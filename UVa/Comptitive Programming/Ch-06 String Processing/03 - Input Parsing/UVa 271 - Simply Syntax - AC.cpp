#include <iostream>
#include <string>

using namespace std;

// S -> p-z | NS | (C-I)SS

string inp; int i; bool yes;

void S(){
	if (i >= inp.size()) yes = false;
	else if ('p' <= inp[i] && inp[i] <= 'z') i++;
	else if (inp[i] == 'N') i++, S();
	else i++, S(), S();
}

int main(){
	while (cin >> inp){
		yes = true; i = 0; S();
		if (i < inp.length()) yes = false;
		if (yes == true) cout << "YES" << endl;
		if (yes != true) cout << "NO"  << endl;
	}
}