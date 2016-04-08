#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <queue>
#include <sstream>
#define INF (int)1e9
#define MAX 100
#define pii pair<int,int>
#define cost first
#define node second

using namespace std;

vector<pii> adj[MAX+10]; int dist[MAX+10], T[5], n, k;

int dijkstra(int s,int k){
	priority_queue< pii , vector<pii> , ::greater<pii> > pq;
	dist[s]=0; pq.push(pii(dist[s],s));
	while(!pq.empty()){
		pii u=pq.top(); pq.pop();
		if(u.cost == dist[u.node]){
			if(k==u.node) return dist[k];
			for(int i=0 ; i<adj[u.node].size() ; i++){
				pii v=adj[u.node][i];
				if(dist[v.node]>dist[u.node]+v.cost+60){
					dist[v.node]=dist[u.node]+v.cost+60;
					pq.push(pii(dist[v.node],v.node));
				}
			}
		}
	}
	return dist[k];
}

int main(){
	string str; stringstream sin;
	while(cin >> n >> k){
		for(int i=0 ; i<MAX+10 ; i++) adj[i].clear(), dist[i]=INF;
		for(int i=0 ; i<n ; i++) cin >> T[i]; cin.ignore();
		for(int e=0 ; e<n ; e++){
			getline(cin , str);
			sin.clear(); sin << str;
			int tmp[MAX+10]; int size=0;
			while(sin >> tmp[size]) size++;
			for(int i=0 ; i<size ; i++){
				for(int j=i+1 ; j<size; j++){
					adj[tmp[i]].push_back(pii(abs(tmp[j]-tmp[i])*T[e],tmp[j]));
					adj[tmp[j]].push_back(pii(abs(tmp[j]-tmp[i])*T[e],tmp[i]));
				}
			}
		}
		int ans=dijkstra(0,k);
		if(ans!=INF) cout << (k!=0 ? ans-60 : ans) << endl;
		else cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}