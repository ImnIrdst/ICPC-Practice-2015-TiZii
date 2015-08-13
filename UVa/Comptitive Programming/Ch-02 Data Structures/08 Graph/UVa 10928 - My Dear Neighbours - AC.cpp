#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <vector>
#define INF (int)1e9
#define int64 long long

using namespace std;

vector<int> ans; string str; stringstream sstr;

int main(){
	int tc; cin >> tc;
	while(tc--){
		int n,tmp,Min=INF; ans.clear(); cin >> n; cin.ignore();
		for(int i=0 ; i<n ; i++){
			getline(cin,str); sstr.clear(); sstr << str;
			int cnt=0;
			while(sstr >> tmp) cnt++;
			if(cnt<Min){ Min=cnt; ans.clear();}
			if(cnt==Min) ans.push_back(i+1);
		}
		for(int i=0 ; i<ans.size() ; i++){
			if(i!=0) cout << " ";
			cout << ans[i];
		}
		cout << endl;
	}
	return 0;
}
