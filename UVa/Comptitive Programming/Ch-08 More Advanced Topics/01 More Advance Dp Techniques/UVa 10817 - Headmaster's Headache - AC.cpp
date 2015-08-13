#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>

using namespace std;

typedef long long int;

const int MAXS = 8+1    ;//Max Subjects
const int MAXA = 100+10 ;//Max Applicants
const int INF  = 1e9   ;//Max long long

int dp[MAXA][1<<(MAXS*2)], teaches[MAXA][MAXS], cost[MAXA], s, m, n;
//for debugging bit mask
void printbitS(int bit){
    for(int i=0 ; i<2*s ; i++){
        if(bit&(1<<i)) cout << 1;
        else cout << 0;
    }
    cout << endl;
}
//initialize global arrays
void init(){
    memset(dp,-1,sizeof dp);
    memset(teaches,0,sizeof teaches);
}
//calc ans using dp + bitmask
int solve(int idx, int bit){
    int& dpp = dp[idx][bit]; //printbitS(bit); //Debug
    if(idx >= n && bit != (1<<(2*s))-1) return INF;
    if(bit == (1<<(2*s))-1) return 0;
    if(dpp != -1) return dpp;
    //either we choose a app or not
    dpp = INF; int bit2=bit;
    //if we choose him
    for(int i=0 ; i<s ; i++){
        if(teaches[idx][i]){
                if(bit2&(1<<i)) bit2 |= (1<<(i+s));
                else            bit2 |= (1<<(i  ));
        }
    }
    dpp = min(dpp, solve(idx+1, bit2) + cost[idx]);
    //if we dont choose him;
    dpp = min(dpp, solve(idx+1, bit ));
    return dpp;
}



int main(){
    while(cin >> s >> m >> n && (s||m||n)){
        //initialize and input
        
        int bit=0, u, c, ans=0; init();// bit == current assigned subjecs
        for(int i=0 ; i<m ; i++){
            cin >> c; ans += c;
            string str; getline(cin, str);
            stringstream sstr(str);
            while(sstr >> u){ u--;
                if(bit&(1<<u)) bit |= (1<<(u+s));
                else           bit |= (1<<(u  ));
            }
        }
        for(int i=0 ; i<n ; i++){
            cin >> cost[i]; 
            string str; getline(cin, str);
            stringstream sstr(str);
            while(sstr >> u){ u--; teaches[i][u]=1;}
        }
        //calculate min matching and print ans
        cout << ans+solve(0,bit) << endl;
    }
}