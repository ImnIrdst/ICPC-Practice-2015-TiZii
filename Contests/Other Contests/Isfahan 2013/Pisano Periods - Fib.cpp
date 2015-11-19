#include <iostream>
#include <fstream>

using namespace std;

int fib(int m){
	if(m==2) return 3;
	int a=1,b=1,i;
	for(i=2 ; i<m*m ; i++){
		int t=a;
		a=b%m;
		b=(b+t)%m;
		//cout << a << " ";
		if((a==0 || a==1)&& b==1 ) break;
	}
	return i;
}

int main(){
	ofstream fout("out.txt");
	int tc; cin >> tc;
	while(tc--){
		int n,m; cin >> n >> m;
		fout << n << " " << fib(m) << endl;	
	}
}