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
#define INF (int)1e9
#define MAXP (1000+5)
#define MAXC (20+5)
#define Cat(i) (np+1+i)
#define Prob(i) (1+i)

using namespace std;

int res[MAXC+MAXP][MAXC+MAXP],mf,f,s,t,cnt,n,par[MAXP+MAXC]; vector<int> dist,adj[MAXP+MAXC];
//0==source, 1->np==problems, np+1->np+nk==catigories, np+nk+1==sink
void agument(int v, int minEdge){
	if(v==s) f=minEdge;
	else if(par[v]!=-1){
		agument(par[v],min(minEdge,res[par[v]][v]));
		res[par[v]][v]-=f; res[v][par[v]]+=f;
	}
}

int main(){
	int nk, np,tmp,tmp2;
	while(cin >> nk >> np && (nk||np)){
		mf=cnt=0; s=0; t=np+nk+1; n=np+nk+2;
		memset(res,0,sizeof res); for(int i=0 ; i<n ; i++) adj[i].clear();
		for(int i=0 ; i<nk ; i++){
			cin >> tmp; res[Cat(i)][t]=tmp; cnt+=tmp;
			adj[Cat(i)].push_back(t);
		}
		for(int i=0 ; i<np ; i++){
			res[s][Prob(i)]=1; cin >> tmp;
			adj[Prob(i)].push_back(s); adj[s].push_back(Prob(i));
			for(int j=0 ; j<tmp ; j++){
				cin >> tmp2; tmp2--;
				res[Prob(i)][Cat(tmp2)]=1;
				adj[Prob(i)].push_back(Cat(tmp2)); adj[Cat(tmp2)].push_back(Prob(i));
			}
		}
		while(1){
			f=0; memset(par,-1,sizeof par); dist.assign(n,INF);
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
		//printf("%d %d\n",mf,cnt );
		if(mf!=cnt) cout << 0 << endl;
		else {
			cout << 1 << endl;
			for(int i=Cat(0) ; i<Cat(nk) ; i++){
				bool first=true;
				for(int j=Prob(0) ; j<Prob(np) ; j++){
					if(res[i][j]>0){
						if(!first) cout << " "; first=false;
						cout << j;
					}
				}
				cout << endl;
			}
			//cout << endl;
		}
	}
	return 0;
}