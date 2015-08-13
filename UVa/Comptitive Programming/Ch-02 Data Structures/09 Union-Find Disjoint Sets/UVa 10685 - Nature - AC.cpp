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
	int n, m;
	while(cin >> n >> m && (n||m)){
		string str1, str2; ans = 1; SetInit(n);
		for(int i=0 ; i<n ; i++) cin >> str1;
		int tmp=0; map<string,int> mp;
		for(int i=0 ; i<m ; i++){
			cin >> str1 >> str2;
			if(!mp.count(str1)) mp[str1]=tmp++;
			if(!mp.count(str2)) mp[str2]=tmp++;
			ans = max(ans, Uni(mp[str1],mp[str2]));
		}
		cout << ans << endl;
	}
}