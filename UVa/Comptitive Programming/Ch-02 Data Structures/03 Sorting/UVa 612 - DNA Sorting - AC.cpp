#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;


typedef pair<int,int   >  pii  ;
typedef vector< pii    > vpii  ;
typedef vector< string >  vcs  ;

int n, m;

int countInv(string& s){
	int ret=0;
	for(int i=0 ; i<n ; i++){
		for(int j=i+1 ; j<n ; j++){
			if(s[j]<s[i]) ret++;
		}
	}
	return ret;
}

int main(){
	string str; 
	int tc; cin >> tc;
	while(tc--){
		vpii vi; vcs vs; cin >> n >> m;
		for(int i=0 ; i<m ; i++){
			cin >> str; vs.push_back(str);
			vi.push_back(pii(countInv(str),i));
		}
		sort(vi.begin(), vi.end());
		for(int i=0 ; i<m ; i++){
			cout << vs[vi[i].second] << endl;
		}
		if(tc) cout << endl;
	}
}