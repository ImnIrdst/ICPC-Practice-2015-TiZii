#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#define MAX 1000
#define pii pair<int,int>
#define pdii pair<double, pii >
#define W first
#define U second.first
#define V second.second

using namespace std;

vector<int> par,rnk,cnt;//par==parent
vector< pdii > edges; int X[MAX+10], Y[MAX+10],n,r;

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

int main(){
	int t=1, tc; cin >> tc;
	while(tc--){
		edges.clear();
		cin >> n >> r; for(int i=0 ;i<n ; i++) cin >> X[i] >> Y[i];
		for(int i=0 ; i<n ; i++){
			for(int j=i+1 ; j<n ; j++){
				double w=hypot(X[i]-X[j],Y[i]-Y[j]);
				edges.push_back(pdii(w,pii(i,j)));
			}
		}
		SetInit(n); int states=1; double road=0, rail=0;
		sort(edges.begin(), edges.end());
		for(int i=0 ; i<edges.size(); i++){
			if(Find(edges[i].U)!=Find(edges[i].V)){
				Uni(edges[i].U,edges[i].V);
				if(edges[i].W>r) rail+=edges[i].W, states++;
				else road+=edges[i].W;
			}
		}
		printf("Case #%d: %d %.lf %.lf\n", t++, states, road, rail);
	}
	return 0;
}
