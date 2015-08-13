#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int gcd(int a, int b){
	if(a==0) return 0;
	return (b==0 ? a : gcd(b,a%b));
}

int len(int x){
	if(x==0) return 0;
	stringstream sstr; sstr << x;
	string str; sstr >> str;
	return str.length();
}

struct Avg{// x(a/b), s -> sign
	int x, a, b, dash_len, total_len; char s;
	void calculate(int m, int n){
		x = m/n; a = abs(m%n); b = n; simplify();
		s = ((m%n)<0 ? '-' : '+');
		dash_len = max(len(a),len(b));
		total_len = (s=='+' ? 0 : 2) + len(abs(x)) + dash_len;
	}
	void simplify(){
		if(gcd(a,b)==0) 
			a=b=0;
		else{
			int ta = a/gcd(a,b);
			int tb = b/gcd(a,b);
			a = ta, b = tb;
		}
	}

};

void printch(int n, char ch){
	for(int i=0 ; i<n ; i++) cout << ch;
}

int main(){
	int n, cs=1;
	while(cin >> n && n){
		int sum=0, tmp;
		for(int i=0 ; i<n ; i++){
			cin >> tmp; sum+=tmp;
		}
		Avg avg; avg.calculate(sum, n);

		cout << "Case " << cs++ << ":" << endl;
		if(avg.a != 0) 
			printch(avg.total_len-(len(avg.a)),' '), cout << avg.a << endl;
		if(avg.x <  0) 
			cout << "- " << abs(avg.x), printch(avg.dash_len,'-'), cout << endl;
		if(avg.x >  0)
			cout <<  avg.x, printch(avg.dash_len,'-'), cout << endl;
		if(avg.x ==  0 && avg.s=='+' && avg.a!=0)
			printch(avg.dash_len,'-'), cout << endl;
		if(avg.x ==  0 && avg.s=='-')
			cout << "- ", printch(avg.dash_len,'-'), cout << endl;
		if(avg.a != 0)
			printch(avg.total_len-(len(avg.b)),' '), cout << avg.b << endl;
		if(avg.a==0 && avg.x==0)
			cout << 0 << endl;
	}
}

