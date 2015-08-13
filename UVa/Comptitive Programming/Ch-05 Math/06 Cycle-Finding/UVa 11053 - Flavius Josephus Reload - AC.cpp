#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define MAXN (024+10)
#define MAXX (150+10)
#define int64 long long int
using namespace std;



int64 a,b,n,t=1;

int64 f(int64 X){
    int64 x = (X*X)%n;
    return (a*x+b)%n;
}

int main(){
    while(cin >> n && n){ cin >> a >> b;
        int64 X0=0, tort=f(X0), hare=f(f(X0));
        while(tort!=hare){
            tort=f(tort); hare=f(f(hare));
        }

        int64 mu=0; hare=X0;
        while(tort!=hare){
            tort=f(tort); hare=f(hare); mu++;
        }

        int64 lam=1; tort=hare; hare=f(tort);
        while(tort!=hare){
            hare=f(hare); lam++;
        }
        printf("%lld\n",n-lam);
    }
    return 0;
}

