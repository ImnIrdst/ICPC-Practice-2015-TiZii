#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <cstdio>

#define INF (int)1e9
#define MAXF (1800+10)
#define MAXM (30+10)

using namespace std;


char Map[MAXM][MAXM]; int node[MAXM][MAXM]; 
int res[MAXF][MAXF],mf,f,s,t,n,m,p,par[MAXF]; vector<int> dist,adj[MAXF];
int di[4] = { 0, 0,+1,-1};
int dj[4] = {+1,-1, 0, 0};

int inRange(int i, int j){
	return (i>=0 && i<n && j>=0 && j<m && Map[i][j]!='~');
}

void agument(int v, int minEdge){
	if(v==s) f=minEdge;
	else if(par[v]!=-1){
		agument(par[v],min(minEdge,res[par[v]][v]));
		res[par[v]][v]-=f; res[v][par[v]]+=f;
	}
}

void AddEdge(int u, int v, int c){
	res[u][v] = c;
	adj[u].push_back(v);
	adj[v].push_back(u);
}

int main(){
	while(cin >> n >> m >> p){
		mf=0; memset(res,0,sizeof res); 
		for(int i=0 ; i<n ; i++) adj[i].clear();
		s=0, t=1;
		
		int nd=2;
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<m ; j++){
				cin >> Map[i][j];
				if(Map[i][j]!='~') node[i][j]=nd, nd+=2;
			}
		}
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<m ; j++){
				if(Map[i][j]!='~'){
					int Vin = node[i][j];
					int Vout = node[i][j]+1;
					if(Map[i][j]=='.')      AddEdge(Vin, Vout, 1);
					else if(Map[i][j]=='*') AddEdge(Vin, Vout, 1);
					else			        AddEdge(Vin, Vout, INF);
					for(int dir=0 ; dir<4 ; dir++){
						int ii = i+di[dir];
						int jj = j+dj[dir];
						if(inRange(ii, jj)) AddEdge(Vout, node[ii][jj],INF);
					}
					if(Map[i][j]=='*') AddEdge(s, Vin, 1);
					if(Map[i][j]=='#') AddEdge(Vout,t, p);
				}
			}
		}
		int u,v,c;
		while(1){
			f=0; memset(par,-1,sizeof par); dist.assign(MAXF,INF);
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
		cout << mf << endl;
	}
	return 0;}
