#include <iostream>
#include <stdio.h>
#include <vector>
#include <sstream>

using namespace std;

int main(){
	stringstream sstr; string str; int n,x;
	while(cin >> x){
		cin.ignore(); vector<int> coef;
		getline(cin, str); sstr.clear(); sstr << str;
		while(sstr >> n) coef.push_back(n);
		
		int ans=0;
		for(int i=coef.size()-2,j=1,k=1 ; i>=0 ; i--, j*=x,k++){
			ans+=coef[i]*j*k;
		}
		cout << ans << endl;
	}
}
