#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cassert>
#define VI vector<int>
#define VVI vector< VI >

using namespace std;

double INF = 1e100;
double EPS = 1e-9 ;

int dcmp(double x){ return (fabs(x)<EPS ? 0 : (x>0 ? 1 : -1) ); }

struct PT { 
  double x, y; PT() {}
  PT(double x, double y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y)    {}
  PT operator - (const PT &p)  const { return PT(x-p.x, y-p.y); }
};

struct circle { 
  double r; PT p; 
};

double dot(PT p, PT q)     { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q)   { return dot(p-q,p-q); }

VVI adj; VI vis;

int bfs(int u){
  vis[u]=1; int cnt=0;
  for(int i=0 ; i<adj[u].size() ; i++){
    int v = adj[u][i];
    if(!vis[v]) cnt+=bfs(v);
  }
  return 1 + cnt;
}



int main(){
  int n; circle circ;;
  while(cin >> n && n!=-1){
    vector<circle> vc; adj = VVI(n,VI()); vis=VI(n,0);
    for(int i=0 ; i<n ; i++){
      cin >> circ.p.x >> circ.p.y >> circ.r; vc.push_back(circ);
    }
    for(int i=0 ; i<n ; i++){
      for(int j=0 ; j<n ; j++){
        //cout << sqrt(dist2(vc[i].p,vc[j].p)) << " " << vc[i].r+vc[j].r << endl;
        if(sqrt(dist2(vc[i].p,vc[j].p))<vc[i].r+vc[j].r &&
           sqrt(dist2(vc[i].p,vc[j].p))+min(vc[i].r,vc[j].r)>max(vc[i].r,vc[j].r)){
          adj[i].push_back(j);
        }
      }
    }
    int Max=0;
    for(int i=0 ; i<n ; i++){
      if(!vis[i]) Max=max(Max,bfs(i));
    }
    if(Max==1) printf("The largest component contains 1 ring.\n");
    else printf("The largest component contains %d rings.\n",Max);
  }
}