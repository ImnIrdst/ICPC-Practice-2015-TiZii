#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#define INF (int)1e9
#define int64 long long

using namespace std;

char a[]="BCG";
int bin[3][3];
map<char,int> mp;

struct p{
	string name;
	int ans;
};

p solve(string s){
	if(s.length()==3){
		p ans; ans.ans=0; ans.name=s;
		for(int i=0 ; i<3 ; i++){
			int t=mp[s[i]];
			for(int j=0 ; j<3 ; j++){
				ans.ans+=bin[j][t];
			}
			ans.ans-=bin[i][t];
		}
		return ans;
	}
	p ans,sol; ans.ans=INF;
	for(int i=0 ; i<3 ; i++){
		if(s.find(a[i])==-1){
			sol=solve(s+a[i]);
			if(ans.ans>sol.ans)
				ans=sol;
		}
	}
	return ans;
}

int main(){
	mp['B']=0; mp['G']=1; mp['C']=2;
	while(cin >> bin[0][0]){
		for(int i=1 ; i<3 ; i++) cin >> bin[0][i];
		for(int i=0 ; i<3 ; i++) cin >> bin[1][i];
		for(int i=0 ; i<3 ; i++) cin >> bin[2][i];
		p sl=solve("");
		cout << sl.name << " " << sl.ans << endl;
	}
	return 0;
}