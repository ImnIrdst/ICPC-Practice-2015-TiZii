#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;

const int MAX = 100+10;
const int INF = 1e9;

typedef long long int64;

int64 StoI(string str){
	stringstream sstr(str); int64 n; sstr >> n; return n;
}

int main(){
	int n;
	while(cin >> n){
		int64 adj[MAX][MAX]={0}; string str;
		for(int i=1 ; i<n ; i++){
			for(int j=0 ; j<i ; j++){
				cin >> str;
				if(str=="x") adj[i][j]=adj[j][i]=INF;
				if(str!="x") adj[i][j]=adj[j][i]=StoI(str);
			}
		}
		for(int k=0 ; k<n ; k++){
			for(int i=0 ; i<n ; i++){
				for(int j=0 ; j<n ; j++){
					adj[i][j] = min(adj[i][j],adj[i][k]+adj[k][j]);
				}
			}
		}
		
		int64 ans=-1;
		for(int i=1 ; i<n ; i++){
			ans = max(ans,adj[0][i]);
		}
		cout << ans << endl;
	}
}