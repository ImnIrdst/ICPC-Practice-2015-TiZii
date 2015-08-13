#include <iostream>
#include <stdio.h>
#include <vector>
#include <sstream>

using namespace std;

int main(){
	stringstream sstr; string str; int n;
	while(getline(cin,str)){
		
		sstr.clear(); sstr << str; vector<int> coef;
		while(sstr >> n) coef.push_back(n);
		
		getline(cin,str); 
		sstr.clear(); sstr << str;

		bool first=true;
		while(sstr >> n){
			int ans=0;
			for(int i=coef.size()-1,j=1 ; i>=0 ; i--, j*=n){
				ans+=coef[i]*j;
			}
			if(!first) cout << " "; first=false;
			cout << ans;
		}
		cout << endl;
	}
}
