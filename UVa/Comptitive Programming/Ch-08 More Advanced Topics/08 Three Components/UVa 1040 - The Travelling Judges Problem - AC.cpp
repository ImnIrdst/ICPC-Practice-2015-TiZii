#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef vector<int> vi;
typedef vector<vi > vvi;

struct DisJointSet{
	vector<int> par,rnk,cnt; int numOfsets;

	DisJointSet(int n){
		par.assign(n,-1); rnk.assign(n,0); cnt.assign(n,1); //par==parent
		numOfsets=n; // if wanna count number of disjoint sets
	}

	int Find(int a){
		int i=a,j=a,tmp;
		while(par[i]!=-1){ i=par[i]; }
		while(par[j]!=-1){ tmp=par[j]; par[j]=i; j=tmp; } //path compression
		return i;
	}
	int Uni(int a, int b){
		int A=Find(a),B=Find(b);
		if(A!=B){
			if(rnk[A]<rnk[B]) swap(A,B); // union using rank
			if(rnk[A]==rnk[B]) rnk[A]++;
			par[B]=A;
			cnt[A]+=cnt[B]; // if we wanna count each set size
			numOfsets--; // if wanna count number of disjoint sets
		}
		return cnt[A]; // if we wanna count each set size
	}
};

struct edge{ int u, v, w;
	edge(int u=0, int v=0, int w=0):u(u), v(v), w(w){};
	bool operator<(const edge& b) const {
		if(w == b.w && v == b.w) return u < b.u;
		if(w == b.w ) return v < b.v; 
		return w < b.w;
	}
};

int n, m, dc, nj, bit; vector<edge> e; vvi adj, pth; vi jodges, vis, marked;

int Kruskal(){
	DisJointSet djst(n); marked.clear();
	int ans=0; int j=0;
	for(int i=0; i<e.size() ; i++){
		if(!(bit&(1<<e[i].u)) || !(bit&(1<<e[i].v))) continue;
		if(djst.Find(e[i].u)!=djst.Find(e[i].v)){
			djst.Uni(e[i].u,e[i].v); ans+=e[i].w; j++; marked.push_back(i);
		}
	}
	return ans;
}

int cntOnes(int bitmask){
	int cnt=0;
	while(bitmask) 
		bitmask-=bitmask&(-bitmask), cnt++; 
	return cnt;
}

int coversGoals(int bitmask){
	if(!(bitmask&(1<<dc))) return false;
	for(int i=0 ; i<jodges.size() ; i++){
		if(!(bitmask&(1<<jodges[i]))) return false;
	}
	return true;
}

void dfs(int u){
	if(vis[u]) return; vis[u]=1;
	for(int i=0 ; i<adj[u].size() ; i++)
		dfs(adj[u][i]);
}

bool connected(){
	vis.assign(n,0);
	for(int i=0 ; i<n ; i++){
		if(bit&(1<<i)){
			dfs(i); break;
		}
	}
	for(int i=0 ; i<n ; i++){
		if((bit&(1<<i)) && !vis[i]) return false;
	}
	return true;
}

void buildGraph(){
	adj.assign(n, vi());
	for(int i=0 ; i<e.size() ; i++){
		if((bit&(1<<e[i].u)) && (bit&(1<<e[i].v)))
			adj[e[i].u].push_back(e[i].v), adj[e[i].v].push_back(e[i].u);
	}
}

void print(int i,int j){
	if(i!=j){
		printf("-%d",i+1 );
		print(pth[i][j],j);
	}
}


int main(){
	int cs=1;
	while(cin >> n && n!=-1){
		cin >> dc >> m; dc--; e.resize(m);
		for(int i=0 ; i<m ; i++){ 
			cin >> e[i].u >> e[i].v >> e[i].w;
			e[i].u--; e[i].v--;
		}
		sort(e.begin(), e.end());
		cin >> nj; jodges.resize(nj);
		for(int i=0 ; i<nj ; i++){
			cin >> jodges[i]; jodges[i]--;
		}
		
		vector<edge> ans; int minOnes=1e9, minCost=1e9;
		for(bit=0 ; bit<(1<<n) ; bit++){
			if(!coversGoals(bit)) continue;

			buildGraph();
			if(!connected()) continue;

			int ones = cntOnes(bit); int cost = Kruskal();
			if( cost > minCost || (cost == minCost && ones > minOnes) ) continue;

			minCost = cost; 
			minOnes = ones; ans.clear();
			for(int i=0 ; i<marked.size() ; i++){
				ans.push_back(e[marked[i]]);
			}
		}

		pth.assign(n, vi(n));
		adj.assign(n, vi(n));
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<n ; j++) 
				pth[i][j]=j, adj[i][j]=1e9;
			adj[i][i]=0;
		}
		for(int i=0 ; i<ans.size() ; i++){
			adj[ans[i].u][ans[i].v]=ans[i].w;
			adj[ans[i].v][ans[i].u]=ans[i].w;
		}

		for(int k=0 ; k<n ; k++)
			for(int i=0 ; i<n ; i++)
				for(int j=0 ; j<n ; j++)
					if(adj[i][j] > adj[i][k]+adj[k][j])
						adj[i][j] = adj[i][k]+adj[k][j], 
						pth[i][j] = pth[i][k];

		//if( cs != 1)
		printf("Case %d: distance = %d\n", cs++, minCost);
		for(int i=0 ; i<jodges.size() ; i++){
			int s = jodges[i]; 
			printf("   %d",s+1); print(pth[s][dc], dc); printf("-%d\n", dc+1);
		}
		printf("\n");
	}
}