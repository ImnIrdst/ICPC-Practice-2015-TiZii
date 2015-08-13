#include <iostream>
#include <cstdio>
#include <math.h>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

typedef long long int int64;
typedef pair<int64,int64> pii;

int main(){
    string str;
    while(getline(cin,str) && str!="0"){
        stringstream sstr(str); int64 b,p,num=1;
        while(sstr >> b >> p){
            num*=pow(b,p);
        }
        vector<pii> fact; int64 tmp=--num;
        for(int64 f=2 ; f*f<=num; f++){
            int64 powi=0;
            while(tmp%f==0){
                tmp/=f; powi++;
            }
            if(powi>0){
                fact.push_back(pii(f,powi));
            }
        }
        if(tmp>1) fact.push_back(pii(tmp,1));
        //cout << fact.size() << endl;
        sort(fact.begin(), fact.end(), ::greater<pii>());
        for(int i=0 ; i<fact.size() ; i++){
            if(i!=0) printf(" ");
            printf("%lld %lld",fact[i].first,fact[i].second);
        }
        if(num==1) printf("1 1");
        printf("\n");
    }
}

