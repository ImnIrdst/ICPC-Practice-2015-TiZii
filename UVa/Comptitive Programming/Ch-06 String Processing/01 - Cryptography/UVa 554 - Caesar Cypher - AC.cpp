#include <iostream>
#include <sstream>
#include <set>

using namespace std;

set<string> dic;

int CntinDic(string str){
	stringstream sstr(str);
	int cnt = 0;
	while(sstr >> str)
		if(dic.count(str)) cnt++;
	return cnt;
}

int main(){
	string word;
	while(cin >> word && word!="#"){
		dic.insert(word);
	}

	int mx=-1;
	string ans;
	string line;

	cin.ignore();
	getline(cin, line);

	string decrypted=""; 
	for(int k=0 ; k<=26 ; k++){
		for(int i=0 ; i<line.length() ; i++){
			int id=0; 
			if(line[i]!=' ') 
				id+=line[i]-'A'+1;
			id = (id+k)%27;
			decrypted += (id==0?' ':'A'+id-1) ;
		}
		int cnt = CntinDic(decrypted);
		if(cnt > mx) mx=cnt, ans=decrypted;
		decrypted="";
	}

	int lim=60;
	stringstream sstr(ans);
	while(sstr >> word){
		if(lim-(int)word.length()<=0) cout <<'\n', lim=60;
		cout << (lim==60?"":" ") << word, lim-=(word.length()+1);
	}
	if(lim!=60) cout << endl;
}