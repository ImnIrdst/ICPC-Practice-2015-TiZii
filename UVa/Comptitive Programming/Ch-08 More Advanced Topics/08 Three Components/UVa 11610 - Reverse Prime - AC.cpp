#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <vector>
#define INF (int)1e9
#define MAX (int)1e6
#define int64 long long

using namespace std;

vector<int> SumTree, DelIdxTree,prime,revprime,pf; int n;//pf = prime factor
bitset<MAX> isp;// isprime

int BSearch(int i, int j, int val){
    int m=(i+j)/2;
    if(val == revprime[m]) return m;
    if(val >  revprime[m]) return BSearch(m+1,j,val);
    else                   return BSearch(i,m-1,val);
}

int64 fenweak_read(vector<int>& tree, int idx){
    int64 sum=0;
    while(idx>0){
        sum+=tree[idx]; idx-=(idx & -idx);
    }
    return sum;
}

int64 fenweak_val(vector<int>& tree, int idx){
    return fenweak_read(tree,idx)-fenweak_read(tree,idx-1);
}

void fenweak_update(vector<int>& tree, int idx, int val){
    int64 sum=0;
    while(idx<n){
        tree[idx]+=val; idx+=(idx & -idx);
    }
}


void genprime(){
    isp.set(); isp[0]=isp[1]=0;
    for(int64 i=2 ; i<MAX ; i++){
        if(isp[i]){
            prime.push_back(i);
            for(int64 j=i*i ; j<MAX ; j+=i) isp[j]=0;
        }
     
    }
}

int reverse(int n){
    int r=0, i=0;
    while(n){
        r += n%10; r*=10; 
        n /= 10;   i++;
    }
    while(i+1<7) r*=10, i++;
    return r;
}

bool isprime(int n){
    if(n<MAX) return isp[n];
    for(int i=0 ; i<prime.size() ; i++){
        if(n%prime[i]==0) return 0;
    }
    return 1;
}


int PrimeFactorsCnt(int n){
    int j=0, ret=0; 
    while(!isprime(n)){
        if(n % prime[j] == 0){
            n /= prime[j]; ret++;
        }else j++;
    }
    return ret+1;
}

void calcRevPrime(){
    
    genprime(); n=prime.size();
    //cout << PrimeFactorsCnt(24)  << endl;
    for(int i=0 ; i<prime.size() ; i++){
        revprime.push_back(reverse(prime[i]));
    }
    sort(revprime.begin(), revprime.end());
    SumTree.assign(n,0); DelIdxTree.assign(n,0);
    for(int i=0 ; i<revprime.size() ; i++){
        fenweak_update(SumTree,i+1,PrimeFactorsCnt(revprime[i]));
    }
}

int getRealIdx(int fake){
    int lo=0, hi=n-1, mid;
    while(lo<hi){
        mid = (lo+hi)/2;
        if(mid-fenweak_read(DelIdxTree,mid) >= fake) hi=mid;
        else lo=mid+1;
    }
    while(fenweak_val(DelIdxTree,hi)==1) hi--;
    return hi;
}

int main(){
    calcRevPrime(); //cout << n << endl;
    char c; int val; 
    while(cin >> c >> val){
       if(c == 'q'){
           int idx=getRealIdx(val+1);
           cout << fenweak_read(SumTree,idx) << endl;
       }
       if(c == 'd'){
            int idx = BSearch(0,revprime.size()-1,val)+1;
            fenweak_update(DelIdxTree ,idx ,1);
            fenweak_update(SumTree    ,idx ,-1*PrimeFactorsCnt(val));
       }
    }
    return 0;
}