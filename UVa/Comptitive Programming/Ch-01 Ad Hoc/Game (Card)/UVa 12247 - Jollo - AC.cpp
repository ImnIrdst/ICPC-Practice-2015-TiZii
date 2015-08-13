#include <iostream>
#include <algorithm>

using namespace std;

int s[3], b[2];

bool isDuplicate(int ans){
	for(int i=0 ; i<2 ; i++)
		if(b[i]==ans) return 1;
	for(int i=0 ; i<3 ; i++)
		if(s[i]==ans) return 1;
	return 0;
}

int main(){
	while(cin >> s[0] >> s[1] >> s[2] >> b[0] >> b[1] 
			&& (s[0] || s[1] || s[2] || b[0] || b[1])){
		sort(s,s+3); sort(b,b+2);
		int mark[3]={0}, cnt=0;
		for(int i=0 ; i<2 ; i++){
			for(int j=0 ; j<3 ; j++){
				if(s[j]>b[i] && !mark[j]){
					mark[j]=1; cnt++; break;
				}
			}
		}
		if(cnt==2){
			cout << -1 << endl; continue;
		}
		int ans = -1;
		for(int j=0 ; j<3 ; j++){
			if(s[j]>ans && !mark[j]) ans=s[j];
		}
		if(cnt==0) ans=1;
		while(isDuplicate(ans)) ans++;
		if(ans>52) cout << -1 << endl;
		else       cout << ans << endl;
	}
}