#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <bitset>
#define int64 long long

using namespace std;

int main(){
    int64 n;
    while(cin >> n && n){
        int64 euler=n, tmp=n;
        for(int64 pf=2 ; pf*pf<=tmp ; pf++){
            if(tmp%pf==0) euler-=euler/pf;
            while(tmp%pf==0) tmp/=pf;

        }
        if(tmp>1) euler-=euler/tmp;
        cout << euler << endl;
    }

}

