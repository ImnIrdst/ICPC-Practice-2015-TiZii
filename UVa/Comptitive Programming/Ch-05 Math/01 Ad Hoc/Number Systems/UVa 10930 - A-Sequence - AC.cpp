#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX (30+10)

using namespace std;

int a[MAX],dp[MAX][1000+10];

bool subsetsum(int idx,int val){
    if(val==0) return 1;
    if(idx<0 || val<0) return 0;
    int& dpp = dp[idx][val];
    if(dpp!=-1) return dpp;
    return dpp = subsetsum(idx-1,val-a[idx]) | subsetsum(idx-1,val);
}

int main(){
    int n,t=1;
    while(cin >> n){
        for(int i=0 ; i<n ; i++) cin >> a[i];
        bool OK=true;
        for(int k=1 ; k<n && OK ; k++){
            for(int i=0 ; i<k && OK; i++){
                for(int j=0 ; j<k && OK; j++){
                    if(a[i]>=a[k] || a[j]>=a[k]) OK=false;
                    if(i==j) continue;
                }
            }
            memset(dp,-1,sizeof dp);
            if(subsetsum(k-1,a[k])) OK=false;
        }
        printf("Case #%d:",t++);
        for(int i=0 ; i<n ; i++) printf(" %d",a[i]);
        if(OK) printf("\nThis is an A-sequence.");
        else   printf("\nThis is not an A-sequence.");
        printf("\n");
    }
}
