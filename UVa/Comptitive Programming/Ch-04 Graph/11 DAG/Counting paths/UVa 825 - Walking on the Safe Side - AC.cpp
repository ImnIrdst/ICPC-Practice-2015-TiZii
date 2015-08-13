#include <iostream>
#include <sstream>
#include <cstring>
#define INF (int)1e9
#define MAX (1000+10)


using namespace std;

int a[MAX][MAX], path_cnt[MAX][MAX], n, m;

int main(){
	string str; stringstream sstr; int tc; cin >> tc;
	while(tc--){
		cin >> n >> m; cin.ignore(); memset(a,0,sizeof a);
		int u,v;
		for(int i=1; i<=n ; i++){
			getline(cin,str); sstr.clear(); sstr << str;
			sstr >> u; while(sstr >> v) a[u][v]=1;
		}
		memset(path_cnt,0,sizeof path_cnt); path_cnt[1][1]=1;
		for(int i=1 ; i<=n ; i++){
			for(int j=1 ; j<=m ; j++){
				if(a[i][j]!=1){
					if(i>1) path_cnt[i][j]+=path_cnt[i-1][j];
					if(j>1) path_cnt[i][j]+=path_cnt[i][j-1];
				}
			}
		}
		cout << path_cnt[n][m] << endl;
		if(tc) cout << endl;
	}
}