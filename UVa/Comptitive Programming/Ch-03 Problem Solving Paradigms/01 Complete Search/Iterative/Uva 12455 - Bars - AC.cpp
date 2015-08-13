#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;

int main(){
	int tc; 
	cin >> tc;
	while( tc-- ){
		int n, len; 
		cin >> len >> n;
		
		vi bar;
		for(int i=0 ; i<n ; i++){
			int tmp; cin >> tmp; bar.push_back(tmp);
		}
		
		// Pick a Subset
		bool yes=0;
		for(int bit=0 ; bit<(1<<n) ; bit++){
			int sum=0;
			for(int i=0; i<n ; i++){
				if(bit&(1<<i)) sum += bar[i]; 
			}
			yes |= (sum==len);
		}
		if(yes==1) cout << "YES" << endl;
		if(yes==0) cout << "NO"  << endl;
	}
}
