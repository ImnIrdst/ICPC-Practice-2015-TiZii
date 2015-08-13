#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <set>

using namespace std;

typedef set<int> vi;
typedef vector<vi > vsi;


int main(){
	int tc; cin >> tc;
	while(tc--){ int p, t; cin >> p >> t; cin.ignore();
		string str; vsi adj(p); int n=0;
		while(getline(cin, str) && str!=""){
			stringstream sstr(str);
			int u,v; sstr >> u >> v; u--;
			adj[u].insert(v); 
		}
		int ans=0;
		for(int i=0 ; i<p ; i++){
			bool isdif=1;
			for(int j=i+1 ; j<p ; j++){
				isdif &= (adj[i]!=adj[j]);
			}
			ans+=isdif;
		}
		cout << ans << endl;
		if(tc) cout << endl;
	}
}