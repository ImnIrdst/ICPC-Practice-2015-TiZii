#include <iostream>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

char table[5][5];

void find(char c, int& i, int& j){
	for(i=0 ; i<5 ; i++){
		for(j=0 ; j<5 ; j++){
			if(table[i][j]==c) return;
		}
	}
}

int main(){
	int tc;
	cin >> tc;
	cin.ignore();
	while( tc-- ){
		string key;
		set<char> st;
		getline(cin, key);
		for(char c='a' ; c<='z' ; c++)
			if( c != 'q' ) key+=c;

		int k=0; 
		for(int i=0 ; i<5 ; i++){
			for(int j=0 ; j<5 ; j++){
				while(st.count(key[k]) || key[k]==' ') k++;
				st.insert(key[k]); table[i][j]=key[k];
			}
		}

		string text;
		string ans="";
		getline(cin, text);
		for(int i=0 ; i<text.size() ; i++){
			string pair="";
			while( i<text.length() && text[i]==' ') i++;
			pair+=text[i]; i++;
			while( i<text.length() && text[i]==' ') i++;
			if(i < text.length()) pair+=text[i];
			if(pair[0]==pair[1] || pair.size()==1) pair[1]='x', i--;
			int i1, j1, i2, j2; find(pair[0],i1,j1), find(pair[1], i2, j2);
			if(i1==i2)      
				ans+=table[i1][(j1+1)%5], ans+=table[i2][(j2+1)%5];
			else if(j1==j2) 
				ans+=table[(i1+1)%5][j1], ans+=table[(i2+1)%5][j2];
			else            
				ans+=table[i1][j2], ans+=table[i2][j1];
		}
		transform(ans.begin(), ans.end(), ans.begin(), ::toupper);
		cout << ans << endl;
	}
}