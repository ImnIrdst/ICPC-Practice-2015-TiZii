#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>

using namespace std;

typedef long long int64;
const int64 MAX = 65000 + 10;


bitset<MAX> isp, isCarm;// isprime && normal
vector<int64> primes;
int64 n;

void genprime(){
    isp.set(); isp[0]=isp[1]=0;
    for(int64 i=2 ; i<MAX; i++){
        if(isp[i]){
            for(int64 j=i*i ; j<MAX ; j+=i) 
                isp[j]=0;
        }
    }
}

int64 PowMod(int64 b, int64 p, int64 m){
	if(p==1) return b%m;
	if(p%2==1) return (b*PowMod(b, p-1, m))%m;
	int64 pm = PowMod(b, p/2, m); 
	return (pm*pm)%m;
}

void genCarms(){
	isCarm.reset();
	for(int64 n=2 ; n<MAX ; n++){
		isCarm[n]=!isp[n];
 		if(n==46657)
			n=n;
		for(int64 a=2 ; a<n && isCarm[n]; a++){
			int poww=PowMod(a,n,n);
			if(poww%n!=a)
				isCarm[n]=0;
		}
	}
}

int main(){
	genprime(); genCarms();
	while(cin >> n && n){
		if(!isCarm[n]) cout << n << " is normal." << endl;
		else cout << "The number " << n << " is a Carmichael number." << endl;
	}
}

