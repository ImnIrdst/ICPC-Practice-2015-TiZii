#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

int sumofdigit(int n){
    int sum=0;
    while(n){
        sum+=(n%10)*(n%10);
        n/=10;
    }
    return sum;
}

int main(){
    int n,m, tc, t=1; cin >> tc;
    while(tc--){
       cin >> n; set<int> st;
       m=sumofdigit(n);
       while(m!=1 && !st.count(m)){
           //cout << m << endl;
           st.insert(m); m=sumofdigit(m);
       }
       if(m==1) printf("Case #%d: %d is a Happy number.\n",t++,n);
       else     printf("Case #%d: %d is an Unhappy number.\n",t++,n);
    }
}
