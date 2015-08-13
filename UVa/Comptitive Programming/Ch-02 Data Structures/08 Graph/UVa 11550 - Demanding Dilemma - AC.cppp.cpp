#include <iostream>

using namespace std;

int main(){
	int n, m, tc; cin >> tc;
	while(tc--){
		cin >> n >> m; int vg[10][100];
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<m ; j++){
				cin >> vg[i][j];
			}
		}	
		int adj[10][10]={0}, ok=1, u, v;
		for(int i=0 ; i<m && ok  ; i++){
			int cnt=0;
			for(int j=0 ; j<n ; j++){
				if(vg[j][i]){ 
					if(cnt==0)	u=j;
					else 		v=j; 
					cnt++;
				}
			}
			if(cnt!=2) ok = 0;
			else {
				if(adj[u][v]) ok = 0; adj[u][v]=adj[v][u]=1;
			}	
		}
		cout << (ok ? "Yes" : "No") << endl;
	}
}