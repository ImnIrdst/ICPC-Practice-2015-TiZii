#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

const int Max=50+10;

typedef vector<int> vi;
typedef vector<vi > vvi;

int main(){
	int n, m, cs=1;
	while(cin >> n >> m && (n||m)){
		vvi adj(n, vi(n, 1e9));
		map<string, int> mp; int t=0;
		for(int i=0 ; i<n ; i++) 
			adj[i][i]=0;
		for(int i=0 ; i<m ; i++){
			string s1, s2;
			cin >> s1 >> s2;
			if(!mp.count(s1)) mp[s1]=t++;
			if(!mp.count(s2)) mp[s2]=t++;
			adj[mp[s1]][mp[s2]]=1;
			adj[mp[s2]][mp[s1]]=1;
		}

		for(int k=0 ; k<n ; k++){
			for(int i=0 ; i<n ; i++){
				for(int j=0 ; j<n ; j++){
					adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
				}
			}
		}

		int diameter=-1;
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<n ; j++){
				diameter = max(adj[i][j], diameter);
			}
		}
		cout << "Network " << cs++ << ": ";
		if(diameter < 1e9) cout << diameter << endl;
		else cout << "DISCONNECTED" << endl;
		cout << endl;
	}
}