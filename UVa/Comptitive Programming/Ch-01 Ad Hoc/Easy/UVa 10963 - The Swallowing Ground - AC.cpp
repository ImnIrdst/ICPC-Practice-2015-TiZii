#include <iostream>

using namespace std;

int main(){
	int tc; 
	cin >> tc;
	while( tc-- ){
		int n; cin >> n;
		int a, b, p=-1; bool yes=1;
		for(int i=0 ; i<n ; i++)  {
			cin >> b >> a; 
			if(p!=-1 && b-a != p) yes=0;
			p = b-a;
		}
		cout << (yes ? "yes" : "no") << endl;
		if(tc) cout << endl;
	}
}