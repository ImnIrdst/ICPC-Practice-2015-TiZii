#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int n, f, e, ans, cnt, a;// a == all
	while(cin >> n){
		//no borrowing
		f=n; e=0;  cnt=0; ans=0;
		while(f>0){
			a=f+e; cnt += f; f = a/3; e = a%3;
		}
		if(e>=0) ans = max(ans, cnt);
		//boroowing 1 empty bottle
		f=n; e=1;  cnt=0; 
		while(f>0){
			a=f+e; cnt += f; f = a/3; e = a%3;
		}
		if(e>=1) ans = max(ans, cnt);
		//boroowing 2 empty bottle
		f=n; e=2;  cnt=0;
		while(f>0){
			a=f+e; cnt += f; f = a/3; e = a%3;
		}
		if(e>=2) ans = max(ans, cnt);
		//Print the ans
		cout << ans << endl;
	}
}