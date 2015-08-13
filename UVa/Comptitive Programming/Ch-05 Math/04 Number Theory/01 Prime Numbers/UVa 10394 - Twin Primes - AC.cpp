#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

typedef long long int64;
const int64 MAX = 2*1e7 + 10;

bitset<MAX> isp;// isprime
vector<int64> primes, tw1, tw2; //pfs = prime factors, pws = prime powers

void genPrimeAndTwins(){
    isp.set(); isp[0]=isp[1]=0;
    for(int64 i=2 ; i<MAX; i++){
        if(isp[i]){ primes.push_back(i);
            for(int64 j=i*i ; j<MAX ; j+=i) 
                isp[j]=0;
        }
    }

	for(int i=0 ; i<primes.size() ; i++){
		if(isp[primes[i]+2]){
			tw1.push_back(primes[i]), tw2.push_back(primes[i]+2);
		}
	}
}

int main(){
    int i; 
	genPrimeAndTwins();
    while(cin >> i){ i--; 
		cout << "(" << tw1[i] << ", " << tw2[i] << ")" << endl;
    }
}

