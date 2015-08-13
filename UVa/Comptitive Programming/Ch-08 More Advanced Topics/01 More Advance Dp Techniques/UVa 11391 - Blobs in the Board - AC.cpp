#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>

using namespace std;

const int MAX = 16+1  ;//Max Cells
const int INF = 1e9   ;//Max long long

int dp[1<<MAX], r, c, n;
int di[] = {-1,-1,-1, 0, 0, 1, 1, 1};
int dj[] = {-1, 0, 1,-1, 1,-1, 0, 1};
//for debugging bit mask
void printbitS(int bit){
    for(int i=0 ; i<r*c ; i++){
        if(bit&(1<<i)) cout << 1;
        else cout << 0;
    }
    cout << endl;
}
//decides a point is in range or not
bool inRange(int i, int j){return (i>=0 && i<r && j>=0 && j<c);}
//calc ans using dp+bitmask and simulation
int solve(int bit, int rem){
	int& dpp = dp[bit];
	if(rem==1) 
		return 1;
	if(dpp!=-1) return dpp;
	dpp=0;
	for(int i=0 ; i<r ; i++){
		for(int j=0 ; j<c ; j++){
			if((bit & (1 << (i*c+j))) == 0 ) continue; //this cell is non empty
			for(int d=0 ; d<8 ; d++){
				int i1 = i  + di[d], j1 = j  + dj[d];//first step
				int i2 = i1 + di[d], j2 = j1 + dj[d];//second step
				if(!inRange(i2,j2)) continue;
				if((bit & (1 << (i1*c+j1))) == 0 ) continue; //is first step is non empty
				if((bit & (1 << (i2*c+j2))) == 1 ) continue; //is second step is empty
				dpp += solve(bit ^ (1 << (i*c+j)) ^ (1 << (i1*c+j1)) 
								 ^ (1 << (i2*c+j2)), rem-1);
			}
		}
	}
	return dpp;
}

int main(){
    int tc,cs=1; cin >> tc;
    while(tc--){
    	//initialize and input
        cin >> r >> c >> n;
        int bit=0, x, y;
        for(int i=0 ; i<n ; i++){
        	cin >> x >> y; x--, y--;
        	bit |= ( 1 << (x*c+y) );
        }
        //calc and print ans
		memset(dp,-1,sizeof dp);
       	printf("Case %d: %d\n", cs++, solve(bit,n));
    }
}
