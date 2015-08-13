#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector< int > vi;
typedef vector< vi  > vii;

vi par,rnk,cnt; vii membs; int numOfsets;

void SetInit(int n){
    par.assign(n,-1); rnk.assign(n,0); cnt.assign(n,1); //par==parent
    numOfsets=n; // if wanna count number of disjoint sets
    membs.assign(n,vi());//members of each set
    for(int i=0 ; i<n ; i++){
    	membs[i].push_back(i);
    }

}

int Find(int a){
    int i=a,j=a,tmp;
    while(par[i]!=-1){ i=par[i]; }
    while(par[j]!=-1){ tmp=par[j]; par[j]=i; j=tmp; } //path compression
    return i;
}
int Uni(int a, int b){
    int A=Find(a),B=Find(b);
    if(A!=B){
        if(rnk[A]<rnk[B]) swap(A,B); // union using rank
        if(rnk[A]==rnk[B]) rnk[A]++;
        par[B]=A;
        cnt[A]+=cnt[B]; // if we wanna count each set size
        numOfsets--; // if wanna count number of disjoint sets
    }
    return cnt[A]; // if we wanna count each set size
}

int main(){
    int n, m, cs=1; 
    while(cin >> n >> m && (n||m)){
        int u, v; SetInit(n);
        for(int i=0 ; i<m ; i++){
            cin >> u >> v; u--, v--; Uni(u,v);
        }
        printf("Case %d: %d\n", cs++, numOfsets);
    }
}