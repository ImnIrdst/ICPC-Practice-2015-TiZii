#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#define INF (int)1e9
#define int64 long long

using namespace std;

int main(){
	string str1; int t=1;
	while(getline(cin, str1) && str!="#"){
		cout << "Case " << t++;
		if(str1=="HELLO") cout << ": ENGLISH" << endl;
		else if(str1=="HOLA") cout << ": SPANISH" << endl;
		else if(str1=="HALLO") cout << ": GERMAN" << endl;
		else if(str1=="BONJOUR") cout << ": FRENCH" << endl;
		else if(str1=="CIAO") cout << ": ITALIAN" << endl;
		else if(str1=="ZDRAVSTVUJTE") cout << ": RUSSIAN" << endl;
		else cout << "UNKNOWN" << endl;
	}
	return 0;
}