#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

typedef unsigned long long int64;

int main(){
    int64 fact[21]={1}; for(int64 i=1 ; i<21 ; i++) fact[i]=i*fact[i-1];

    int tc,t=1; cin >> tc;
    while(tc--){
        int64 freq[30]={0}; char str[22]; cin >> str;
        int64 n=strlen(str);
        for(int64 i=0 ; i<n ; i++){
            freq[str[i]-'A']++;
        }
        int64 ans = fact[n];
        for(int64 i=0 ; i<30 ; i++){
            ans/=fact[freq[i]];
        }
        printf("Data set %d: %lld\n",t++, ans);
    }
}
//1 QWERTYUIOPLKJHGFDSAZ