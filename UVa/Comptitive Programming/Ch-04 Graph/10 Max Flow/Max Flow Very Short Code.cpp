#include <stdio.h>
 
#define REP(i,n) for (int i=0,_n=n; i<_n; i++)
#define INF 1000000000
#define MAXN 100
 
int res[MAXN][MAXN], vis[MAXN], n;
 
int augpath(int so, int si, int mf){
  vis[so] = true;
  if (so==si) return mf;
  REP(i,n) if (!vis[i] && res[so][i]>0){
    int flow = augpath(i,si,mf <? res[so][i]);
    if (flow>0){
      res[so][i] -= flow;
      res[i][so] += flow;
      return flow;
    }
  }
  return 0;
}
 
int maxflow(int so, int si){
  int ret = 0;
  while (true){
    REP(i,n) vis[i] = 0;
    int flow = augpath(so,si,INF);
    if (flow == 0) return ret;
    ret += flow;
  }
}
 
int main(){
  for (int N,E,a,b,c; scanf("%d %d",&N,&E)!=EOF && (N||E); ){
    n = 2*N;  // split each vertex into 2 vertices
    REP(i,n) REP(j,n) res[i][j] = 0;  // initialize residue
    res[0][N] = res[N-1][N+N-1] = INF;  // server and boss
    REP(i,N-2){
      scanf("%d %d",&a,&c); a--;
      res[a][N+a] = c;
    }
    REP(i,E){
      scanf("%d %d %d",&a,&b,&c); a--; b--;
      res[N+a][b] = res[N+b][a] = c;
    }
    printf("%d\n",maxflow(0,N+N-1));
  }
}