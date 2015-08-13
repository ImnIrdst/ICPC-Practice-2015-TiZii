#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <vector>
#define INF (int)1e9
#define MAX (500+10)

using namespace std;

struct p{
    int x,y,val;
    p(){}
    p(int X,int Y, int V){x=X; y=Y; val=V;}
    bool operator<(const p &a)const{return a.val>val;}
    bool operator>(const p &a)const{return a.val<val;}
};

int a[MAX][MAX]={0}; p stmx[MAX*MAX*4], stmn[MAX*MAX*4];

p BuildMaxSegT(int node, int x1, int y1, int x2, int y2){
    if(x1>x2 || y1>y2) return p(0,0,-1);
    if(x1==x2 && y1==y2){ 
        return stmx[node]=p(x1,y1,a[x1][y1]); }
    
    int midx=(x1+x2)/2, midy=(y1+y2)/2; p Max(0,0,-1);
    Max=max(Max,BuildMaxSegT(node*4-2, x1 , y1, midx, midy));
    Max=max(Max,BuildMaxSegT(node*4-1, midx+1 , y1, x2, midy));
    Max=max(Max,BuildMaxSegT(node*4+0, x1 , midy+1, midx, y2));
    Max=max(Max,BuildMaxSegT(node*4+1, midx+1 , midy+1, x2, y2));
    return stmx[node]=Max;
}

p QueryMax(int node, int x1, int y1, int x2, int y2, int qx1, int qy1, int qx2, int qy2){
    if(x1>qx2 || y1>qy2 || x2<qx1 || y2<qy1 || x1>x2 || y1>y2) return p(-1,-1,-1);
    if(qx1<=x1 && qx2>=x2 && qy1<=y1 && qy2>=y2){ 
        return stmx[node]; }
    
    int midx=(x1+x2)/2, midy=(y1+y2)/2; p Max(0,0,-1);
    Max=max(Max,QueryMax(node*4-2, x1 , y1, midx, midy,qx1,qy1,qx2,qy2));
    Max=max(Max,QueryMax(node*4-1, midx+1 , y1, x2, midy,qx1,qy1,qx2,qy2));
    Max=max(Max,QueryMax(node*4+0, x1 , midy+1, midx, y2,qx1,qy1,qx2,qy2));
    Max=max(Max,QueryMax(node*4+1, midx+1 , midy+1, x2, y2,qx1,qy1,qx2,qy2));
    return Max;
}

p UpdateMax(int node, int x1, int y1, int x2, int y2, int ux, int uy, int val){
    if(x1>x2 || y1>y2) return p(0,0,-1);
    if(ux>x2 || uy>y2 || ux<x1 || uy<y1) return stmx[node];
    if(x1==ux && y1==uy && x2==ux && uy==y2){ return stmx[node]=p(x1,y1,val); }
    
    int midx=(x1+x2)/2, midy=(y1+y2)/2; p Max(0,0,-1);
    Max=max(Max,UpdateMax(node*4-2, x1 , y1, midx, midy,ux,uy,val));
    Max=max(Max,UpdateMax(node*4-1, midx+1 , y1, x2, midy,ux,uy,val));
    Max=max(Max,UpdateMax(node*4+0, x1 , midy+1, midx, y2,ux,uy,val));
    Max=max(Max,UpdateMax(node*4+1, midx+1 , midy+1, x2, y2,ux,uy,val));
    return stmx[node]=Max;
}

p BuildMinSegT(int node, int x1, int y1, int x2, int y2){
    if(x1>x2 || y1>y2) return p(0,0,(int)1e9);
    if(x1==x2 && y1==y2){ 
        return stmn[node]=p(x1,y1,a[x1][y1]); }
    
    int midx=(x1+x2)/2, midy=(y1+y2)/2; p Min(0,0,(int)1e9);
    Min=min(Min,BuildMinSegT(node*4-2, x1 , y1, midx, midy));
    Min=min(Min,BuildMinSegT(node*4-1, midx+1 , y1, x2, midy));
    Min=min(Min,BuildMinSegT(node*4+0, x1 , midy+1, midx, y2));
    Min=min(Min,BuildMinSegT(node*4+1, midx+1 , midy+1, x2, y2));
    return stmn[node]=Min;
}

p QueryMin(int node, int x1, int y1, int x2, int y2, int qx1, int qy1, int qx2, int qy2){
    if(x1>qx2 || y1>qy2 || x2<qx1 || y2<qy1 || x1>x2 || y1>y2) return p(0,0,(int)1e9);
    if(qx1<=x1 && qx2>=x2 && qy1<=y1 && qy2>=y2){ 
        return stmn[node]; }
    
    int midx=(x1+x2)/2, midy=(y1+y2)/2; p Min(0,0,(int)1e9);
    Min=min(Min,QueryMin(node*4-2, x1 , y1, midx, midy,qx1,qy1,qx2,qy2));
    Min=min(Min,QueryMin(node*4-1, midx+1 , y1, x2, midy,qx1,qy1,qx2,qy2));
    Min=min(Min,QueryMin(node*4+0, x1 , midy+1, midx, y2,qx1,qy1,qx2,qy2));
    Min=min(Min,QueryMin(node*4+1, midx+1 , midy+1, x2, y2,qx1,qy1,qx2,qy2));
    return Min;
}

p UpdateMin(int node, int x1, int y1, int x2, int y2, int ux, int uy, int val){
    if(x1>x2 || y1>y2) return p(0,0,(int)1e9);
    if(ux>x2 || uy>y2 || ux<x1 || uy<y1) return stmn[node];
    if(x1==ux && y1==uy && x2==ux && uy==y2){ 
        return stmn[node]=p(x1,y1,val); }
    
    int midx=(x1+x2)/2, midy=(y1+y2)/2; p Min(0,0,(int)1e9);
    Min=min(Min,UpdateMin(node*4-2, x1 , y1, midx, midy,ux,uy,val));
    Min=min(Min,UpdateMin(node*4-1, midx+1 , y1, x2, midy,ux,uy,val));
    Min=min(Min,UpdateMin(node*4+0, x1 , midy+1, midx, y2,ux,uy,val));
    Min=min(Min,UpdateMin(node*4+1, midx+1 , midy+1, x2, y2,ux,uy,val));
    return stmn[node]=Min;
}
int main(){
    int n,m; cin >> n >> m;
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){
            cin >> a[i][j];
        }
    }
    BuildMaxSegT(1,1,1,n,m);
    BuildMinSegT(1,1,1,n,m);
    int qx1,qy1,qx2,qy2,ux,uy,val; char c[5];
    int q; cin >> q;
    while(q--){
        cin >> c; 
        if(c[0]=='q'){
            cin >> qx1 >> qy1 >> qx2 >> qy2;
            cout << QueryMax(1,1,1,n,m,qx1,qy1,qx2,qy2).val << " ";
            cout << QueryMin(1,1,1,n,m,qx1,qy1,qx2,qy2).val << endl;
        }
        else{
            cin >> ux >> uy >> val;
            UpdateMax(1,1,1,n,m,ux,uy,val);
            UpdateMin(1,1,1,n,m,ux,uy,val);
        }
    }

    return 0;
}