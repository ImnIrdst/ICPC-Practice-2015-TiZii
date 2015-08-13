#include <iostream>
#include <vector>

using namespace std;

struct edge{ int u, v, w;
	edge(int u=0, int v=0, int w=0)
		:u(u), v(v), w(w){}
};

int n, m, cs=1;  

int main(){
	while(cin >> n){
		vector<int> busy(n+1,0);
		
		for(int i=1 ; i<=n ; i++){
			cin >> busy[i];
		}

		cin >> m; 
		vector<edge> ve(m, edge());
		for(int i=0 ; i<m ; i++){
			cin >> ve[i].u >> ve[i].v; 
			ve[i].w = busy[ve[i].v]-busy[ve[i].u];
			ve[i].w*= ve[i].w*ve[i].w;
		}

		vector<int> dist(n+1, 1e9); dist[1]=0;
		for(int i=0 ; i<n-1 ; i++){
			for(int j=0 ; j<m ; j++){
				int u=ve[j].u, v=ve[j].v, w=ve[j].w;
				if(dist[u]+w < dist[v]){
					dist[v] = dist[u] + w;
				}
			}
		}

		for(int j=0 ; j<m ; j++){
			int u=ve[j].u, v=ve[j].v, w=ve[j].w;
			if(dist[u]+w < dist[v] && dist[u]!=1e9){
				dist[v] = -1e9 ;
			}
		}

		int q;
		cin >> q;
		cout << "Set #" << cs++ << endl;
		while(q--){
			int u; cin >> u;
			if( dist[u]<3 || dist[u]>1e9/10) 
				cout << "?" << endl;
			else
				cout << dist[u] << endl;
		}
	}
}