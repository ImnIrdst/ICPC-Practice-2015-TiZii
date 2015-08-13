//UVa 621 - Secret Research - AC.cpp
#include <iostream>
#include <string>

using namespace std;

int main(){
	int tc; cin >> tc;
	while(tc--){
		string str; cin >> str;
		if(str=="1" || str=="4" || str=="78") 
			cout << "+" << endl;
		else if(str.size()>1 && str.substr(str.length()-2,2)=="35") 
			cout << "-" << endl; 
		else if(str.size()>1 && str[0]=='9' && str[str.length()-1]=='4') 
			cout << "*" << endl; 
		else if(str.size()>2 && str.substr(0,3)=="190") 
			cout << "?" << endl;
	}
}