#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int a[15+2], dp[100+10][1<<15];
int preSum[1<<15], preCount[1<<15];

int Count(int bit){
	int cnt=0; for(int i=0 ; i<16 ; i++) if(bit&(1<<i)) cnt++; return cnt;
}

int Sum(int bit){
	int sum=0; for(int i=0 ; i<16 ; i++) if(bit&(1<<i)) sum+=a[i]; return sum;
}

bool solve(int y, int bit){
	if(preCount[bit]==1) return true;
	if(dp[y][bit]!=-1) return dp[y][bit];

	int x = preSum[bit]/y;
	for(int bbit = (bit-1)&bit ; bbit ; bbit = (bbit-1)&bit){
		int rbit = bit - bbit;
		int mn1 = min(preSum[bbit]/y, y);
		int mn2 = min(preSum[rbit]/y, y);
		int mn3 = min(preSum[bbit]/x, x);
		int mn4 = min(preSum[rbit]/x, x);
		if(preSum[bbit]%y == 0 && preSum[rbit]%y == 0 
			&& solve(mn1, bbit) && solve(mn2, rbit)) return dp[y][bit]=true;
		if(preSum[bbit]%x == 0 && preSum[rbit]%x == 0 
			&& solve(mn3, bbit) && solve(mn4, rbit)) return dp[y][bit]=true;

	}
	return dp[y][bit]=false;
}

int main(){
	int n, cs=1;
	while(cin >> n && n){
		int x, y; cin >> x >> y;

		int sum=0;
		for(int i=0 ; i<n ; i++){
			cin >> a[i]; sum += a[i];
		}
		for(int i=0 ; i<(1<<n) ; i++) 
			preSum[i]=Sum(i), preCount[i]=Count(i);
		
		
		memset(dp, -1, sizeof dp);
		cout << "Case " << cs++ << ": ";// << endl;
		if(preSum[(1<<n)-1] != (x*y)) cout << "No" << endl;	
		else if(solve(min(x,y), (1<<n)-1)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
}