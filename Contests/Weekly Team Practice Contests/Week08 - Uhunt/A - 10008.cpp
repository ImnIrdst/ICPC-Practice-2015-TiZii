#include <iostream>
#include <cctype>
#include <algorithm>
#include <string>

using namespace std;

typedef pair<int,int> pii;

bool cmp(pii a, pii b){
	return (a.first!=b.first ? a.first>b.first : a.second<b.second );
}

int main(){
	int tc; 
	cin >> tc;
	cin.ignore();
	string str, line; 
	while( tc-- ){
		getline(cin, line); str+=line;
	}
	int freq[256]={0};
	
	for(int i=0 ; i<str.length() ; i++){
		freq[toupper(str[i])]++;
	}
	pii ans[30];
	for(int i='A', j=0 ; i<='Z' ; i++, j++){
		ans[j]=pii(freq[i],i);
	}
	int n = 'Z'-'A'+1;
	sort(ans, ans+n, cmp);
	for(int i=0 ; i<n ; i++){
		if(ans[i].first)
			cout << char(ans[i].second) << " " << ans[i].first << endl;
	}
}