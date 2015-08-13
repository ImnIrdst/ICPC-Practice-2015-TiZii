#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>


using namespace std;

typedef long long int64;
const int64 MAX = 1e6 + 10;

int lo, hi;
bitset<MAX> isp;// isprime
vector<int64> primes, freq; 

void genprime(){
    isp.set(); isp[0]=isp[1]=0;
    for(int64 i=2 ; i<MAX; i++){
        if(isp[i]){primes.push_back(i);
            for(int64 j=i*i ; j<MAX ; j+=i) 
                isp[j]=0;
        }
    }
}

int main(){
    int tc; cin >> tc; genprime();
    while(tc--){ cin >> lo >> hi; 
        int ii=0; while(primes[ii]<lo) ii++;

		freq.assign(MAX,0); 
		for(int i=ii+1 ; i<primes.size() && primes[i]<=hi ; i++){
			freq[primes[i]-primes[i-1]]++;
		}

		int Max=-1, champfreq=0, champ;
		for(int i=0 ; i<freq.size() ; i++){
			if(freq[i]>Max) Max=freq[i], champ=i, champfreq=0;
			if(freq[i]==Max) champfreq++;
		}
		if(champfreq==1) cout << "The jumping champion is " << champ << endl;
		if(champfreq!=1) cout << "No jumping champion" << endl;
    }
}

