#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long int64;

int gcd(int a, int b){if(b==0) return a; return gcd(b,a%b);}

int64 X0, Y0, d;
void extEuclid(int a, int b){
    if(b==0){X0=1, Y0=0, d=a; return;}
    extEuclid(b,a%b);
    int x1=Y0, y1=X0-(a/b)*Y0;
    X0=x1; Y0=y1;
}

int main(){
    int64 n, n1, c1, n2, c2;
    int64 x1, y1, x2, y2, ansx, ansy;
    while(cin >> n && n){
        cin >> c1 >> n1 >> c2 >> n2;
        d = gcd(n1,n2);
        if(n%d){
            printf ("failed\n"); continue;
        }
        n/=d, n1/=d, n2/=d;
        extEuclid(n1,n2);
        X0*=n, Y0*=n;
        int64 a = ceil(-(double)X0/n2);
        int64 b = floor((double)Y0/n1);
        if(a>b){
            printf ("failed\n"); continue;
        }
        x1 = X0+n2*a; y1 = Y0-n1*a;
        x2 = X0+n2*b; y2 = Y0-n1*b;
        if (x1 * c1 + y1 * c2 < x2 * c1 + y2 * c2) ansx = x1, ansy = y1;
        else ansx = x2, ansy = y2;
        printf("%lld %lld\n",ansx, ansy);
    }
}

