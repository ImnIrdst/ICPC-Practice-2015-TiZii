#include <iostream>
#include <queue>
#include <string>

using namespace std;

int l,m,tmp; string str;

int main(){
	int tc; cin >> tc;
	while(tc--){
		cin >> l >> m; l*=100;
		queue<int> qleft, qright;
		for(int i=0 ; i<m ; i++){
			cin >> tmp >> str;
			if(str=="left") qleft.push(tmp);
			if(str=="right") qright.push(tmp);
		}
		int ans=0, len;
		while(!qleft.empty() || !qright.empty()){
			len=0; 
			while(!qleft.empty() && len+qleft.front()<=l){
				len+=qleft.front(); qleft.pop();
			}
			ans++;
			if(qleft.empty() && qright.empty()) break;
			len=0; 
			while(!qright.empty() && len+qright.front()<=l){
				len+=qright.front(); qright.pop();
			}
			ans++;
		}
		cout << ans << endl;
	}
}
