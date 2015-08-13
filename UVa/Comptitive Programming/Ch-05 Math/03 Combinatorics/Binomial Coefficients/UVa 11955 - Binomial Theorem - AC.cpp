#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <sstream>
#define int64 long long
#define MAX (50+10)

using namespace std;

char var1[100], var2[100]; int n;

void scanInput(){
    string str,v1,v2,num; int i;
    getline(cin, str); v1=v2=num="";
    for(i=1 ; str[i]!='+' ; i++) v1+=str[i];
    for(i=i+1 ; str[i]!=')' ; i++) v2+=str[i];
    for(i=i+2 ; i<str.length() ; i++) num+=str[i];
    stringstream sstr(num); sstr >> n;
    strcpy(var1,v1.c_str()); strcpy(var2,v2.c_str());

}

int main(){
    int64 c[MAX][MAX];
    for(int i=0 ; i<MAX ; i++){
        c[i][0]=1; c[i][i]=1;
        for(int j=1 ; j<i ; j++){
            c[i][j]=c[i-1][j]+c[i-1][j-1];
        }
    }
    int tc, t=1; cin >> tc; cin.ignore();
    while(tc--){
        scanInput();
        //printf("%s",var1);
        printf("Case %d: ", t++);
        printf("%s",var1); if(n!=1) printf("^%d",n);
        for(int i=1 ; c[n][i]!=1 && n!=1 ; i++){
            printf("+%lld*%s",c[n][i],var1); if(n-i!=1) printf("^%d",n-i);
            printf("*%s",var2);  if(i!=1) printf("^%d",i);
        }
        printf("+%s",var2); if(n!=1) printf("^%d",n);
        printf("\n");
    }
}

