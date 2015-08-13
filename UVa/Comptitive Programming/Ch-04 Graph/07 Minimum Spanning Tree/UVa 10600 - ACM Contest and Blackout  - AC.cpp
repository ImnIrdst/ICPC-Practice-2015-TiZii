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
#define piii pair<int, pii >
#define W first
#define U second.first
#define V second.second

using namespace std;

vector<int> par,rnk,cnt;//par==parent
vector< piii > E;// e==edges array
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

int main(){
	int tc; cin >> tc;
	while(tc--){
		cin >> m >> n;
		E.clear(); int u,v,w;
		for(int i=0 ; i<n ; i++){
			cin >> u >> v >> w;  u--; v--;
			E.push_back(piii(w,pii(u,v)));
		}
		sort(E.begin(), E.end()); SetInit(m); int ans1=0; vector<int> marked;
		for(int i=0, j=0 ; i<E.size() && j<m-1; i++){
			if(Find(E[i].U)!=Find(E[i].V)){
				Uni(E[i].U,E[i].V); ans1+=E[i].W; j++; marked.push_back(i);
			}
		}
		int ans2=INF,tmp; // second best MST
		for(int k=0 ; k<marked.size() ; k++){
			tmp=0; SetInit(m); int j=0;
			for(int i=0 ; i<E.size() && j<m-1; i++){
				if(i==marked[k]) continue;
				if(Find(E[i].U)!=Find(E[i].V)){
					Uni(E[i].U,E[i].V); tmp+=E[i].W; j++;
				}
			}
			ans2=min(ans2,(j==m-1 ? tmp : INF));
		}
		cout << ans1 << " " << ans2 << endl;
	}
	return 0;
}
