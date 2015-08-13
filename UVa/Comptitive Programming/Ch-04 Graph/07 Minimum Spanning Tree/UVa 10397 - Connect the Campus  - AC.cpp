#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#define INF (int)1e9
#define MAX 1000
#define pii pair<int,int>
#define pfii pair<double, pii >
#define W first
#define U second.first
#define V second.second
#define X first
#define Y second

using namespace std;

vector<int> par,rnk,cnt;//par==parent
vector< pfii > E; vector<pii> p;// e==edges array, p==points array
int m,n; 

void SetInit(int n){
	par.assign(n,-1); rnk.assign(n,0); cnt.assign(n,1);
}

int Find(int a){
	int i=a,j=a,tmp;
	while(par[i]!=-1){ i=par[i]; }
	while(par[j]!=-1){ tmp=par[j]; par[j]=i; j=tmp; } //path compression
	return i;
}
void Uni(int a, int b){
	int A=Find(a),B=Find(b);
	if(A!=B){
		if(rnk[A]<rnk[B]) swap(A,B); // union using rank
		if(rnk[A]==rnk[B]) rnk[A]++;
		par[B]=A;
	}
}

double dist(pii u, pii v){
	double dx=u.X-v.X , dy=u.Y-v.Y;
	return sqrt(dx*dx+dy*dy);
}

int main(){
	while(cin >> n){
		E.clear(); p.clear(); int u,v,w,x,y;
		for(int i=0 ; i<n ; i++){
			cin >> x >> y; p.push_back(pii(x,y));
		}
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<n ; j++){
				if(i!=j) E.push_back(pfii(dist(p[i],p[j]),pii(i,j)));
			}
		}

		cin >> m; double ans=0; SetInit(n);
		for(int i=0 ; i<m ; i++){
			cin >> u >> v; u--, v--;
			if(Find(u)!=Find(v)){
				Uni(u,v);// ans+=dist(p[u],p[v]);
			}
		}
		sort(E.begin(), E.end()); 
		for(int i=0, j=0 ; i<E.size() && j<n-1; i++){
			if(Find(E[i].U)!=Find(E[i].V)){
				Uni(E[i].U,E[i].V); ans+=E[i].W; j++;
			}
		}
		printf("%.2lf\n",ans);
	}
	return 0;
}
