#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct pii{
	int v, w; pii(int v=0,int w=0):v(v), w(w){}
};

int main(){
	int a, b, n, cs=1;
	while(cin >> a >> b >> n && (a+b+n)){
		vector<int> btn(n), vis(10000,0);
		for(int i=0 ; i<n ; i++){
			cin >> btn[i];
		}

		int ans=-1;
		queue<pii> q;
		q.push(pii(a,0));
		while(!q.empty()){
			pii u=q.front(); q.pop();
			
			if( u.v == b ){
				ans = u.w; break;
			}

			for(int i=0 ; i<n ; i++){
				pii v((btn[i]+u.v)%10000, u.w+1);
				if( vis[v.v] ) continue; 
				vis[v.v]=true; q.push(v);
			}
		}
		cout << "Case " << cs++ << ": ";
		if(ans != -1) cout << ans << endl;
		if(ans == -1) cout << "Permanently Locked" << endl;
		
	}
}