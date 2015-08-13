
#include <iostream>
#include <cstdio>
#include <math.h>
#include <vector>

using namespace std;

typedef long long int int64;

int main(){
    int64 num;
    while(cin >> num && num){
        vector<int64> fact; int64 sign=1; 
        if(num<0) fact.push_back(-1),num*=-1,sign=-1;
        int64 tmp=num;
        for(int64 f=2 ; f*f<=num; f++){
            while(tmp%f==0){
                tmp/=f; fact.push_back(f);
            }
        }
        if(tmp>1) fact.push_back(tmp);
        printf("%lld = ",num*sign);
        for(int i=0 ; i<fact.size() ; i++){
            if(i!=0) printf(" x ");
            printf("%lld",fact[i]);
        }
        printf("\n");
    }
}

