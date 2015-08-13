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
#define piii pair<int, pii >
#define W first
#define U second.first
#define V second.second

using namespace std;

vector<int> par,rnk,cnt,mark;//par==parent
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
	while(cin >> m >> n && (n||m)){
		E.clear(); int u,v,w,total=0;
		for(int i=0 ; i<n ; i++){
			cin >> u >> v >> w; total+=w;
			E.push_back(piii(w,pii(u,v)));
		}
		sort(E.begin(), E.end()); SetInit(m); bool first=true, hasAns=false;
		for(int i=0 ; i<E.size() ; i++){
			if(Find(E[i].U)!=Find(E[i].V)){
				Uni(E[i].U,E[i].V);
			}
			else{
				hasAns=true;
				if(!first) cout << " ";	first=false;
				cout << E[i].W;
			}
		}
		if(!hasAns) cout << "forest" << endl;
		else cout << endl;
	}
	return 0;
}
