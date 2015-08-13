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
#define MAX 40

using namespace std;

int res[MAX][MAX],mf,f,s=0,t=37,cnt,n=38,par[MAX]; vector<int> dist,adj[MAX];
//0==source, 1->26==applications, 27->36==computers, 37==sink
void agument(int v, int minEdge){
	if(v==s) f=minEdge;
	else if(par[v]!=-1){
		agument(par[v],min(minEdge,res[par[v]][v]));
		res[par[v]][v]-=f; res[v][par[v]]+=f;
	}
}

int main(){
	string str; char c1,c2; stringstream sstr;
	while(getline(cin,str) && str.size()!=0){
		mf=cnt=0; memset(res,0,sizeof res); for(int i=0 ; i<n ; i++) adj[i].clear();
		for(int i=27 ; i<=36 ; i++){ res[i][t]=1; adj[i].push_back(t);}
		do{
			sstr.clear(); sstr << str; 
			sstr >> c1 >> c2; cnt+=(c2-'0'); sstr.ignore();
			res[0][c1-'A'+1]=(c2-'0'); adj[0].push_back(c1-'A'+1);
			while(sstr >> c2 && c2!=';'){
				res[c1-'A'+1][c2-'0'+27]=1;
				adj[c1-'A'+1].push_back(c2-'0'+27);
				adj[c2-'0'+27].push_back(c1-'A'+1);
			}
		}while(getline(cin,str) && str.size()!=0);
		if(cnt>10) cout << "!" << endl;
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
		if(mf!=cnt) cout << "!" << endl;
		else {
			for(int i=27 ; i<=36 ; i++){
				bool assigned=false;
				for(int j=1 ; j<=26 ; j++){
					if(res[i][j]>0){
						cout << (char)(j-1+'A'); assigned=true; break;
					}
				}
				if(!assigned) cout <<"_";
			}
			cout << endl;
		}
	}
	return 0;
}