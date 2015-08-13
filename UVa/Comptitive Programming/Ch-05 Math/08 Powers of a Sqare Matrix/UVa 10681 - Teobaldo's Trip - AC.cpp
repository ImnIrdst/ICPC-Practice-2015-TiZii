
#include <stdio.h>
#include <iostream>
#include <climits>
#include <string.h>
#define MAX (100+10)
#define int64 long long

using namespace std;

struct Matrix{
    bool e[MAX][MAX]; int n;
    bool* operator[](int i){
        return e[i];
    }
    Matrix operator=(Matrix b){
        n=b.n;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<n ; j++){
                e[i][j]=b[i][j];
            }
        }
        return *this;
    }
    Matrix(int n){
        memset(e,0,sizeof e); this->n=n;
    }
};

Matrix MatMul(Matrix& a, Matrix& b){
    Matrix ans(a.n);
    for(int i=0 ; i<a.n ; i++){
        for(int j=0 ; j<a.n ; j++){
            for(int k=0 ; k<a.n ; k++){
                ans[i][j] |= a[i][k] & b[k][j];
            }
        }
    }
    return ans;
}

Matrix MatPow(Matrix base, int64 p){
    Matrix ans(base.n); for(int i=0 ; i<ans.n ; i++) ans[i][i]=1;
    while(p){
        if(p%2) ans = MatMul(ans,base);
        base = MatMul(base,base);
        p/=2;
    }
    return ans;
}

int main()
{
    int n,m;
    while(cin >> n >> m && (n||m)){
        Matrix base(n), ans(n);
        int u,v,d;
        for(int i=0 ; i<m ; i++){
            cin >> u >> v; u--, v--;
            base[u][v]=base[v][u]=1;
        }
        cin >> u >> v >> d; u--,v--;
        ans = MatPow(base,d);
        if(ans[u][v]) cout << "Yes, Teobaldo can travel." << endl;
        else cout << "No, Teobaldo can not travel." << endl;
    }
}
