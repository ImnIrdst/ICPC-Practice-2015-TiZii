#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long int64;

const int Max = 1e5+10; int64 a[Max], n;

int numlen(int64 n){
	int len=0; while(n) len++, n/=10; return (n?len:1);
}

int numdif(int64 n, int64 m){
	int dif=0, i=1; 
	while(n && m){
		if(n%10!=m%10) dif=i;
		n/=10, m/=10; i++;
	}
	return dif;
}

int p10(int n){
	int p=1; for(int i=0 ; i<n ; i++) p*=10; return p;
}

void print(int s, int e){
	if(s==e){ cout << "0" << a[s] << endl; return; }
	int dif = numdif(a[e],a[s]);
	cout << "0" << a[s] << "-" << a[e]%p10(dif) << endl;
}

int main(){ int cs=1;
	while(scanf("%lld", &n) && n){
		for(int i=0 ; i<n ; i++) scanf("%lld", &a[i]);
		cout << "Case " << cs++ << ":" << endl;
		sort(a, a+n); int i;
		for(i=0 ; i<n-1 ; i++){
			int s=i ;
			while(a[i+1]==a[i]+1) i++;
			print(s, i);
		}
		if(i==n-1) print(i,i);
		cout << endl;
	}
}