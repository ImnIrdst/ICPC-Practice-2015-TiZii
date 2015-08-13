#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <map>

using namespace std;

typedef vector< int > vi;
typedef vector< vi  > vii;

const int INF = 1e9;

vii adj; vi vis; map<string,int> mp;

int main(){
	cout << "SHIPPING ROUTES OUTPUT" << endl << endl;
	int tc , cs=1; cin >> tc;
	while(tc--){
		int n, m, q; cin >> n >> m >> q;

		string str; adj.assign(n,vi(n,INF));
		mp.clear(); vis.assign(n,0); 
		for(int i=0 ; i<n ; i++){
			cin >> str; mp[str]=i;
			adj[i][i]=0;
		}

		string s1, s2;
		for(int i=0 ; i<m ; i++){
			cin >> s1 >> s2; adj[mp[s1]][mp[s2]]=adj[mp[s2]][mp[s1]]=1;
		}
		for(int k=0 ; k<n ; k++){
			for(int i=0 ; i<n ; i++){
				for(int j=0 ; j<n ; j++){
					adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
				}
			}
		}
		cout << "DATA SET  " << cs++ << endl << endl;
		while(q--){
			int c; cin >> c >> s1 >> s2;
			if(adj[mp[s1]][mp[s2]]==INF) cout << "NO SHIPMENT POSSIBLE" << endl;
			if(adj[mp[s1]][mp[s2]]!=INF) cout << "$" << 100*c*adj[mp[s1]][mp[s2]] << endl;
		}
		cout << endl;
	}
	cout << "END OF OUTPUT" << endl;
}