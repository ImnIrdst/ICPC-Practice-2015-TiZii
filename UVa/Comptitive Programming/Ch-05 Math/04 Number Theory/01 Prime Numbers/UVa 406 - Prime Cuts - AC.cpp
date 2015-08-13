#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

typedef long long int64;
const int MAX = 1e3 + 10;

bitset<MAX> isp;// isprime
vector<int64> primes;

void genprime(){
	primes.push_back(1);
    isp.set(); isp[0]=isp[1]=0;
    for(int i=2 ; i<MAX; i++){
        if(isp[i]){primes.push_back(i);
            for(int j=i*i ; j<MAX ; j+=i) isp[j]=0;
        }
    }
}

bool isprime(int n){
    if(n<MAX) return isp[n];
	for(int i=0 ; i<primes.size() ; i++){
        if(n%primes[i]==0) return 0;
    }
    return 1;
}

int main(){
	int n, c; genprime();
	while(cin >> n >> c){
		int m=0;
		for(m=0 ; m<n && primes[m]<=n ; m++);// m--;

		cout << n << " " << c << ":";
		if(m%2){
			for(int i=max(m/2-c+1,0); i<m/2+c && i<m ; i++){
				cout << " " << primes[i];
			}
		}else{
			for(int i=max(m/2-c,0); i<m/2+c   && i<m ; i++){
				cout << " " << primes[i];
			}
		}
		cout << endl << endl;
	}
}