#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define MAXN (024+10)
#define MAXX (150+10)
#define int64 long long int
using namespace std;



int64 Z,I,M,L,t=1;

int64 f(int64 X){
    return (Z*X+I)%M;
}

int main(){
    while(cin >> Z >> I >> M >> L && (Z||I||M||L)){
        int64 X0=L, tort=f(X0), hare=f(f(X0));
        while(tort!=hare){
            tort=f(tort); hare=f(f(hare));
        }
        
        int64 mu=0; hare=X0
                ;
        while(tort!=hare){
            tort=f(tort); hare=f(hare); mu++;
        }
        
        int64 lam=1; tort=hare; hare=f(tort);
        while(tort!=hare){
            hare=f(hare); lam++;
        }
        printf("Case %lld: %lld\n",t++ , lam);
    }
    return 0;
}

