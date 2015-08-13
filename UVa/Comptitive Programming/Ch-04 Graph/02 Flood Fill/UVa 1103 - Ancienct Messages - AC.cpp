#include <iostream>
#include <cstring>

using namespace std;

const int Max = 5*1e4 + 10;

int m[Max], vis[Max], n;

int Count(int u, int color){
	vis[u]=color;
	int v = m[u];
	if( vis[v]!=color ) return 1 + Count(v, color);
	else return 0;
}

int main(){
	int tc;
	int cs=1;
	cin >> tc;
	while( tc-- ){
		cin >> n; int u, v;
		memset(vis,0,sizeof vis);
		for(int i=0 ; i<n ; i++){
			cin >> u >> v; m[u-1]=v-1;
		}

		int Ans=0, Max=-1, Cnt;
		for(int u=0 ; u<n ; u++){
			if(!vis[u]) Cnt = Count(u, u+1);
			if(Max < Cnt) Ans = u, Max=Cnt;
		}

		cout << "Case " << cs++ << ": " << Ans+1 << endl;
	}
}