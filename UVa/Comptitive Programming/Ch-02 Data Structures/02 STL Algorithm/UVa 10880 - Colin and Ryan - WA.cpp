#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main(){
    int tc,cs=1; cin >> tc;
    while(tc--){
        int c, r; cin >> c >> r;
        if( c==r ){ cout << 0 << endl; continue; }
        vector<int> ans;
        int tmp = c-r, sq = sqrt(tmp);
        for(int i=1 ; i<=sq ; i++){
            if(tmp%i == 0){
                if(i>r && i!=sq) ans.push_back(i);
                if(tmp/i>r) ans.push_back(tmp/i);
            }
        }
        cout << "Case #" << cs++ << ":" ;
        sort(ans.begin(), ans.end());
        for(int i=0 ; i<ans.size() ; i++){
            cout << " " << ans[i];
        }cout << endl;
    }
}