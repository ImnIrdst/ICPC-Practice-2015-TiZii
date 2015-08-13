#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>

using namespace std;

typedef long long int64;
const int64 MAX = 1e4 + 100;

bitset<MAX> isp;// isprime
vector<int64> primes, sum, pfs, pws; //pfs = prime factors, pws = prime powers

int getsum(int i, int j){
	if(i==0) return sum[j];
	if(i!=0) return sum[j]-sum[i-1];
}

void genprime(){
    isp.set(); isp[0]=isp[1]=0;
    for(int64 i=2 ; i<MAX; i++){
        if(isp[i]){primes.push_back(i);
            for(int64 j=i*i ; j<MAX ; j+=i) 
                isp[j]=0;
        }
    }
	sum.push_back(primes[0]);
	for(int i=1 ; i<primes.size() ; i++){
		sum.push_back(primes[i]+sum[i-1]);
	}
}

bool isprime(int n){
    if(n<MAX) return isp[n];
    for(int i=0 ; i<primes.size() ; i++){
        if(n%primes[i]==0) return 0;
    }
    return 1;
}
//generation prime factors of a number
int main(){
    int64 n; genprime();
    while(cin >> n && n){ 
		int ans=0;
		for(int i=0 ; i<primes.size() ; i++){
			int lo=i, hi=primes.size()-1;
			while(lo<hi){
				int mid = (hi+lo)/2;
				if( getsum(i,mid) >= n ) hi=mid; else lo = mid+1;
			}
			if(getsum(i,hi)==n) ans++;
		}
		cout << ans << endl;
    }
}

