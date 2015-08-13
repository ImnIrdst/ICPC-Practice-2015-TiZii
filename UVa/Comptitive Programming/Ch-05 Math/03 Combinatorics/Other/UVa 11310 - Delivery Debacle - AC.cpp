#include <iostream>
#include <cstdio>
#include <cstring>
#define int64 long long
#define MAX (50+10)

using namespace std;

int64 a[40+1];

int main(){
    a[0]=a[1]=1; a[2]=5;
    for(int i=3 ; i<=40 ; i++){
        a[i]=a[i-1]+4*a[i-2]+2*a[i-3];
    }
    int tc,n; cin >> tc;
    while(tc--){
        cin >> n;
        cout << a[n] << endl;
    }
}

