#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int main(){
	int n, cs=1;
	while(cin >> n && n){
		vector<int> bag(n);
		for(int i=0 ; i<n ; i++){
			cin >> bag[i];
		}
		sort(bag.begin(), bag.end());

		int same=0;
		for(int i=0 ; i<n ; ){
			int cnt; for(cnt=1 ; i+cnt<n ; cnt++){
				if(bag[cnt+i]!=bag[i]) break;
			}
			same=max(same, cnt); i+=cnt;
		}

		vector<vector<int> > ans(same);
		for(int i=0 ; i<n ; i++){
			ans[i%same].push_back(bag[i]);
		}
		if(cs==1) cout << endl; cs++;

		cout << same << endl;
		for(int i=0 ; i<same ; i++){
			for(int j=0 ; j<ans[i].size() ; j++){
				cout << (j ? " " : "") << ans[i][j];
			}
			cout << endl;
		}
	}
}