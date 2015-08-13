#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>
#define MAX (5000000+100)
#define INF (int64)1e12
#define int64 long long

using namespace std;

bitset<MAX> isp;// isprime
int64 bound, dp[MAX]={0};

void genprime(){
    isp.set(); isp[0]=isp[1]=0; bound++;
    for(int64 i=2 ; i<=bound ; i++){
        if(isp[i]){
            dp[i]+=i;
            for(int64 j=i*2 ; j<=bound ; j+=i) 
                isp[j]=0, dp[j]+=i;
        }
    }
}

int main(){
    bound=5000000+10; genprime();
    for(int i=2 ; i<bound ; i++){
        if(isp[ dp[i] ])  dp[i]=dp[i-1]+1;
        else              dp[i]=dp[i-1];
    }
    int64 a, b;//, tc; cin >> tc;
    while(cin >> a && a){ cin >> b;
        cout << dp[b]-dp[a-1] << endl;
    }
}

