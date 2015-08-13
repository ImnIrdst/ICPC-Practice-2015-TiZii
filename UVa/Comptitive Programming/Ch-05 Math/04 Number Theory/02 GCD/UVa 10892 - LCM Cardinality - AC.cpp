#include <iostream>
#include <stdio.h>
#include <cmath>
#include <vector>
#define int64 long long

using namespace std;

int64 gcd(int64 a, int64 b){if(b==0) return a; return gcd(b,a%b); }
int64 lcm(int64 a, int64 b){return (a*b)/gcd(b,a%b); }

int main(){
	int64 n;
	while(cin >> n && n){
		vector<int64> f,p; // f==factors, p==Power Of Factor[i]
		int64 backup=n;
		for(int64 fact=2 ; fact*fact<=backup ; fact++){
			int64 powi=0;
			while(n%fact==0){
				powi++, n/=fact;
			}
			//printf("%lld %lld\n", fact, powi);
			if(powi>0){
				f.push_back(fact); p.push_back(powi);
				//printf("%lld %lld\n", f.back(), p.back());
			}
		}
		if(n>1) f.push_back(n), p.push_back(1);//printf("%lld %lld\n", f.back(), p.back());

		int64 ans=1;
		for(int64 i=0 ; i<f.size() ; i++){
			int64 ansi=p[i];
			//printf("%lld %lld\n", ans, ansi);
			for(int64 j=i+1 ; j<f.size(); j++){
				ansi*=2*p[j]+1;
				//printf("%lld %lld\n", ans, ansi);
			}
			ans+=ansi;
			//printf("%lld %lld\n", ans, ansi);
		}
		printf("%lld %lld\n", backup, ans);
	}
	return 0;
}
