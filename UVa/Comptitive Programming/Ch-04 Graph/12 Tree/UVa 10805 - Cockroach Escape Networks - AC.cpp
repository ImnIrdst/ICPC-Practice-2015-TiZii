#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 25 + (25*24)/2 + 10;

int adj[MAX][MAX];

int main(){
	int tc;
	int cs=1;
	cin >> tc;
	while(tc--){
		int n, m; cin >> n >> m;
		for(int i=0 ; i<n+m ; i++){
			for(int j=0 ; j<n+m ; j++){
				adj[i][j] = 1e9;
			}
			adj[i][i]=0;
		}

		int edge=n, u, v; // consider edges as new nodes (split edges)
		for(int i=0 ; i<m ; i++, edge++){
			cin >> u >> v;
			adj[u][edge] = adj[edge][u] = 1;
			adj[v][edge] = adj[edge][v] = 1;
		}

		for(int k=0 ; k<n+m ; k++){
			for(int i=0 ; i<n+m ; i++){
				for(int j=0 ; j<n+m ; j++){
					adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
				}
			}
		}

		int ans = 1e9;
		for(int i=0 ; i<n+m ; i++){// Set as root (middle of tree)
			int fd1=0, fd2=0;	   // Furthest distances from root
			for(int j=0 ; j<n  ; j++){ 
				if(adj[i][j] > fd1) 
					fd1 = adj[i][j];
				if(fd2 < fd1) 
					swap(fd1, fd2);
			}
			ans = min(ans, (fd1+fd2)/2); // Real distance doubled
		}
		cout << "Case #" << cs++ << ":" << endl;
		cout << ans << endl << endl;
	}
}