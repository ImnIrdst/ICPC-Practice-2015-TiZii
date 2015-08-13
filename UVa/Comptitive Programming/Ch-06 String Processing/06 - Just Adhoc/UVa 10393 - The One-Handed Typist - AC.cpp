#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <set>
#define int64 unsigned long long

using namespace std;

bool CantUse[11]; map<char,int> mp;

bool check(string& str){
	for(int i=0 ; i<str.size() ; i++){	
		if(CantUse[mp[str[i]]]==1){
			//printf("%s, %c : %d\n",str.c_str(), str[i], mp[str[i]] );
			return false;
		}
	}
	return true;
}

int main(){
	mp['q']=1; mp['a']=1; mp['z']=1;
	mp['w']=2; mp['s']=2; mp['x']=2;
	mp['e']=3; mp['d']=3; mp['c']=3;
	mp['r']=4; mp['f']=4; mp['v']=4;
	mp['t']=4; mp['g']=4; mp['b']=4;
	mp[' ']=5; mp[' ']=6; mp['y']=7;//space is for two fingers
	mp['h']=7; mp['n']=7; mp['u']=7;
	mp['j']=7; mp['m']=7; mp['i']=8;
	mp['k']=8; mp[',']=8; mp['o']=9;
	mp['l']=9; mp['.']=9; mp['p']=10;
	mp[';']=10; mp['/']=10;
	int f,n;
	while(cin >> f >> n){
		memset(CantUse,0,sizeof CantUse);
		set<string> ans; int tmp;
		for(int i=0 ; i<f ; i++ ){
			cin >> tmp; CantUse[tmp]=1;
		}
		CantUse[6] = CantUse[5] & CantUse[6];
		string str; cin.ignore();
		for(int i=0 ; i<n ; i++){
			cin >> str; 
			if(ans.size()!=0 && str.size()>ans.begin()->size() && check(str)){
				ans.clear();
			}
			if((ans.size()==0 || str.size()==ans.begin()->size()) && check(str)){
				ans.insert(str);
			}
			// cout << ans.size() << endl;
			// set<string>::iterator itr;
			// for(itr=ans.begin() ; itr!=ans.end() ; itr++){
			// 	cout << *itr << endl;
			// }
		}
		cout << ans.size() << endl;
		set<string>::iterator itr;
		for(itr=ans.begin() ; itr!=ans.end() ; itr++){
			cout << *itr << endl;
		}
	}
	

}
