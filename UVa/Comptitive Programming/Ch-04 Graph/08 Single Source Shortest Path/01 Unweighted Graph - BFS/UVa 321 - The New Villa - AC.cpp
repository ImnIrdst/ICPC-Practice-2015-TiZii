#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <queue>
#define INF (int)1e9
#define MAX 11
#define pii pair<int,int>
#define NODE first
#define BITSET second

using namespace std;

int adj[MAX][MAX],sw[MAX][MAX],dist[MAX][1<<MAX],r,d,s,t=1; pii parent[MAX][1<<MAX];

int bfs(){
	queue<pii> q; dist[1][1<<1]=0; q.push(pii(1,(1<<1)));
	while(!q.empty()){
		pii u=q.front(); q.pop();
		if(u.NODE==r && u.BITSET == (1<<r)) return dist[u.NODE][u.BITSET];
		for(int v=1 ; v<=r ; v++){
			if(adj[u.NODE][v] && dist[v][u.BITSET]==INF && (u.BITSET&(1<<v)) == (1<<v) ){
				dist[v][u.BITSET]=dist[u.NODE][u.BITSET]+1;
				parent[v][u.BITSET]=u;
				q.push(pii(v,u.BITSET));
			}
		}

		for(int v=1 ; v<=r ; v++){
			if(sw[u.NODE][v] && u.NODE!=v && dist[u.NODE][u.BITSET^(1<<v)]==INF){
				dist[u.NODE][u.BITSET^(1<<v)]=dist[u.NODE][u.BITSET]+1;
				parent[u.NODE][u.BITSET^(1<<v)]=u;
				q.push(pii(u.NODE,u.BITSET^(1<<v)));
			}
		}
	}
	return -1;
}

int dif(int bitset1, int bitset2){
	for(int v=1 ; v<=r ; v++){
		if((bitset1&(1<<v)) != (bitset2&(1<<v))) return v;
	}
	return -1;
}


void print(){
	pii u(r,(1<<r)); pii v=parent[u.NODE][u.BITSET]; vector<string> ans; vector<int> ansnum;
	while(u.NODE!=1 || u.BITSET!=(1<<1)){
		if(u.BITSET==v.BITSET) ans.push_back("- Move to room "), ansnum.push_back(u.NODE);
		if(u.NODE==v.NODE && u.BITSET>v.BITSET) ans.push_back("- Switch on light in room "), ansnum.push_back(dif(u.BITSET,v.BITSET));
		if(u.NODE==v.NODE && u.BITSET<v.BITSET) ans.push_back("- Switch off light in room "), ansnum.push_back(dif(u.BITSET,v.BITSET));
		u=v; v=parent[u.NODE][u.BITSET];
	}
	if(u.BITSET==v.BITSET) ans.push_back("- Move to room "), ansnum.push_back(u.NODE);
	if(u.NODE==v.NODE) ans.push_back("- Switch on light in room "), ansnum.push_back(dif(u.BITSET,v.BITSET));
	
	cout << "The problem can be solved in " << ans.size() << " steps:" << endl;
	for(int i=ans.size()-1 ; i>=0 ; i--){
		cout << ans[i] << ansnum[i] << "." << endl;
	}
}



int main(){
	int x,y;
	while(cin >> r >> d >> s && (r||d||s)){
		memset(adj,0,sizeof adj); memset(sw,0,sizeof sw);
		for(int i=0 ; i<d ; i++){ cin >> x >> y; adj[x][y]=adj[y][x]=1; }
		for(int i=0 ; i<s ; i++){ cin >> x >> y; sw[x][y]=1; }
		for(int i=1 ; i<=r ; i++) for(int j=0 ; j<(1<<(r+1)) ; j++) dist[i][j]=INF;
		int ans=bfs(); cout << "Villa #" << t++ << endl;
		if(ans==-1) cout << "The problem cannot be solved." << endl; 
		else print(); 
		cout << endl;
	}
	return 0;
}