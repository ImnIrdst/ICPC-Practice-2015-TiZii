#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <math.h>
#include<vector>
#include <fstream>
#include <map>
#include <sstream>
//#define cin fin
#define INF (int) 1e6

using namespace std;

int n; vector<int> v;

void prmut(string set,string num){
	if(num.length()==5){
		stringstream sin; sin << num;
		int x; sin >> x;
		v.push_back(x);
		return;
	}
	string tmp;
	for(int i=0 ; i<set.length() ; i++){
		tmp=set; tmp.replace(i,1,"");
		prmut(tmp,num+set[i]);
	}
}

bool check(int x){
	if(x<9999 && (x/n)<9999)
		return 0;
	if(x>98765)
		return 0;
	stringstream sin;
	sin << x;
	string s; sin >> s; 
	sin.clear();
	if(s.size()==4) s="0"+s;
	sin << x/n;
	string tmp; sin >> tmp; 
	if(tmp.size()==4) s=s+"0"+tmp;
	else s+=tmp;
	for(int i=0 ; i<s.length() ; i++){
		for(int j=i+1 ; j<s.length() ; j++){
			if(s[i]==s[j]) return 0;
		}
	}
	return 1;
}

int main(){
	//ifstream fin("in.txt");
	prmut("0123456789","");
	int tc=1;
	while(cin >> n && n){
		int cnt=0;
		if(tc++>1) cout << endl;
		for(int i=0 ; i<v.size() ; i++){
			if(check(v[i]*n)){
				printf("%.5d / %.5d = %d\n", v[i]*n , v[i] , n);
				cnt++;
			}
		}
		if(cnt<1) printf("There are no solutions for %d.\n",n);
	}
	return 0;
}