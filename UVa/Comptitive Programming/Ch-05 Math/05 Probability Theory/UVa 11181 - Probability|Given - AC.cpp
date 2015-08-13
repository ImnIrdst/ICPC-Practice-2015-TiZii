#include <iostream>
#include <cstdio>
#define MAX (30+10)

using namespace std;

int n, r; double sum[MAX], p[MAX], total;

void dfs(int idx, int cnt, double val, int bitmask){
  if(cnt>=r){
    for(int i=0 ; i<n ; i++){
      if(!(bitmask&(1<<i))) val*=(1-p[i]);
    }
    total += val;
    for(int i=0 ; i<n ; i++){
      if(bitmask&(1<<i)) sum[i]+=val;
    }
    return;
  }
  for(int i=idx ; i<n ; i++){
    dfs(i+1,cnt+1,val*p[i],bitmask|(1<<i));
  }
}

int main(){
  int t=1;
  while(cin >> n >> r && (n||r)){
    for(int i=0 ; i<n ; i++) cin >> p[i], sum[i]=0;
    total=0; dfs(0,0,1,0);
    printf("Case %d:\n",t++);
    for(int i=0 ; i<n ; i++)
        printf("%.6f\n",sum[i]/total);
  }
}
