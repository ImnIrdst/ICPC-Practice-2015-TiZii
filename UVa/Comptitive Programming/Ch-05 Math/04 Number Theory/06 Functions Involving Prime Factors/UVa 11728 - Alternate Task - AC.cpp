#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>

#define int64 long long
#define powPFP(PF, P) (int64)pow((double)PF, P + 1.0)

using namespace std;

int64 ans[1000+10];

void preprocessing(){

    for(int i=0 ; i<=1000 ; i++){
        int64 sumofdiv=1;  int64 tmp=i;
        for(int64 pf=2 ; pf*pf<=tmp ; pf++){
            int Pow=0;
            while(tmp%pf==0) Pow++,tmp/=pf;
            sumofdiv*=(powPFP(pf,Pow)-1)/(pf-1);
        }
        if(tmp>1) sumofdiv*=(powPFP(tmp,1)-1)/(tmp-1);
        if(sumofdiv<=1000) ans[sumofdiv]=i;
    }

}

int main(){
    memset(ans,-1,sizeof ans);
    int64 n,t=1; preprocessing();
    while(cin >> n && n){
        printf("Case %d: %lld\n",t++ ,ans[n]);
    }

}

