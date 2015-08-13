#include <iostream>

using namespace std;

typedef long long int int64;

int64 log2(int64 n){ if(n==0) return 0;
    int64 ret=0, p2=1; while(p2<=n) p2*=2, ret++; return ret-1;
}

int main(){
    int64 n; //cout << log2(9) << endl << log2(8) << endl;
    while(cin >> n){
        cout << n-1 + log2(n-1) << endl;
    }
}