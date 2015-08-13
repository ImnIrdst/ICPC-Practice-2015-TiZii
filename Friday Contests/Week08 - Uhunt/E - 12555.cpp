#include <iostream>
#include <string>
#include <cctype>
#include <sstream>

using namespace std;

string Int2Str(int n){
	string ret; stringstream sstr;
	sstr << n; sstr >> ret; return ret;
}

int Str2Int(string str){
	if(str=="") return 0;
	int ret; stringstream sstr;
	sstr << str; sstr >> ret; return ret;
}

int main(){
	int tc;
	int cs=1;
	cin >> tc; 
	cin.ignore();
	while( tc-- ){
		string str; getline(cin, str);
		double a, b, i=0; string n1, n2;
		while(i<str.length() && isdigit(str[i])){
			n1+=str[i]; i++;
		}
		while(i<str.length() && !isdigit(str[i])) i++;
		while(i<str.length() &&  isdigit(str[i])){
			n2+=str[i]; i++;
		}
		a = Str2Int(n1), b = Str2Int(n2);
		cout << "Case " << cs++ << ": ";
		cout << a*0.5 + b *0.05 << endl;
	}
	
}