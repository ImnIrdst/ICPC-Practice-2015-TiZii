#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>

using namespace std;

typedef long long int64;
const int64 MAX = 1e6 + 10;

bitset<MAX> isp;// isprime
vector<int64> primes, pfs, pws; //pfs = prime factors, pws = prime powers

void genprime(){
    isp.set(); isp[0]=isp[1]=1;
    for(int64 i=2 ; i<MAX; i++){
        if(isp[i]){
			primes.push_back(i);
            for(int64 j=i*i ; j<MAX ; j+=i) 
                isp[j]=0;
        }
    }
}

int ans[MAX];

void PreProcess(){
	genprime();
	ans[1]=ans[0]=0;
	for(int n=2 ; n<MAX ; n++){
		ans[n]=ans[n-1];
		int tmp = n, j=0;
		for(int j=0, pf=primes[j] ; tmp && !isp[tmp] ; pf=primes[j++]){
			while(tmp%pf==0){
				ans[n]++; tmp/=pf;
			}
		}
		if(isp[tmp] && tmp>1) ans[n]++;
	}
}

int main(){
	int n; PreProcess();
	while(cin >> n){
		cout << ans[n] << endl;
	}
}