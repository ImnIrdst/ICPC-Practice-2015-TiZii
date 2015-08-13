#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define MAXN (024+10)
#define MAXX (150+10)

using namespace std;

typedef long long int int64;

int n, x; int64 dp[MAXN][MAXX];

int64 gcd(int64 a, int64 b){
    if(b==0) return a;
    return gcd(b,a%b);
}

int64 solve(int idx, int val){
    if(idx==n && val>=x) return 1;
    if(idx==n && val< x) return 0;
    int64& dpp=dp[idx][val];
    if(dpp!=-1) return dpp;

    dpp=0;
    for(int i=1 ; i<=6 ; i++){
        dpp+=solve(idx+1,val+i);
    }
    return dpp;
}

int main(){
    while(cin >> n >> x && (x||n)){
        memset(dp,-1,sizeof dp);
        int64 s=pow(6,n), e=solve(0,0), g=gcd(s,e);
        e/=g; s/=g;
        if(e==0) printf("0\n");
        else if(s==1) printf("1\n");
        else printf("%llu/%llu\n",e,s);
    }
    return 0;
}

/*
3 9
1 7
24 24
15 76
24 56
24 143
23 81
7 38
0 0
*/

