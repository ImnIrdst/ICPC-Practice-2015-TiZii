#include <stdio.h>
#include <iostream>
#include <climits>
#include <string.h>
#define MAX 2
#define int64 long long

using namespace std;

int64 mod;

struct Matrix{
    int64 e[MAX][MAX],n;
    int64* operator[](int i){
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
                ans[i][j]+=(a[i][k]*b[k][j])%mod;
            }
            ans[i][j]%=mod;
        }
    }
    return ans;
}

Matrix MatPow(Matrix base, int64 p){
    Matrix ans(base.n); for(int i=0 ; i<ans.n ; i++) ans[i][i]=1;
    while(p){
        if(p%2) ans = MatMul(ans,base);
        base = MatMul(base,base);
        p>>=1;
    }
    return ans;
}

int main()
{
    int n,m;
    while(cin >> n >> m){
        Matrix base(2), ans(2); mod=1<<m;
        base[0][0]=1; base[0][1]=1;
        base[1][0]=1; base[1][1]=0;
        ans = MatPow(base,n);
        cout << ans[0][1] << endl;
    }
}
