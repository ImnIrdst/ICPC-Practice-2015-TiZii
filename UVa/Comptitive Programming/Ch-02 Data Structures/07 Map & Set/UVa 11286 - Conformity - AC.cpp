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

int main(){
	int n; 
	while(cin >> n && n){
		map<string,int> mp; string str[5]; int Max=0,cnt=0;
		for(int i=0 ; i<n ; i++){
			for(int i=0 ; i<5 ; i++){
				cin >> str[i];
			}
			sort(str,str+5);
			for(int i=1 ; i<5 ; i++){
				str[0]+=str[i];
			}
			mp[str[0]]++;
			if(Max<mp[str[0]]){
				Max=mp[str[0]]; cnt=0;
			}
			if(Max==mp[str[0]]){
				cnt++;
			}
		}
		cout << cnt*Max << endl;
	}
	return 0;
}