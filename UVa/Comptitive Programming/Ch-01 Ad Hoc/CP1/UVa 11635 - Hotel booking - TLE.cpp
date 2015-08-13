#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <sstream>
#include <vector>
#define INF (int)1e9
#define P pair<int,int>
#define Y first
#define W second

using namespace std;

vector<P> adj[10000+10]; 
int n,m,fs; int h[10000+10], vis[10000+10];//h->isHotel, vis[i]=t -> visited city (i) in time (t) 
int rh;  // rh -> number of reached hotels

int solve(int pos, int time/*, string lev*/){//lev -> level for debug
	if(time>600) return INF;
	if(vis[pos]<=time){ return INF;}
	//stringstream sin; string tmp;
	if(pos==n){ return 0; }
	int dpp=INF; vis[pos]=(h[pos]?0:time);
	for(int i=0 ; i<adj[pos].size() ; i++){
		P next=adj[pos][i]; vis[pos]=(h[pos]?0:time);
		//sin.clear(); sin << "(" << next.Y << ", " << time+next.W <<")"; getline(sin,tmp);
		dpp=min(dpp,solve(next.Y,time+next.W/*,lev+tmp*/)+next.W);
		//sin.clear(); sin << "(" << next.Y << ", " << 0+next.W <<")";  getline(sin,tmp);
		if(h[pos]) dpp=min(dpp,solve(next.Y,0+next.W/*,lev+tmp*/)+next.W);
		
	}
	vis[pos]=INF;
	return dpp;
}

int main(){
	while(cin >> n && n){
		int x,y,z;
		for(int i=0 ; i<10000+10 ; i++) h[i]=vis[i]=0,adj[i].clear(),vis[i]=INF;
		cin >> fs; for(int i=0 ; i<fs ; i++){cin >> x; h[x]=1;}
		cin >> m;
		for(int i=0 ; i<m ; i++){
			cin >> x >> y >> z;
			if(x==y) continue;
			adj[x].push_back(P(y,z));
			adj[y].push_back(P(x,z));
		}
		rh=0; int ans=solve(1,0/*,"1"*/); 
		cout << (ans>=INF ? -1 : ans/600-(ans%600==0)) << endl;
	}
	return 0;
}