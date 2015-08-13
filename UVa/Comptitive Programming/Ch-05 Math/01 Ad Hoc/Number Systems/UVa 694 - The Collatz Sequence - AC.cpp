#include <iostream>
#include <cstdio>

using namespace std;

typedef long long int64;

int main(){
	int64 A, L, cs=1;
	while(cin >> A >> L && (A>=0 && L>=0)){
		int64 ans=1, a=A, l=L;
		while(a!=1 && a<=l){
			if(a%2==0) a=a/2;
			else     a=a*3+1;
			ans++;
		}
		if(a!=1) ans--;
		printf("Case %lld: A = %lld, limit = %lld, number of terms = %lld\n", cs++, A, L, ans);
	}
}