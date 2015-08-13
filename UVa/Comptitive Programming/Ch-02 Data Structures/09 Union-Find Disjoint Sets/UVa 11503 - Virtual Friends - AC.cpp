#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#define INF (int)1e9
#define int64 long long

using namespace std;

vector<int> par,rnk,cnt; int numOfsets;

void SetInit(int n){
	par.clear(); rnk.clear(); cnt.clear();
	for(int i=0 ; i<n ; i++){ par.push_back(-1); rnk.push_back(0); cnt.push_back(1);}
	numOfsets=n; // if wanna count of disjoint sets
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
		numOfsets--; // if wanna count of disjoint sets
	}
	return cnt[A]; // if we wanna count each set size
}


int main(){
	int tc; cin >> tc;
	while(tc--){
		int n; cin >> n; string str1, str2;
		map<string,int> mp; int idx=1; SetInit(200000+10);
		for(int i=0 ; i<n ; i++){
			cin >> str1 >> str2;
			if(!mp[str1]) mp[str1]=idx++;
			if(!mp[str2]) mp[str2]=idx++;
			cout << Uni(mp[str1],mp[str2]) << endl;
		}
	}
	return 0;
}