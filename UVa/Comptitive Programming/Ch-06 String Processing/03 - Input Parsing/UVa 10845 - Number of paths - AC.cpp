#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef vector<string> vs;

int id; vs code;

int Count(){
	int ret = 1; id++;
	while(id < code.size() && code[id][0]!='E'){
		if(code[id][0]=='I') ret *= (Count() + Count()); id++;
	}
	return ret;
}

int main(){
	int tc;
	cin >> tc;
	while( tc-- ){
		string tmp; id=-1; code.clear();
		while(cin >> tmp && tmp!="ENDPROGRAM"){
			if(tmp!="S") code.push_back(tmp);
		}
		//code.push_back(tmp);
		cout << Count() << endl;
	}
}