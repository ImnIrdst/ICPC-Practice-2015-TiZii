#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const double eps = 1e-4;

typedef pair<int,int> pii; 

vector<pii> Calc_Pfs(int b){
	vector<pii> pfs;
	for(int i=2 ; i*i<=b ; i++){
		int Pow=0;
		while(b%i==0) Pow++, b/=i;
		if(Pow) pfs.push_back(pii(i,Pow));
	}
	if(b>1) pfs.push_back(pii(b,1));
	return pfs;
}

int ZeroCnt(int n, int b){//n == number, b = base
	int cnt=1e9;
	vector<pii> pfs = Calc_Pfs(b);
	for(int i=0 ; i<pfs.size() ; i++){
		int tmp=0, pf=pfs[i].first, num=n;
		while(num) 
			tmp+=(num/pf), num/=pf;
		cnt = min(cnt, tmp/pfs[i].second); 
	}
	return cnt;
}

int DigitsCnt(int n, int b){
	double ret=0;
	for(int i=1 ; i<=n ; i++){
		ret += log10(i);
	}
	ret/=log10(b);
	return int(ret+eps)+1;
}


int main(){
	int n, b;
	while(cin >> n >> b){
		cout << ZeroCnt(n,b) << " " << DigitsCnt(n,b) << endl;
	}
}