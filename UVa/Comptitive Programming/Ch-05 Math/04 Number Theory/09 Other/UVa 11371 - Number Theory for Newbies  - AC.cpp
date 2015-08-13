#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <sstream>
#include <algorithm>
#include <functional>

using namespace std;

typedef long long int int64;

int main(){
    string num1, num2; stringstream sstr;
    while(cin >> num1){
        sort(num1.begin(), num1.end());
        int i; for(i=0 ; num1[i]=='0'; i++);

        num1[0]=num1[i];
        if(i>0) num1[i]='0';

        num2=num1; sort(num2.begin(), num2.end(),::greater<char>());
        int64 n1; sstr.clear(); sstr << num1; sstr >> n1;
        int64 n2; sstr.clear(); sstr << num2; sstr >> n2;

        printf("%lld - %lld = %lld = 9 * %lld\n",n2,n1,n2-n1,(n2-n1)/9);

    }
    return 0;
}

