#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <set>
#define INF (int) 1e6
#define MAX 100
#define pii pair<int,int>
using namespace std;

int n, dfsLow[MAX+10], dfsNum[MAX+10],parent[MAX+10] , lev, dfsRoot,rootChilds;
vector<int> adj[MAX+10]; set<pii> ansSet;

void artPoint(int u){
	 dfsLow[u]=dfsNum[u]=lev++;
	 for(int i=0 ; i<adj[u].size() ; i++){
		 int v=adj[u][i];
		 if(dfsNum[v]==0){
			 parent[v]=u;
			 if(u==dfsRoot) rootChilds++;
			 artPoint(v);
			 if(dfsLow[v]>dfsNum[u])//u,i bridge 
				ansSet.insert(pii(min(u,v),max(u,v)));
			 dfsLow[u]=min(dfsLow[u],dfsLow[v]);
		 }
		 else if(parent[u]!=v)
			 dfsLow[u]=min(dfsLow[u],dfsNum[v]);
	 }
}

int main(){
	while(cin >> n){
		for(int i=0 ; i<MAX+10; i++) dfsLow[i]=parent[i]=INF, dfsNum[i]=0, adj[i].clear();
		ansSet.clear(); lev=1; int tmp,u,m;
		for(int i=0 ; i<n ; i++){
			scanf("%d (%d", &u, &m); cin.ignore();
			for(int i=0 ; i<m ; i++){
				cin >> tmp; adj[u].push_back(tmp);
			}
		}
		for(int i=0 ; i<n ; i++){
			if(dfsNum[i]==0){
				dfsRoot=i; rootChilds=0; 
				artPoint(i);
			}
		}
		printf("%d critical links\n", ansSet.size());
		set<pii>::iterator itr;
		for(itr=ansSet.begin() ; itr!=ansSet.end() ; itr++) printf("%d - %d\n", itr->first, itr->second);
		cout << endl;
	}
	return 0;
}