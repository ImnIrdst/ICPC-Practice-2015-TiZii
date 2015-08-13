#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main(){
	int n; string mp[13+10];
	while(cin >> n && n){ cin.ignore();
		int len[13+10]={0}, Max=-1;
		for(int i=0 ; i<n ; i++){
			getline(cin, mp[i]);
			for(int j=0 ; j<25 ; j++){
				len[i] += (mp[i][j]=='X');
				Max = max(Max, len[i]);
			}
		}
		int ans=0;
		for(int i=0 ; i<n ; i++){
			ans += (Max-len[i]);
		}
		cout << ans << endl;
	}
}