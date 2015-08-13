#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

typedef long long int64;
const int64 MAX = 1e7 + 10;

bitset<MAX> isp;// isprime
vector<int64> primes; //pfs = prime factors, pws = prime powers

void genprime(){
    isp.set(); isp[0]=isp[1]=0;
    for(int64 i=2 ; i<MAX; i++){
        if(isp[i]){ primes.push_back(i);
            for(int64 j=i*i ; j<MAX ; j+=i) 
                isp[j]=0;
        }
    }
}

bool isprime(int64 n){
    if(n<MAX) return isp[n];
    for(int i=0 ; i<primes.size() && primes[i]*primes[i]<=n ; i++){
        if(n%primes[i]==0) return 0;
    }
    return 1;
}

int main(){
    int L, U; 
	genprime();
    while(cin >> L >> U){ 
		int mx = -1, mn = 1e9;
		int cx, cy, dx, dy, cur, prev=-1;
		for(int i=L ; i<=U ; i++){
			if(isprime(i)) cur = i; else continue;
			if(prev != -1){
				if(cur-prev > mx) 
					mx=cur-prev, dx=prev, dy=cur;
				if(cur-prev < mn) 
					mn=cur-prev, cx=prev, cy=cur;
			}
			prev = cur;
		}
		if(mx!=-1) 
			cout << cx << "," << cy << " are closest, ",
			cout << dx << "," << dy << " are most distant." << endl;
		if(mx==-1) 
			cout << "There are no adjacent primes." << endl;
    }
}

