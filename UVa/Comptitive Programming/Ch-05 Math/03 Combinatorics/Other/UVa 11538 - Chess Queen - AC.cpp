#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long int64;

int main(){
	int64 n, m;
	while(cin >> n >> m && (n||m)){
		// 1. Just in Diags
		int64 mn=min(m,n), mx=max(m,n), ans=0; 
		//this loop cause TLE We Can Compute it Straight forward
		
		//for(int64 i = 1; i!=mn ; i++){
		//	// i == num of cell in Diag i
		//	ans += i*(i-1);
		//	ans += i*(i-1);
		//}

		// == 2* ([2,...,mn-1]*([2,...,mn-1]-[1,...,1]))
		// == 2* ([2,...,mn-1]*[2,...,mn-1]-[2,...,mn-1]
		// == 2* (sigma((n-1)^2)-1-sigma(n-1)+1;
		int64 t = mn-1;
		ans +=2* ((t*(t+1)*(2*t+1))/6 - 1 - (t*(t+1))/2 + 1);
		// if n != m then from min -> max num of diag cells == min
		ans += (mn*(mn-1))*(mx-mn+1);
		ans *= 2; // there are 2 Diagonals
		ans += m*n*(n-1); // 2. just in Cols
		ans += n*m*(m-1); // 3. just in Rows
		cout << ans << endl;
	}
}