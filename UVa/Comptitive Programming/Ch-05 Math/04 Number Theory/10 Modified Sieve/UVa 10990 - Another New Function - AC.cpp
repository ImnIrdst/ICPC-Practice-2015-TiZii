#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>

using namespace std;

typedef long long int64;
const int64 MAX = 2*1e6 + 10;

bitset<MAX> isp;// isprime
vector<int64> primes, phi, dphi, sum; //pfs = prime factors, pws = prime powers

void Init(){
	// Fill Primes, Phi, Dphi, Isprime, sum
	for(int i=0 ; i<MAX ; i++) 
		phi.push_back(i);
    isp.set(); isp[0]=isp[1]=0;
    for(int64 i=2 ; i<MAX; i++){
        if(isp[i]){ 
			primes.push_back(i); phi[i]=i-1;
            for(int64 j=i*2 ; j<MAX ; j+=i) 
                isp[j]=0, phi[j]=(phi[j]*(i-1))/i;
        }
    }
	sum.assign(MAX,0); sum[2]=1;
	dphi.resize(MAX); dphi[2]=1; 
	for(int i=3 ; i<MAX ; i++){
		dphi[i]=dphi[phi[i]]+1;
		sum[i]=sum[i-1]+dphi[i];
	}
}



//generation prime factors of a number
int main(){
    Init();
	int tc;
	cin >> tc;
    while(tc--){
		int n, m;
		cin >> n >>  m;
		cout << sum[m]-sum[n-1] << endl;
    }
}

