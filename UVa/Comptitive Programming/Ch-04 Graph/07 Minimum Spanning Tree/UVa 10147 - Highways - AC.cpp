#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#define INF (int)1e9
#define MAX 1000
#define pii pair<int,int>
#define pdii pair<double, pii >
#define W first
#define U second.first
#define V second.second

using namespace std;

int m,n;
vector< pdii > E;// e==edges array
vector<int> par,rnk,cnt, marked; int numOfsets;

void SetInit(int n){
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

struct pt{ int x, y; pt(int x=0, int y=0): x(x), y(y) {} };

double dist(pt a, pt b){ return hypot(a.x-b.x,a.y-b.y); }

int main(){
	int tc; cin >> tc;
	while(tc--){cin >> n;
		E.clear(); int u,v,w,x,y; vector<pt> vpt;
		for(int i=0 ; i<n ; i++){
			cin >> x >> y; vpt.push_back(pt(x,y));
		}
		for(int i=0 ; i<n ; i++){
			for(int j=i+1 ; j<n ; j++){
				E.push_back(pdii(dist(vpt[i],vpt[j]),pii(i,j)));
			}
		}
		sort(E.begin(), E.end()); SetInit(n); 

		int m; cin >> m;
		for(int i=0 ; i<m ; i++){
			cin >> u >> v; Uni(u-1,v-1);
		}
		
		int ans=0; marked.clear();
		for(int i=0; i<E.size() ; i++){
			if(Find(E[i].U)!=Find(E[i].V)){
				Uni(E[i].U,E[i].V); ans+=E[i].W; marked.push_back(i);
			}
		}
		for(int i=0 ; i<marked.size() ; i++){
			cout << E[marked[i]].U+1 << " " << E[marked[i]].V+1 << endl;
		}
		if(marked.size() == 0) cout << "No new highways need" << endl;
		if(tc) cout << endl;
	}
	return 0;
}
