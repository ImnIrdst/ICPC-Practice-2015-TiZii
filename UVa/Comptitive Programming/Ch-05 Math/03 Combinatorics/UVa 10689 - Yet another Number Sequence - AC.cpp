//Pisano period
#include <iostream>
#include <string>
#include <stdio.h>
#define MAX 15000+10
#define int64 long long

using namespace std;

int fib[MAX][4];

int POW10(int n){int val=1; while(n--) val*=10; return val;}

void initfib(){
    for(int j=0 ; j<4 ; j++)
        fib[0][j]=0, fib[1][j]=1;
    for(int i=2 ; i<MAX ; i++){
        for(int j=0, pow10=10 ; j<4 ; j++, pow10*=10){
            fib[i][j]=(fib[i-1][j]+fib[i-2][j])%pow10;
        }
    }
}

int main(){
    initfib();int a,b,n,m; int tc; cin >> tc;
    while(tc--){
        cin >> a >> b >> n >> m;
        if(m==1) n%=60; if(m==2) n%=300;
        if(m==3) n%=1500; if(m==4) n%=15000;
        int ans; m--;
        if(n==0) ans=a;
        if(n!=0) ans=a*fib[n-1][m]+b*fib[n][m];
        cout << ans%POW10(m+1) << endl;
    }
}

