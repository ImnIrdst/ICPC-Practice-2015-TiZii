#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

vector<int> par,rnk,cnt; int numOfsets;

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

int main(){
	int V, E, K;
	while(cin >> V >> E){
		map<char,int> mp;
		char u, v; SetInit(V); int n=0;
		for(int i=0 ; i<E ; i++){
			cin >> u >> v; 
			if(!mp.count(u)) mp[u]=n++;
			if(!mp.count(v)) mp[v]=n++;
			Uni(mp[u], mp[v]);
		}
		K = numOfsets;
		cout << E-V+1+K << endl;
	}
}
