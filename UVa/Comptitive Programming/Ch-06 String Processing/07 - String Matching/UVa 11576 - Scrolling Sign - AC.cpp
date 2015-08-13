#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int b[MAX];

int main(){
	int tc; cin >> tc;
	while(tc--){
		int k,w; cin >> k >> w;
		string str,ans="",prev="";
		while(w--){
			cin >> str; 
			if(str==prev) continue; prev=str;
			if(ans.size()==0){ans+=str; continue;}
			int pos = ans.size()-k;
			string tmp; int nPos=0;
			for(int i=pos i<ans.size() ; i++){
				tmp=ans.substr(i);
				if(str.find(tmp)==0) break;
				nPos++;
			}
			for(int i=k-nPos; i<k ; i++) ans+=str[i];
		}
		cout << ans.size() << endl;
	}
}
