#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
#include <vector>
#include <cstdio>

using namespace std;

const int MAX = 100+50;
const int INF = 1e9;

typedef pair<int,int> pii;
typedef long long int64;

int adj[MAX][MAX]={0} , path[MAX][MAX]; 
string route[MAX][MAX], name[MAX];
map<string,int> mp; vector<int> p;

void pathCons(int i, int j){
	if(i != j) pathCons(i,path[i][j]);
	p.push_back(j);
}

int main(){
	for(int i=0 ; i<MAX ; i++){
		for(int j=0 ; j<MAX ; j++){
			adj[i][j]=INF; path[i][j]=i;
		}
	}
	string line; int n=0;
	while(cin.peek() != '\n'){
		string name1=""; getline(cin, name1, ',');
		if(!mp.count(name1)) mp[name1]=n, name[n]=name1, n++;
		
		string name2=""; getline(cin, name2, ',');
		if(!mp.count(name2)) mp[name2]=n, name[n]=name2, n++;

		string routee; getline(cin, routee, ',');
		int dist; cin >> dist; cin.ignore();
		if(dist < adj[mp[name1]][mp[name2]]){
			route[mp[name1]][mp[name2]] = routee;
			route[mp[name2]][mp[name1]] = routee;

			adj[mp[name1]][mp[name2]] = dist;
			adj[mp[name2]][mp[name1]] = dist;
		}
		

		//cout << name1 << "|" << name2 << "|" << routee << "|" << dist << endl;
	}
	for(int k=0 ; k<n ; k++){
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<n ; j++){
				if(adj[i][j] > adj[i][k]+adj[k][j]){
					adj[i][j] = adj[i][k]+adj[k][j];
					path[i][j] = path[k][j];
				}
			}
		}
	}
	string name1, name2; cin.ignore();
	while(getline(cin, name1, ',')){ getline(cin, name2);
		p.clear(); pathCons(mp[name1], mp[name2]);
		cout << endl << endl;
		cout << "From                 To                   Route      Miles" << endl;
		cout << "-------------------- -------------------- ---------- -----" << endl;
		for(int i=1 ; i<p.size() ; i++){
			printf("%-20s %-20s %-10s %5d\n", name[p[i-1]].c_str(), name[p[i]].c_str(),
				route[p[i-1]][p[i]].c_str(), adj[p[i-1]][p[i]]);
		}
		cout << "                                                     -----" << endl;
		printf("                                          Total      %5d\n", adj[mp[name1]][mp[name2]]);
	}

}