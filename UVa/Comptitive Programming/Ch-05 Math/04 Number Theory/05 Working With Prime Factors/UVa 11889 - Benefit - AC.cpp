#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <bitset>
#define MAX (11000000+10)

using namespace std;

typedef unsigned long long int int64;

bitset<MAX> isp;// isprime
vector<int64> primes,factc,pofc,facta,pofa;//pof=PowerOfFactors
int64 bound;

void genprime(){
    isp.set(); isp[0]=isp[1]=0; bound++;
    for(int64 i=2 ; i<=bound ; i++){
        if(isp[i]){
            for(int64 j=i*i ; j<=bound ; j+=i) isp[j]=0;
            primes.push_back(i);
            //printf("%d: %d\n", primes.size(), primes.back());
        }
    }
}

void genfacts(vector<int64>& fact, vector<int64>& pof, int64 m){
    int64 tmp=m; //printf("%d  %d\n", fact.size(), pof.size());
    for(int i=0 ; primes[i]*primes[i]<=m; i++){
        int64 powi=0;
        while(tmp%primes[i]==0){
            tmp/=primes[i]; powi++;
        }
        if(powi>0){
            fact.push_back(primes[i]), pof.push_back(powi);
            //printf("%lld %lld\n",fact.back(),pof.back());
        }
    }
    if(tmp>1) fact.push_back(tmp), pof.push_back(1);//, printf("%lld %lld\n",fact.back(),pof.back());
}

bool check(){
    int i,j,found;
    for(i=0 ; i<facta.size() ; i++){
        found=0;
        for(j=0 ; j<factc.size() ; j++){
            //printf("%lld %lld\n",factc[i],facta[j]);
            if(facta[i]==factc[j] && pofa[i]<=pofc[j]){
                found=1;
            }
        }
        if(!found) return 0;
    }
    return 1;
}

int main(){
    int64 a,c; bound=1000000; genprime();
    int tc; cin >> tc;
    while(tc--){
        cin >> a >> c;
        if(a==1){
            cout << c << endl; continue;
        }
        facta.clear(); pofa.clear(); genfacts(facta,pofa,a);
        factc.clear(); pofc.clear(); genfacts(factc,pofc,c);

        int64 ans=1; //cout << "r1" << endl;
        for(int i=0, j=0 ; i<factc.size() ; i++){
            while(j+1<facta.size() && factc[i]>facta[j]) j++;
            //printf("%lld %lld\n",factc[i],facta[j]);
            if(factc[i]==facta[j] && pofc[i]>pofa[j]) ans*=pow(factc[i],pofc[i]);
            else if(facta[j]!=factc[i]) ans*=pow(factc[i],pofc[i]);
        }
        if(!check()) cout << "NO SOLUTION" << endl;
        else cout << ans << endl;
    }
}

