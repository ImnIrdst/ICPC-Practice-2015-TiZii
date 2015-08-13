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
#define vi vector<int> 

using namespace std;

struct pii{
	int x,y; pii(){} pii(int X, int Y){x=X,y=Y;}
};

vector< vi > adj; vector<int> owner, vis; int n,m; vector<pii> bob,dog;

int altpath(int u){
	if(vis[u]) return 0; vis[u]=1;
	for(int i=0 ; i<adj[u].size() ; i++){
		int v=adj[u][i];
		if(owner[v]==-1 || altpath(owner[v])){
			owner[v]=u; owner[u]=v; return 1;
		}
	}
	return 0;
}

double dist(pii a, pii b){
	double dx=a.x-b.x, dy=a.y-b.y;
	return sqrt(dx*dx+dy*dy);
}

bool valid(pii b1, pii b2, pii dog){
	double b1tob2=dist(b1,b2);
	double b1todog=dist(b1,dog);
	double b2todog=dist(dog,b2);
	return (b1tob2*2>=(b1todog+b2todog));
}

int main(){
	int x,y,tc,t=1; cin >> tc;
	while(tc--){
		cin >> n >> m; adj.assign(n+m,vi()); bob.clear(); dog.clear();
		for(int i=0 ; i<n ; i++){
			cin >> x >> y; bob.push_back(pii(x,y));
		}
		for(int i=0 ; i<m ; i++){
			cin >> x >> y; dog.push_back(pii(x,y));
		}
		for(int i=0 ; i<n-1 ; i++){
			for(int j=0 ; j<m ; j++){
				if(valid(bob[i],bob[i+1],dog[j])){
					adj[i].push_back(j+n),adj[j+n].push_back(i);
				}
			}
		}
		int MCBM=0; owner.assign(n+m,-1);
		for(int u=0 ; u<n-1 ; u++){
			if(owner[u]==-1){
				vis.assign(n,0); MCBM+=altpath(u);
			}
		}
		printf("%d\n",MCBM+n);
		bool first=true;
		for(int i=0 ; i<n ; i++){
			if(!first) printf(" "); first=false;
			printf("%d %d",bob[i].x, bob[i].y);
			if(owner[i]!=-1){
				int j=owner[i]-n;
				printf(" %d %d",dog[j].x, dog[j].y);
			}
		}
		printf("\n");
		if(tc) printf("\n");
	}
	return 0;
}