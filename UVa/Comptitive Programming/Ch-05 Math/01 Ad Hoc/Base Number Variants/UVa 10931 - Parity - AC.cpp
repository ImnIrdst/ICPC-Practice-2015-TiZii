#include <iostream>
#include <cstdio>
#include <bitset>
#include <string>

using namespace std;

int main(){
    int n;
    while(cin >> n && n){
        bitset<64> b(n);
        string str = b.to_string(); int cnt=0; bool flag=1;
        for(int i=0 ; i<str.length() ; i++){
            //printf("%c ", str[i]);
            if(str[i]=='1') cnt++ , flag=0;
            if(flag && str[i]=='0') str.replace(i,1,""),i--;
        }
        printf("The parity of %s is %d (mod 2).\n",str.c_str(),cnt);
    }
}

