#include <iostream>
#include <string>

using namespace std;

typedef unsigned long long int64;

struct frac{ int64 a, b; frac(int64 a=0, int64 b=0) : a(a), b(b){} };

int main(){
	int tc; cin >> tc;
	while(tc--){
		string str; cin >> str;
		frac left(0,1), mid(1,1), right(1,0), tmp;
		for(int i=0 ; str[i] ; i++){
			if(str[i]=='L'){
				tmp   = frac(left.a+mid.a, left.b+mid.b);
				right = frac(mid.a, mid.b);
				mid   = frac(tmp.a, tmp.b);
			}
			if(str[i]=='R'){
				tmp   = frac(right.a+mid.a, right.b+mid.b);
				left  = frac(mid.a, mid.b);
				mid   = frac(tmp.a, tmp.b);
			}
		}
		cout << tmp.a << "/" << tmp.b << endl;
	}
}