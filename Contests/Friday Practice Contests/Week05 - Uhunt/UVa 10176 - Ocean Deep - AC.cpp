#include <iostream>
#include <string>

using namespace std;

int main(){
	string str, tmp;
	while(cin >> str){
		while(str[str.length()-1]!='#'){
			cin >> tmp; str+=tmp;
		}

		int mod=0;
		for(int i=0, j=1 ; i<str.length()-1 ; i++, j*=2, j%=131071){
			mod+=j*(str[i]-'0'); mod%=131071;
		}
		
		if(mod==0) cout << "YES" << endl;
		else	   cout << "NO" << endl;
	}
}