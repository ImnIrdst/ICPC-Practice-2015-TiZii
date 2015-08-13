#include <stdio.h>
#include <iostream>
#include <climits>
#include <vector>
#define int64 unsigned long long

using namespace std;

int64 f(int64 n){
    int64 ans=0,i,p2;
    for(i=1, p2=1 ; i<64 && ans<n ; i++, p2*=2){
        ans+=p2;
    }
    ans = n-(ans-p2/2);
    return ans*2-1;
}

int main()
{
    int64 n=1, m=1;
    while(cin >> n >> m){
        int64 ans=n;
        int64 prevAns=0;
        while(m-- && ans!=1 && ans!=prevAns){
            prevAns=ans; ans=f(ans);
        }

        cout << ans << endl;
    }
    return 0;
}
