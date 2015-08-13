#include <algorithm>
#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <cstdio>
#include <string>
#include <cmath>

#define INF (int)1e9
#define MAX (200+10)

using namespace std;

struct point{int x, y, p, j; point(){}
	point(int x, int y, int p, int j):
		x(x), y(y), p(p), j(j){}
};

double Dist(point a, point b){
	return hypot(a.x-b.x, a.y-b.y);
}

int res[MAX][MAX],tmpres[MAX][MAX],mf,f,s,t,n,par[MAX]; vector<int> dist,adj[MAX];

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
	int tc;
	double d;
	cin >> tc;
	while(tc--){
		cin >> n >> d;
		mf=0; memset(res,0,sizeof res); 
		for(int i=0 ; i<n ; i++) adj[i].clear();
		s=0, t=1; int allpeng=0;
		
		vector<point> vp(n);
		for(int i=0 ; i<n ; i++){
			cin >> vp[i].x >> vp[i].y >> vp[i].p >> vp[i].j; allpeng+=vp[i].p;
		}
		for(int i=1 ; i<=n ; i++){
			point& pt = vp[i-1];
			AddEdge(i, i+n, pt.j);
			if(pt.p) AddEdge(s,i,pt.p); 
			for(int j=1 ; j<=n ; j++) if(i!=j) {
				if(Dist(vp[i-1], vp[j-1]) < d + 1e-9){
					AddEdge(i+n, j, INF);
				}
			}
		}

		string ws="";
		for(int tt = 1 ; tt<=n ; tt++){
			memcpy(tmpres, res, sizeof res);
			t = tt; mf=0;
			int u,v,c;
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
			if(mf==allpeng) 
				cout << ws << tt-1, ws=" ";
			memcpy(res, tmpres, sizeof res);
		}
		if(ws=="") cout << -1; cout << endl;
		
	}
	return 0;}
