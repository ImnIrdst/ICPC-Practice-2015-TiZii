#include <iostream>
#include <cstring>
#include <set>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int letter[100]; vector<string> dic; set<string> phrase;
int CharLimit, CharUsed, ans[2000+10]; string tmp, org;

void solve(int ansId, int dicId){
	if(CharLimit==CharUsed){
		cout << org << " =" ;
		for(int i=0 ; i<ansId ; i++){
			cout << " " << dic[ans[i]];
		}
		cout << endl; return;
	}
	for(int i=dicId,j ; i<dic.size() ; i++){
		if(phrase.count(dic[i])) continue;
		
		int WordFound = true;
		for(j=0 ; j<dic[i].size() ; j++){
			letter[dic[i][j]]--; CharUsed++;
			if(letter[dic[i][j]]<0){
				while(j>=0){
					letter[dic[i][j]]++; j--; CharUsed--;
				}
				WordFound = false; break;
			}
		}
		if(WordFound){
			ans[ansId]=i; solve(ansId+1, i+1);
			while(j>0){
				letter[dic[i][j-1]]++; j--; CharUsed--;
			}
		}
	}
}

int main(){
	while(getline(cin, tmp) && tmp[0]!='#'){
		dic.push_back(tmp);
	}
	sort(dic.begin(), dic.end());
	while(getline(cin, org) && org[0]!='#'){
		stringstream sstr(org); phrase.clear();
		while(sstr >> tmp){
			phrase.insert(tmp);
		}
		
		memset(letter,0,sizeof letter); CharLimit=0;
		for(int i=0 ; i<org.length() ; i++){
			if(org[i]!=' ') letter[org[i]]++, CharLimit++;
		}
		solve(0,0);
	}
}

// #include <iostream>
// #include <string>
// #include <sstream>
// #include <set>
// #include <algorithm>
// #include <vector>

// using namespace std;


// set<string> dic, dic1, dic2, dic3;
// set<string> ans; set<int> vis;

// void filldic3(string &tmp){
// 	stringstream sstr(tmp);
// 	string tt; dic3.clear(); vis.clear();
// 	while(sstr >> tt){
// 		dic3.insert(tt); dic.erase(tt);
// 	}
// }

// string sortWords(string str){
// 	stringstream sstr(str);
// 	string tt; vector<string> vs;
// 	while(sstr >> tt){
// 		vs.push_back(tt);
// 	}
// 	sort(vs.begin(), vs.end()); string ret="";
// 	for(int i=0 ; i<vs.size() ; i++){
// 		ret += ' ' + vs[i]; //vis.insert(vs[i]);
// 	}
// 	return ret;
// }

// int ansPrefix(string& str){
// 	set<string>::iterator it; int len;
// 	for(len=0 ; len<str.length() && str[len]!=0 ; len++) ;
// 	for(it=ans.begin() ; it!=ans.end() ; it++){
// 		if(str.substr(0,len)==it->substr(0,len)) return true;
// 	}
// 	return false;
// }


// string str, tmp, org; int charslimit=0;
// void backtrack(int id, int lastspace, int bitset, int chars){
// 	//if(vis.count(bitset)) return; vis.insert(bitset);
// 	//if(ansPrefix(str)) return;
// 	if(chars==charslimit){
// 		if(dic.count(str.substr(lastspace, id-lastspace)) 
// 			&& !dic3.count(str.substr(lastspace, id-lastspace))
// 			&& !ans.count(sortWords(str.substr(0,id)))){
// 				string preprocess = sortWords(str.substr(0,id));
// 				ans.insert(preprocess);
// 				cout << org << " =" << preprocess << endl;
// 		}
// 		return;
// 	}
// 	if(id==20) return;
// 	for(int i=0 ; i<tmp.length() ; i++){
// 		if(bitset&(1<<i)) continue;
// 		//if(ansPrefix(str)) continue;
// 		str[id]=tmp[i]; bitset|=(1<<i);
// 		if(str[id]==' '){
// 			//if(bitset&(1<<22)) continue;
// 			if(dic.count(str.substr(lastspace, id-lastspace))
// 				&& !dic3.count(str.substr(lastspace, id-lastspace))
// 				/*&& !vis.count(str.substr(lastspace, id-lastspace))*/){
					 
// 					//vis.insert(str.substr(lastspace, id-lastspace));
// 					backtrack(id+1,id+1,bitset,chars);
// 			}
// 			i=tmp.find_last_of(' ');
// 		}
// 		else{
// 			if(dic2.count(str.substr(lastspace, id-lastspace)+tmp[i])
// 				/*&& !vis.count(str.substr(lastspace, id-lastspace)+tmp[i])*/){
// 				//vis.insert(str.substr(lastspace, id-lastspace)+tmp[i]);
// 				backtrack(id+1,lastspace,bitset,chars+1);
// 			}
// 		}
// 		str[id]=0; bitset&=~(1<<i);
// 	}
// 	//bitset|=(1<<22);
	
// }

// int main(){
// 	str.assign(30,0);
// 	while(cin >> tmp && tmp[0]!='#'){
// 		dic1.insert(tmp);
// 		for(int i=0 ; i<tmp.length()+1 ; i++){
// 			dic2.insert(tmp.substr(0,i));
// 		}
// 	}
// 	cin.ignore();
// 	while(getline(cin, tmp) && tmp[0]!='#'){
// 		dic = dic1;
// 		org = tmp; filldic3(tmp); charslimit=0;
// 		for(int i=0 ; i<tmp.length() ; i++){
// 			if(tmp[i]!=' ') charslimit++;
// 		}
// 		while(tmp.length()<30) tmp+=' ';
// 		sort(tmp.begin(),tmp.end());
// 		backtrack(0,0,0,0);
// 	}
// }