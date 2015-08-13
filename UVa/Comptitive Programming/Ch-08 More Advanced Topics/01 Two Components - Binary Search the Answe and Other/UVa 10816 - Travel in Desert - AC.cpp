#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <functional>
#define vi   vector<int>
#define node pair<double,int>
#define cost first
#define idx  second
#define eps  1e-9
#define inf  1e99

using namespace std;

int n, m, s, t;

struct edge{
	int idx; double cost, temp;
	edge(int i=0, double c=0, double t=0){idx=i; cost=c; temp=t;}
};

#define ve   vector<edge>
#define vvi  vector< ve >
vvi adj; vi par; vector<double> Cost;


int dcmp(double x){
	return ( fabs(x)<eps ? 0 : (x>0 ? 1 : -1));
}

double dijkstra(int s, int t, double maxtemp){
	priority_queue< node ,vector< node >, ::greater< node > > pq;
	pq.push(node(0,s)); Cost = vector<double>(n,inf); par.assign(n,-1);
	while(!pq.empty()){
		node u = pq.top(); pq.pop();
		if(u.idx == t) return u.cost;
		if(u.cost > Cost[u.idx]) continue;
		for(int i=0 ; i<adj[u.idx].size() ; i++){
			edge v = adj[u.idx][i];
			if(u.cost+v.cost<Cost[v.idx] && v.temp<=maxtemp){
				Cost[v.idx]=u.cost+v.cost; par[v.idx]=u.idx;
				pq.push(node(Cost[v.idx],v.idx));
			}
		}
	}
	return inf;
}

vi path;

void print_path(int i){
    if(i==s){ cout << i+1; return; }
    print_path(path[i]);
    cout << " " << i+1;
}

int main(){
	int u, v; double d, r;
	while(cin >> n >> m){
		cin >> s >> t; s--, t--;
		adj.assign(n, ve());
		double maxtemp=0;
		for(int i=0 ; i<m ; i++){
			cin >> u >> v >> r >> d; u--, v--;
			adj[u].push_back(edge(v,d,r));
			adj[v].push_back(edge(u,d,r));
			maxtemp=max(maxtemp,r);
		}
		double Cost, ans;
		double lo = 0, hi = maxtemp+1;
		while(fabs(lo-hi)>1e-5){
			double mid = (lo+hi)/2;
			Cost = dijkstra(s,t,mid);
			if(!dcmp(Cost-inf)) lo = mid+1e-5; else hi = mid, ans=Cost, path=par;
		}
		print_path(t); cout << endl;
		printf("%.1lf %.1lf\n", ans, lo );
	}
}
