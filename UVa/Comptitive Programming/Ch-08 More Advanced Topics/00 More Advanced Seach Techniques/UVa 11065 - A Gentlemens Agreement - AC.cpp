#include <iostream>
#include <algorithm>

using namespace std;

const int Max = 60+10;

typedef long long int64;

int64 adj[Max]; int n, m, ans1, ans2;

void solve(int ii, int64 bit, int cnt){
	if(bit==(1LL<<n)-1) 
		ans1++, ans2=max(ans2,cnt);
	for(int i=ii ; i<n ; i++){
		if(!(bit & (1LL<<i))) 
			solve(i+1,bit|adj[i], cnt+1);
	}
	
}

int main(){
	int tc;
	cin >> tc;
	while( tc-- ){
		cin >> n >> m; ans1=ans2=0;
		for(int i=0 ; i<n ; i++)
			adj[i]=(1LL<<i);
		
		int u, v;
		for(int i=0 ; i<m ; i++){
			cin >> u >> v; adj[u]|=(1LL<<v), adj[v]|=(1LL<<u);
		}
		solve(0,0LL,0);
		cout << ans1 << endl;
		cout << ans2 << endl;
	}
}