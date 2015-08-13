#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

typedef long long int64;

vector<int64> tree; int n, q;

int64 read(int idx){
	int64 sum=0; idx++;
	while(idx>0){
		sum+=tree[idx]; idx-=(idx & -idx);
	}
	return sum;
}

void update(int idx, int64 val){
	int64 sum=0; idx++;
	while(idx<=n){
		tree[idx]+=val; idx+=(idx & -idx);
	}
}

int64 Map(int64 x){
	if(x>0) return 0;
	if(x<0) return 1;
	else  return 1e9;
}

int64 query(int i, int j){
	if(i==0) return read(j);
	return read(j)-read(i-1);
}

int main(){
	while(cin >> n >> q){
		int tmp; tree.assign(n+1,0);
		for(int i=0 ; i<n ; i++){
			 cin >> tmp; update(i, Map(tmp));
		}
		//cout << read(3) << endl;
		string cmd; int a, b;
		for(int i=0 ; i<q ; i++){
			cin >> cmd >> a >> b; 
			if(cmd[0]=='C') update(a-1, Map(b)-query(a-1,a-1));
			if(cmd[0]=='P'){
				int64 res = query(a-1, b-1);
				if(res>=1e9) cout << '0';
				else if(res%2==0) cout << '+';
				else if(res%2==1) cout << '-';
			}
		}
		cout << endl;
	}

	return 0;
}
