#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <bitset>
#define int64 long long

using namespace std;

int main(){
    int64 u,v,tc; cin >> tc;
    while(tc--){
        cin >> u >> v; int64 MaxNum=-1, MaxC=-1;
        for(int64 i=u ; i<=v ; i++){
            int64 c=1; int64 tmp=i;
            for(int64 j=2 ; j*j<=tmp ; j++){
                int64 pow=0;
                while(tmp%j==0) pow++, tmp/=j;
                c*=(pow+1);
            }
            if(tmp>1) c*=(1+1);
            if(MaxC<c) MaxC=c, MaxNum=i;
        }
        printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",u,v,MaxNum,MaxC);
    }

}

