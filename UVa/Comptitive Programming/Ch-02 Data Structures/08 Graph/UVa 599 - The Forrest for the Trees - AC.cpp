#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct pst{ string str, key; };

bool cmp(pst a, pst b){ return a.str<b.str; }

int main(){
	pst inp; vector<pst> dic;
	while(cin >> inp.str && inp.str!="XXXXXX"){
		inp.key = inp.str; 
		sort(inp.key.begin(), inp.key.end());
		dic.push_back(inp);
	}
	string key; sort(dic.begin(), dic.end(), cmp);
	while(cin >> key && key!="XXXXXX"){
		sort(key.begin(), key.end()); bool found=0;
		for(int i=0 ; i<dic.size() ; i++){
			if(dic[i].key == key){
				cout << dic[i].str << endl; found=1;
			}
		}
		if(!found) cout << "NOT A VALID WORD" << endl;
		cout << "******" << endl;
	}

}