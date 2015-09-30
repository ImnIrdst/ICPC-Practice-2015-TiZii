#include <iostream>
#include <math.h>
#include <algorithm>
#include <fstream>
#include <string>
#include <map>
#define int8 long long
//#define cin fin
#define INF (int8)1e9

using namespace std;

int8 m=131071;

int8 poww(int8 b, int8 p){
	if(p==1) return b;
	if(p==0) return 1;
	int8 ans=poww(b,p/2)%m;
	if(p%2==0) return (ans*ans)%m;
	ans*=poww(b,p/2+1);
	return ans%m;
}

int main(){
	//ifstream fin("in.txt");
	 string tmp;
	while(cin >> tmp){
		string bit=""; bit+=tmp;
		while(tmp.length()!=0 && tmp[tmp.length()-1]!='#'){
			cin >> tmp;
			bit+=tmp;
		}
		int8 ans=0;
		for(int8 i=bit.length()-2, j=0 ; i>=0 ; i--, j++){
			if(bit[i]=='1'){
				ans+=poww(2,j); ans=ans%m;
			}
		}
		cout << (ans==0 ? "YES" : "NO") << endl;
	}
	return 0;
}