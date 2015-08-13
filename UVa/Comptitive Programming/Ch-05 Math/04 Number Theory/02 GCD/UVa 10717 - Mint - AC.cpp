#include <stdio.h>
#include <iostream>
#include <climits>
#include <algorithm>
#define MAX (50+10)
#define int64 long long

using namespace std;

int64 a[MAX],T,n,m,Min,Max;

int64 GCD(int64 a, int64 b){
    if(b==0) return a;
    return GCD(b,a%b);
}
int64 LCM(int64 a, int64 b){
    if(a==0) return b; if(b==0) return a;
    return (a*b)/GCD(a,b);
}

void calcMin(int64 num){
    int64 ret=0;
    for(int i=1 ; num*i<=T ; i++)
        ret=num*i;
    Min=max(Min,ret);
}

void calcMax(int64 num){
    int64 ret=0;
    for(int i=1 ; ret<T ; i++)
        ret=num*i;
    Max=min(Max,ret);
}

void search(int64 idx, int64 lev, int64 num){
    if(lev==4){
        calcMax(num); calcMin(num); return;
    }

    for(int64 i=idx+1 ; i<n ; i++){
        search(i,lev+1,LCM(num,a[i]));
    }
}

int main(){
    while(cin >> n >> m && (n||m)){
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
        }
        //cout << GCD(400,200) << endl;
        //cout << GCD(1,200) << endl;
        for(int i=0 ; i<m ; i++){
            cin >> T;  Min=LLONG_MIN; Max=LLONG_MAX;
            search(-1,0,0);
            cout << Min << " " << Max << endl;
        }
    }
}
