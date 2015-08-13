#include <iostream>
#include <cstring>
#include <sstream>
#include <string>
#include <set>

using namespace std;

const int offset = 3000;

int vis[30+10][30+10][3000*2+10], n; 
int num[30+10], sign[30+10], use[3000*2+10];

void solve(int id, int open, int val){
	if( id>=n ){ use[val+offset]=true; return; };
	if( vis[id][open][val+offset] ) return; 
	vis[id][open][val+offset]=true;

	int nval = val + (num[id]*sign[id]*(open%2 ? -1 : 1));

	if(sign[id] == -1) solve(id+1, open+1, nval);
	if(open > 0      ) solve(id+1, open-1, nval);
	solve(id+1, open, nval);
}

int main(){
	string line;
	while(getline(cin, line)){
		stringstream sstr(line); //ans.clear();
		char c; n=1; sstr >> num[0]; sign[0] = +1;
		while(sstr >> c >> num[n]) 
			sign[n] = (c =='-' ? -1 : +1), n++;
		memset(use, false, sizeof use);
		memset(vis, false, sizeof vis);
		solve(0,0,0); 
		
		int ans=0;
		for(int i=0 ; i<3000*2+10 ; i++) 
			if(use[i]==true) ans++;
		cout << ans << endl;
	}
}dd