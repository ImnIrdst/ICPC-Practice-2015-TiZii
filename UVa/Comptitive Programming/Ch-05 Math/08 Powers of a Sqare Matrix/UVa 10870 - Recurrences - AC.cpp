
#include <stdio.h>
#include <iostream>
#include <climits>
#include <string.h>
#define MAX (15+10)
#define int64 long long

using namespace std;

int64 m;

struct Matrix{
    int64 e[MAX][MAX]; int n;
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
                ans[i][j]+=(a[i][k]*b[k][j])%m; ans[i][j]%=m;
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
    int64 n,d,f[MAX];
    while(cin >> d >> n >> m && (d||n||m)){
        Matrix base(d), ans(d);
        for(int i=0 ;i<d ; i++) cin >> base[0][i];
        for(int i=0 ;i<d ; i++) base[i+1][i]=1;
        for(int i=0 ;i<d ; i++) cin >> f[d-i-1];

        int64 val=0;
        if(n>d){
            ans=MatPow(base,n-d);
            for(int i=0 ; i<d ; i++){
                val+=((ans[0][i]%m)*(f[i]%m))%m;
                val%=m;
            }
        }
        else {
            val=f[d-n]%m;
        }
        cout << val << endl;
    }
}
