#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <functional>
#define MAX (12+10)

using namespace std;

typedef long long int int64;

int main(){
    int64 a[MAX],f[MAX]; a[1]=0; a[2]=1; f[2]=2;
    for(int i=3 ; i<=12 ; i++){
        a[i]=(i-1)*(a[i-1]+a[i-2]);
        f[i]=i*f[i-1];
    }
    int n, tc; cin >> tc;
    while(tc--){
        cin >> n;
        printf("%lld/%lld\n",a[n],f[n]);
    }
    return 0;
}

