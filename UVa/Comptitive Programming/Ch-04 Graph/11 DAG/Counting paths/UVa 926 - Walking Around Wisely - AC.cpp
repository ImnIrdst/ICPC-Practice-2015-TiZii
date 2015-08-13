#include <iostream>
#include <sstream>
#include <cstring>
#define INF (int)1e9
#define MAX (30+10)
#define int64 unsigned long long int

using namespace std;

int block[MAX][MAX][MAX][MAX]; int64 path_cnt[MAX][MAX], n, m;

int main(){
	int tc; cin >> tc;
	while(tc--){
		cin >> n; memset(block,0,sizeof block);
		int su,sv, eu, ev ; cin >> su >> sv >> eu >> ev >> m;
		char c; int u,v;
		for(int i=1; i<=m ; i++){
			cin >> u >> v >> c;
			if(c=='E') block[u][v][u+1][v]=block[u+1][v][u][v]=1;
			if(c=='W') block[u][v][u-1][v]=block[u-1][v][u][v]=1;
			if(c=='S') block[u][v][u][v-1]=block[u][v-1][u][v]=1;
			if(c=='N') block[u][v][u][v+1]=block[u][v+1][u][v]=1;
		}
		memset(path_cnt,0,sizeof path_cnt); path_cnt[su][sv]=1;
		for(int i=1 ; i<=n ; i++){
			for(int j=1 ; j<=n ; j++){
				if(i>1 && !block[i][j][i-1][j]) path_cnt[i][j]+=path_cnt[i-1][j];
				if(j>1 && !block[i][j][i][j-1]) path_cnt[i][j]+=path_cnt[i][j-1];
			}
		}
		// for(int i=1 ; i<=n ; i++){
		// 	for(int j=1 ; j<=n ; j++){
		// 		cout << path_cnt[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
		cout << path_cnt[eu][ev] << endl;
	}
}