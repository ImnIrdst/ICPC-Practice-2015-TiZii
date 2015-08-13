#include <iostream>
#include <cmath>
#include <algorithm>
#define int64 long long

using namespace std;

int main(){
    int64 n,k;
    while(cin >> n >> k){
        int ans; double tmp=0; k=min(k,n-k);
        for(int i=0 ; i<k ; i++){
            tmp+=log10(n-i)-log10(i+1);
        }
        ans = floor(tmp)+1;
        cout << ans << endl;
    }
}

