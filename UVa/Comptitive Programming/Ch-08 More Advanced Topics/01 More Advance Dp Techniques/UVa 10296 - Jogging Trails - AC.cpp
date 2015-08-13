#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long int64;

const int64 MAX = 15+2 ;
const int64 INF = 1e18 ;

int64 n, no, m, dp[1<<MAX], adj[MAX][MAX], oddAdj[MAX][MAX], isOdd[MAX], Odds[MAX];

void init(){
    memset(dp,-1,sizeof dp);
    for(int i=0 ; i<MAX ; i++){
        for(int j=0 ; j<MAX ; j++){
            adj[i][j] = oddAdj[i][j] = INF;
        }
        adj[i][i] = 0; isOdd[i] = 0;
    }
}

int solve(int bit){
    int64& dpp = dp[bit];
    if(bit == (1<<no)-1) return 0;
    if(dpp != -1) return dpp;
    dpp = INF;
    for(int i=0 ; i<no ; i++){
        for(int j=0 ; j<no ; j++){
            if(bit&(1<<i) || bit&(1<<j) || i==j) continue;
            int bit2 = bit | (1<<i) | (1<<j) ;
            dpp = min(dpp, solve(bit2) + oddAdj[i][j]);
        }
    }
    return dpp;
}

int main(){
    while(cin >> n && n){ cin >> m;
        int64 u,v,w,ans=0; init();//initialize and get input
        for(int i=0 ; i<m ; i++){
            cin >> u >> v >> w; u--, v--;
            adj[u][v]=min(adj[u][v],w);
            adj[v][u]=min(adj[v][u],w);
            isOdd[u]=1-isOdd[u];
            isOdd[v]=1-isOdd[v];
            ans += w;
        }
        //calc floyd warshal for graph
        for(int k=0 ; k<n ; k++){
            for(int i=0 ; i<n ; i++){
                for(int j=0 ; j<n ; j++){
                    adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
                }
            }
        }
        //constract odd edges graph
        no=0; // number of odds
        for(int u=0 ; u<n ; u++){
            if(isOdd[u]) Odds[no++]=u;
        }
        for(int i=0 ; i<no ; i++){
            for(int j=0 ; j<no ; j++){
                oddAdj[i][j] = adj[Odds[i]][Odds[j]];
            }
        }
        //calc min weight perfect matching using bitmas+dp
        int64 MWPM = solve(0);
        //print ans;
        cout << ans + MWPM << endl;
    }
}