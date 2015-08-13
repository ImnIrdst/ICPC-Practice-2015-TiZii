#include <iostream>
#define int64 long long

using namespace std;

int64 a[1000000+1];

int main(){
    int n; a[3]=0;
    for(int64 i=4 ; i<1000000+1 ; i++){
        if(i%2) a[i]=(i-1)*(i-3)/4 + a[i-1];
        else    a[i]=(i-2)*(i-2)/4 + a[i-1];
    }
    while(cin >> n && n>=3){
        cout << a[n] << endl;
    }
}

