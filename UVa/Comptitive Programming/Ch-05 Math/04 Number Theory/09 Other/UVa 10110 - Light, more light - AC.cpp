#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

typedef long long int int64;

int main(){
    int64 n;
    while(cin >> n && n){
        int64 sq=sqrt(n);
        if(sq*sq==n) cout << "yes" << endl;
        if(sq*sq!=n) cout << "no" << endl;
    }
    return 0;
}

