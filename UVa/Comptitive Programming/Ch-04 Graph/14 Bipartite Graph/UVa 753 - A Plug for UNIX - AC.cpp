#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
#include <map>


using namespace std;

typedef vector< int > vi;
typedef vector< vi  > vii;

const int MAX = 1000+10;
const int INF = 1e9;

int res[MAX][MAX],mf,f,s,t,n,m,par[MAX]; vii adj; vi dist; map<string, int> MP;

int mp(string& str){if(MP.count(str)) return MP[str]; return MP[str]=n++; }

void agument(int v, int minEdge){
	if(v==s) f=minEdge;
	else if(par[v]!=-1){
		agument(par[v],min(minEdge,res[par[v]][v]));
		res[par[v]][v]-=f; res[v][par[v]]+=f;
	}
}

int main(){
	int tc, cs=1; cin >> tc;
	while( tc-- ){
		memset(res,0,sizeof res); MP.clear(); 
		mf=0; string s1, s2; adj.assign(MAX,vi());
		
		cin >> m; n=1; s=0; t=MAX-1;
		for(int i=0 ; i<m ; i++){
			cin >> s1; 
			res[mp(s1)][t]=1;
			adj[mp(s1)].push_back(t);
		}
		
		cin >> m; int devs = m;
		for(int i=0 ; i<m ; i++){
			cin >> s1 >> s2; mp(s1);

			res[mp(s1)][mp(s2)]=1;
			adj[mp(s1)].push_back(mp(s2));
			adj[mp(s2)].push_back(mp(s1));
			
			res[s][mp(s1)]=1;
			adj[s].push_back(mp(s1));
		}

		cin >> m;
		for(int i=0 ; i<m ; i++){
			cin >> s1 >> s2;
			res[mp(s1)][mp(s2)]=INF;
			adj[mp(s1)].push_back(mp(s2));
			adj[mp(s2)].push_back(mp(s1));
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
		cout << devs-mf << endl;
		if(tc) cout << endl;
	}
	return 0;}
