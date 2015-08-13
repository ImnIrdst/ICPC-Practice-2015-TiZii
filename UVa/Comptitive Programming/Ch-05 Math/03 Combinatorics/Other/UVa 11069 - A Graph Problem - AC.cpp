#include <iostream>
#include <cstdio>
#include <cstring>
#define int64 long long
#define MAX (50+10)

using namespace std;

int64 dp[76+10][3];

int64 solve(int i, int z){//i==index, z==number of zeros following i;
    int64& dpp=dp[i][z];
    if(dpp!=-1) return dpp;
    if(z==0) dpp=solve(i-1,1);
    if(z==1) dpp=solve(i-1,2)+solve(i-1,0);
    if(z==2) dpp=solve(i-1,0);
    return dpp;
}

int main(){
    int n; memset(dp,-1,sizeof dp);
    dp[0][0]=dp[0][1]=1; dp[0][2]=0;
    while(cin >> n){
        cout << solve(n,1) << endl;
    }
}

