#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct frac{ int m,n; 
	frac(int m=0, int n=0):n(n),m(m){}
	bool operator <(frac f){ return m*f.n < f.m*n ; }
	bool operator==(frac f){ return f.m*n == m*f.n; }
}goal;

string solve(frac lo, frac mid, frac hi){// d = depth
	//cout << mid.m << " " << mid.n << " " << (mid  < goal)  << endl;
	if(mid == goal) return "";
	if(mid  < goal) 
		return 'R'+solve(mid, frac(mid.m+hi.m, mid.n+hi.n), hi);
	if(goal < mid) 
		return 'L'+solve(lo, frac(lo.m+mid.m, lo.n+mid.n), mid);
}

int main(){
	while(cin >> goal.m >> goal.n && !(goal==frac(1,1))){
		cout << solve(frac(0,1),frac(1,1),frac(1,0)) << endl;
	}
}