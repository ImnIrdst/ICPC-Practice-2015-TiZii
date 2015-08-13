#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

vector<int> par,rnk,cnt; int ans;

void SetInit(int n){
	par.assign(n,-1); rnk.assign(n,0); cnt.assign(n,1); //par==parent
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
	}
	return cnt[A]; // if we wanna count each set size
}

int main(){
	int tc; cin >> tc;
	while(tc--){int n, m; cin >> n >> m;
		vector<int> money(n), groupMoney(n,0);
		for(int i=0 ; i<n ; i++) 
			cin >> money[i];

		int u,v; SetInit(n);
		for(int i=0 ; i<m ; i++){
			cin >> u >> v; Uni(u,v);
		}
		for(int i=0 ; i<n ; i++){
			groupMoney[Find(i)]+=money[i];
		}
		bool possible=true;
		for(int i=0 ; i<n && possible; i++){
			//cout << groupMoney[i] << " " ;
			if(groupMoney[i]) possible=false;
		}
		cout << (possible ? "POSSIBLE" : "IMPOSSIBLE") << endl;
	}
}