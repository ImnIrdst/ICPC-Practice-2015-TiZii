#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <stack>
#include <map>
#include <queue>
#define INF (int)1e9
#define MAX 100

using namespace std;

vector<int> adj[MAX+10]; int n,m,stn; string a[MAX+10];

int main(){
	int t=1; string s1,s2;
	while(cin >> n){
		map<string,int> mp;
		for(int i=0 ; i<MAX+10 ; i++) adj[i].clear(); stn=0; 
		for(int i=0 ; i<n ; i++){
			cin >> a[i]; mp[a[i]]=i; adj[i].push_back(0);
		}
		cin >> m; for(int i=0 ; i<m ; i++){
			cin >> s1 >> s2; adj[mp[s1]].push_back(mp[s2]); adj[mp[s2]][0]++;
		}
		cout << "Case #" << t++ << ": Dilbert should drink beverages in this order:";
		
		for(int cnt=0 ; cnt<n ; cnt++){
			int u=0;
			while(adj[u][0]!=0) u++;//first node with in degree 0
			cout << " " << a[u]; adj[u][0]=-1;
			for(int i=1 ; i<adj[u].size() ; i++){
				int v=adj[u][i];
				adj[v][0]--;// remove all edges connected to u			
			}
		}
	
		cout << "." << endl << endl;
	}
	return 0;
}