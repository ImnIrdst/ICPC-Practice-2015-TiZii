#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <map>
#define INF (int)1e9
#define MAX 100

using namespace std;

int adj[MAX+10][MAX+10],path[MAX+10][MAX+10]; int n; string name[MAX+10]; map<string,int> mp;

int r(double a){
	a*=100;
	return (int)a;
}

void print(int i,int j){
	if(i!=j){
		printf(" %s", name[i].c_str() );
		print(path[i][j],j);
	}
}

int main(){
	int tc; cin >> tc;
	while(tc--){
		cin >> n;
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<n ; j++){
				path[i][j]=j;
			}
		}
		string str;
		for(int i=0 ; i<n ; i++){cin >> str; mp[str]=i; name[i]=str;}
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<n ; j++){
				cin >> adj[i][j]; if(adj[i][j]==-1) adj[i][j]=INF;
			}
		}
		for(int k=0 ; k<n ; k++){
			for(int i=0 ; i<n ; i++){
				for(int j=0 ; j<n ; j++){
					if(adj[i][j]>adj[i][k]+adj[k][j]){
						adj[i][j]=adj[i][k]+adj[k][j];
						path[i][j]=path[i][k];
					}
				}
			}
		}
		int m; cin >> m; string p,s,d;
		while(m--){
			cin >> p >> s >> d;
			if(adj[mp[s]][mp[d]]==INF){
				printf("Sorry Mr %s you can not go from %s to %s\n", p.c_str(), s.c_str(), d.c_str() );
			}
			else {
				printf("Mr %s to go from %s to %s, you will receive %d euros\n", p.c_str(), s.c_str(), d.c_str(),adj[mp[s]][mp[d]]);
				printf("Path:%s",s.c_str()); print(path[mp[s]][mp[d]],mp[d]); printf(" %s\n",d.c_str());
			}
		}
	}
	return 0;
}