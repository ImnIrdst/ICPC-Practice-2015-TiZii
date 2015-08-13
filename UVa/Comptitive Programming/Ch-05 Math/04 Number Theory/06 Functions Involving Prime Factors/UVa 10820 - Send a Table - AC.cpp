#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <bitset>
#define MAX (50001+10)

using namespace std;

typedef long long int int64;

bitset<MAX> isp;// isprime
vector<int64> primes;
int64 bound,ans[MAX];

void genprime(){
    isp.set(); isp[0]=isp[1]=0; bound++;
    for(int64 i=2 ; i<=bound ; i++){
        if(isp[i]){
            for(int64 j=i ; j<=bound ; j+=i)
                isp[j]=0, ans[j]-=ans[j]/i;
            primes.push_back(i);
        }
        ans[i]=ans[i-1]+ans[i]*2;
    }
}


int main(){
    for(int i=0 ; i<MAX ; i++) ans[i]=i;
    int64 num; bound=50001+5; genprime();
    while(cin >> num && num){
        cout << ans[num] << endl;
    }
}

