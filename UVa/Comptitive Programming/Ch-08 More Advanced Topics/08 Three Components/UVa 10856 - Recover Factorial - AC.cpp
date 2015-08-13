#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>
//#define MAX (1000000+10)
#define INF (int64)1e12
#define int64 long long
#define MAX (int64)(3*1e6)

using namespace std;
vector<int> prime;
bitset<MAX> isp;// isprime
int64 pfcnt[MAX]={0};//pfcnt = prime factor count

void genprime(){
    isp.set(); isp[0]=isp[1]=0;
    for(int64 i=2 ; i<MAX ; i++){
        if(isp[i]){
            prime.push_back(i);
            for(int64 j=i*i ; j<MAX ; j+=i) isp[j]=0;
        }
        pfcnt[i]+=pfcnt[i-1];
    }
}

void factpf(){//calc prime factors of a factorial
    genprime();
    for(int i=2 ; i<MAX ; i++){
        int n=i, j=0;
        while(!isp[n]){
            if(n % prime[j] == 0){
                pfcnt[i]++; n/=prime[j];
            }
            else j++;
        }
        pfcnt[i]+=pfcnt[i-1]+1;
    }
}

int main(){
    int n, cs=1; factpf();
    while(cin >> n && n>=-1){ 
        int lo=0, hi=MAX-1;
        while(lo<hi){
            int mid = (lo+hi)/2;
            if(pfcnt[mid]<n) lo=mid+1; else hi=mid;
        }
        printf("Case %d: ", cs++); 
        if(pfcnt[hi]==n) printf("%d!\n", hi);
        if(pfcnt[hi]!=n) printf("Not possible.\n");
    }
}

