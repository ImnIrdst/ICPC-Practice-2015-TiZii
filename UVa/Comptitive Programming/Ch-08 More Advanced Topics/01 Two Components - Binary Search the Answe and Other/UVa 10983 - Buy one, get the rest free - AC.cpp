#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <queue>
#include <sstream>
#define INF ((int)1e9)
#define MAX (400+10)
#define node(city,day) ((city)*d+(day))

using namespace std;

int n, m, d;

int res[MAX][MAX],RES[MAX][MAX],cap[MAX][MAX],CAP[MAX][MAX],cost[MAX][MAX],mf,f,s=0,t=1,par[MAX];
vector<int> dist,adj[MAX];

void agument(int v, int minEdge){
    if(v==s) f=minEdge;
    else if(par[v]!=-1){
        agument(par[v],min(minEdge,res[par[v]][v]));
        res[par[v]][v]-=f; res[v][par[v]]+=f;
        //cout << v << " ";
    }
}

void bfs(int s, int maxcost){
    memset(par,-1,sizeof par); dist.assign(MAX,INF);
    dist[s]=0; queue<int> q; q.push(s);
    while(!q.empty()){
        int u=q.front(); q.pop();
        //cout << "bfs: " << u << endl;
        if(u==t) break;
        for(int i=0 ; i<adj[u].size(); i++){
            int v=adj[u][i]; //cout << "->" << v << " cost: " << cost[u][v];// << endl;
            if(res[u][v]>0 && dist[v]==INF && cost[u][v]<=maxcost){
                //cout << " Added";
                dist[v]=dist[u]+1; q.push(v); par[v]=u;
            }
            //cout << endl;
        }
    }
}

int main(){
    int cs=1, tc; cin >> tc;
    while(tc--){ cin >> n >> d >> m; d++;
        //initilize
        memset(cost,0,sizeof cost);
        memset(RES,0,sizeof RES);
        memset(CAP,0,sizeof CAP);
        for(int i=0 ; i<n ; i++) adj[i].clear();
        s = node(n,d); t = node(n-1,d-1);
        //cout << s << " " << t << endl;
        //parse input and constracting the graph
        //(u,e) =c=> (v,e+1)
        int u,v,c,p,e;
        while(m--){
            cin >> u >> v >> c >> p >> e; u--; v--;
            RES[node(u,e)][node(v,e+1)]+=c; //RES[v][u]+=c;
            CAP[node(u,e)][node(v,e+1)]+=c; //CAP[v][u]+=c;
           cost[node(u,e)][node(v,e+1)] =p;
            adj[node(u,e)].push_back(node(v,e+1)); //adj[v].push_back(u);
        }
        //source =Zi=> (0,i)
        int zi,zs=0;
        for(int i=0 ; i<n ; i++){
            cin >> zi; zs+=zi;
            RES[s][node(i,0)]+=zi; //RES[v][u]+=c;
            CAP[s][node(i,0)]+=zi; //CAP[v][u]+=c;
           cost[s][node(i,0)] =0;
            adj[s].push_back(node(i,0)); //adj[v].push_back(u);
        }
        //(u,d) =inf=> (u,d+1)
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<d-1 ; j++){
                RES[node(i,j)][node(i,j+1)]+=INF; //RES[v][u]+=c;
                CAP[node(i,j)][node(i,j+1)]+=INF; //CAP[v][u]+=c;
               cost[node(i,j)][node(i,j+1)] =0;
                adj[node(i,j)].push_back(node(i,j+1)); //adj[v].push_back(u);
            }
        }
        //binary search + max flow
        int lo=0, hi=100001, mid;bool hasAns=0;
        while(lo<hi){
            mid = (lo+hi)/2;
            //cout << "mid: " << mid << " ";
            memcpy(res,RES,sizeof RES);
            memcpy(res,CAP,sizeof CAP); mf=0;
            while(1){
                f=0; bfs(s,mid);
                agument(t,INF); //cout << endl;
                if(f==0) break;
                mf+=f;
            }
            //cout << "mf: " << mf << endl;
            if(mf==zs) hi=mid, hasAns=1; else lo=mid+1;
        }
        if(!hasAns) printf("Case #%d: Impossible\n", cs++);
        else printf("Case #%d: %d\n", cs++, hi );
    }
    return 0;
}
