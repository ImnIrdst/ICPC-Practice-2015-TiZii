#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <vector>
#define INF (int)1e9
#define int64 long long

using namespace std;

vector<int> tree,a,b; int n;

int64 read(int idx){
	int64 sum=0;
	while(idx>0){
		sum+=tree[idx]; idx-=(idx & -idx);
	}
	return sum;
}

void update(int idx, int val){
	int64 sum=0;
	while(idx<n){
		tree[idx]+=val; idx+=(idx & -idx);
	}
}

int main(){
	while(cin >> n && n){
		a.assign(n,0); b.assign(n,0); tree.assign(n,0);
		for(int i=0 ; i<n; i++){
			cin >> a[i]; b[i]=a[i];
		}
		sort(b.begin(),b.end());
		for(int i=0 ; i<n ; i++){
			int rank=(int)(lower_bound(b.begin(),b.end(),a[i])-b.begin());
			a[i]=rank+1;
		}
		int64 invs=0;//num of inversions
		for(int i=n-1 ; i>=0 ; i--){
			invs+=read(a[i]-1);
			update(a[i],1);
		}
		cout << (invs%2 ? "Marcelo" : "Carlos") << endl;
	}

	return 0;
}