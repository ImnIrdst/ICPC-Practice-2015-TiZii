#include <iostream>
#include <vector>

using namespace std;

typedef vector< int > stk;
typedef vector< stk > vstk;

stk st; vstk ans;

void solve(int n, int d){
    for(int i=d ; i*i<=n ; i++){
        if(n%i==0){
            st.push_back(i); solve(n/i,i); st.pop_back();
        }
    }
    st.push_back(n);  ans.push_back(st); st.pop_back();
}

int main(){
    int n;
    while(cin >> n && n){
        st.clear(); ans.clear(); solve(n,2);
        cout << ans.size()-1 << endl;
        for(int i=0 ; i<ans.size()-1 ; i++){
            for(int j=0 ; j<ans[i].size() ; j++){
                if(j>0) cout << " "; cout << ans[i][j];
            }
            cout << endl;
        }
    }   
}