#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#define int64 unsigned long long

using namespace std;

int64 fact[21];

int64 permutCnt(string str){	
	sort(str.begin() , str.end());
	int64 fct=fact[str.size()];
	for(int i=0 ; i<str.size() ; i++){
		int same=0; char tmp=str[i];
		while(str[i]==tmp) i++,same++;
		fct/=fact[same];
	}
	return fct;
}

int main(){
	fact[0]=fact[1]=1; for(int i=2 ; i<=20 ; i++) fact[i]=fact[i-1]*i;

	int tc; cin >> tc;
	while(tc--){
		string str; int64 n; cin >> str >> n; string ans,state=str; n++;
		for(int i=0 ; i<str.length() ; i++){
			bool vis[26]={0};
			sort(state.begin(), state.end()); 
			for(int j=0 ; j<state.size() ; j++){
				if(vis[state[j]-'a']) continue; vis[state[j]-'a']=1;
				string tmp = state.substr(0,j) + state.substr(j+1);
				int64 cnt=permutCnt(tmp);
				if(n<=cnt){
					ans+=state[j]; state=tmp; break;
				}
				n-=cnt;
			}
		}
		cout << ans << endl;
	}
}

/*

2
abc
3
abcde
119


*/