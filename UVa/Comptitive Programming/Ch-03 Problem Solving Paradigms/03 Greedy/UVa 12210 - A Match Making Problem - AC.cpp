#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	int b, s, cs=1;
	while( cin >> b >> s && (b||s)){
		vector<int> bach(b), spin(s);
		for(int i=0 ; i<b ; i++) cin >> bach[i]; 
		for(int i=0 ; i<s ; i++) cin >> spin[i];

		sort(bach.begin(), bach.end());
		cout << "Case " << cs++ << ": ";
		if(b>s) cout << b-s << " " <<  bach[0] << endl; 
		else	cout << 0 << endl;
	}
}