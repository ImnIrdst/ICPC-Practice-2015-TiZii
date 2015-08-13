#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <queue>
#define INF ((int)1e9)
#define MAX (60*60*2)

using namespace std;

int res[MAX][MAX],mf,f,s=0,t=1,m,R,C,par[MAX]; vector<int> dist,adj[MAX];
//0 source , 1 sink
int dx[]={ 0, 0,-1,+1};
int dy[]={-1,+1, 0, 0};

bool inRange(int i, int j){return (i>=1 && j>=1 && i<=R && j<=C);}
bool isExit(int i, int j){return (i==1 || j==1 || i==R || j==C);}

void agument(int v, int minEdge){
	if(v==s) f=minEdge;
	else if(par[v]!=-1){
		agument(par[v],min(minEdge,res[par[v]][v]));
		res[par[v]][v]-=f; res[v][par[v]]+=f;
	}
}

int main(){
	int tc; cin >> tc;
	while(tc--){
		memset(res,0,sizeof res); for(int i=0 ; i<MAX ; i++) adj[i].clear();
		mf=0; cin >> R >> C >> m;
		for(int i=1 ; i<=R ; i++){
			for(int j=1 ; j<=C ; j++){
				for(int k=0 ; k<4 ; k++){
					int x=i+dx[k], y=j+dy[k];
					int u=(i*R+j)*2, v=(x*R+y)*2;
					if(k==0) res[u][u+1]=1, adj[u].push_back(u+1);
					res[u+1][v]=1, adj[u+1].push_back(v);
					if(isExit(i,j)) res[u+1][t]=1 , adj[u+1].push_back(t);
					
				}
			}
		}
		int x,y;
		for(int i=0 ; i<m ; i++){
			cin >> x >> y; int v=(x*R+y)*2;
			res[s][v]=1; adj[s].push_back(v);
		}
		while(1){
			f=0; memset(par,-1,sizeof par); dist.assign(MAX,INF);
			dist[s]=0; queue<int> q; q.push(s);
			while(!q.empty()){
				int u=q.front(); q.pop();
				if(u==t) break;
				for(int i=0 ; i<adj[u].size(); i++){
					int v=adj[u][i];
					if(res[u][v]>0 && dist[v]==INF){
						dist[v]=dist[u]+1; q.push(v); par[v]=u;
					}
				}
			}
			agument(t,INF);
			if(f==0) break;
			mf+=f;
		}
		//printf("(flow %d) ", mf );
		cout << (mf==m ? "possible" : "not possible") << endl;
	}
	return 0;
}