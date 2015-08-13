#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define MAX (1000+10)

using namespace std;

typedef long long int int64;
char num[MAX]; int len;

bool check(int a){
    if(a==0) return 1;
    int mod=0; len=strlen(num);
    for(int i=0 ; i<len ; i++){
        mod = mod*10 + (num[i]-'0');
        mod %= a;
    }
    return !mod;
}

int main(){
    int tc; cin >> tc;
    while(tc--){
        bool OK=1;
        int n, a; cin >> num >> n;
        for(int i=0 ; i<n ; i++){
            cin >> a; OK &= check(a);
        }
        if(!OK) printf("%s - Simple.\n", num);
        if( OK) printf("%s - Wonderful.\n", num);
        //cout.flush();
    }
    return 0;
}

