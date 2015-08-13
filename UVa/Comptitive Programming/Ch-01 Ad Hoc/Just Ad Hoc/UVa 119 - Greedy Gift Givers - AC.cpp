#include <iostream>
#include <cstdio>
#include <string>
#include <map>

using namespace std;

int main(){
	int n, first=1;
	while(cin >> n){
		string name, names[10+5]; 
		map<string, int> mp;
		for(int i=0 ; i<n ; i++){
			cin >> names[i]; mp[names[i]]=i;
		}
		int money[10+5]={0}, m, amt;
		for(int i=0 ; i<n ; i++){
			cin >> name >> amt >> m; 
			if(m==0) continue;
			money[mp[name]]-=amt;
			money[mp[name]]+=amt%m;
			for(int i=0 ; i<m ; i++){
				cin >> name;
				money[mp[name]]+=amt/m;
			}
		}
		if(!first) cout << endl; first=0;
		for(int i=0 ; i<n ; i++){
			cout << names[i] << " " << money[i] << endl;
		}
	}
}