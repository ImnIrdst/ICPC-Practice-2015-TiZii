#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <vector>
#define INF (int)1e9
#define int64 long long

using namespace std;

struct p{
	string name; int price;
	p(){}
	p(string n, int pr){name=n; price=pr;}
};

int cmp(p a, p b){
	if(a.price<b.price) return 1;
	if(a.price>b.price) return 0;
	string nameA=a.name, nameB=b.name;

	transform(nameA.begin(), nameA.end(), nameA.begin(), ::toupper);
	transform(nameB.begin(), nameB.end(), nameB.begin(), ::toupper);
	return nameA<nameB;
}

int main(){
	int tc; cin >> tc;
	while(tc--){
		map<string,int> mp; vector<p> v;
		string str; cin.ignore(); getline(cin,str);
		transform(str.begin(), str.end(), str.begin(), ::toupper);
		cout << str << endl;
		int m,n,b,price; cin >> m >> n >> b;
		for(int i=0 ; i<m ; i++){
			cin >> str >> price;
			mp[str]=price;
		}
		int num; string name;
		for(int i=0 ; i<n ; i++){
			cin.ignore(); getline(cin,name); cin >> m; price=0;
			while(m--){
				cin >> str >> num;
				price+=num*mp[str];
			}
			if(price<=b) v.push_back(p(name,price));
		}
		sort(v.begin(), v.end(), cmp);
		for(int i=0 ; i<v.size() ; i++){
			cout << v[i].name << endl;
		}
		if(v.size()==0) cout << "Too expensive!" << endl;
		cout << endl;
	}
	return 0;
}
