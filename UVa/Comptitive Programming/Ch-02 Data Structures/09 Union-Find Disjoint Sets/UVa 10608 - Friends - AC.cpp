#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> par,rnk,cnt; int numOfsets;

void SetInit(int n){
    par.assign(n,-1); rnk.assign(n,0); cnt.assign(n,1); //par==parent
    numOfsets=n; // if wanna count number of disjoint sets
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
    int tc; cin >> tc;
    while(tc--){
        int n, m; cin >> n >> m; 
        SetInit(n);
        
        int u, v; int ans=-1;
        for(int i=0 ; i<m ; i++){
            cin >> u >> v; u--, v--;
            ans = max(ans, Uni(u,v));
        }
        cout << ans << endl;
    }
}