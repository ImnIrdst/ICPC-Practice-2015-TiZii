#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector<int> vi;
typedef vector<vi > vvi;

const int Max = 200+10;
const int Inf = 1e9;

int main(){
	int n, m, cs=1;
	while(cin >> n >> m && (n||m)){
		map<string, int> mp;
		vvi adj(n,vi(n,0));
		string s1, s2; int c=0, w;
		for(int i=0 ; i<n ; i++) adj[i][i]=0;
		for(int i=0 ; i<m ; i++){
			cin >> s1 >> s2 >> w;
			if(!mp.count(s1)) mp[s1]=c++;
			if(!mp.count(s2)) mp[s2]=c++;
			adj[mp[s1]][mp[s2]]=w;
			adj[mp[s2]][mp[s1]]=w;
		}
		for(int k=0 ; k<n ; k++){
			for(int i=0 ; i<n ; i++){
				for(int j=0 ; j<n ; j++){
					adj[i][j]=max(adj[i][j],min(adj[i][k],adj[k][j]));
				}
			}#
		}

		cin >> s1 >> s2;
		cout << "Scenario #" << cs++ << endl;
		cout << adj[mp[s1]][mp[s2]] << " tons" << endl;
		cout << endl;
	}
}
