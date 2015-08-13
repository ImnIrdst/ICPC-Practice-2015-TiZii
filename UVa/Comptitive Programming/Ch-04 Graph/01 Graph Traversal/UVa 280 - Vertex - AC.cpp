#include <iostream>
#include <cstring>

using namespace std;

const int Max=100+10;

int adj[Max][Max];

int main(){
	int n;
	while(cin >> n && n){
		int m, u, v;
		memset(adj,0,sizeof adj);
		while ( cin >> u && u  ){ u--;
			while( cin >> v && v  ){ v--;
				adj[u][v]=1;
			}
		}

		for(int k=0 ; k<n ; k++){
			for(int i=0 ; i<n ; i++){
				for(int j=0 ; j<n ; j++){
					adj[i][j] = adj[i][j] | (adj[i][k]&adj[k][j]);
				}
			}
		}

		int q; 
		cin >> q;
		while(q--){
			cin >> u; u--; int cnt=0;
			for(int i=0 ; i<n ; i++)
				if(!adj[u][i]) cnt++;
			cout << cnt;
			for(int i=0 ; i<n ; i++)
				if(!adj[u][i]) cout << " " << i+1;
			cout << endl;
		}
	}
}