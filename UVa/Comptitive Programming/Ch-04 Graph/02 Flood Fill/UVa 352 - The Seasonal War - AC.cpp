#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 25+10;

char a[MAX][MAX]; int vis[MAX][MAX], n;

int di[8]={-1,-1,-1,+0,+0,+1,+1,+1};
int dj[8]={-1,+0,+1,-1,+1,-1,+0,+1};

int valid(int i, int j){
	return (i<n && i>=0 && j<n && j>=0 && a[i][j]=='1');
}

void dfs(int i, int j){\
	if( vis[i][j] ) return; vis[i][j]=1;
	for(int d=0 ; d<8 ; d++){
		if(valid(i+di[d], j+dj[d])){
			dfs(i+di[d], j+dj[d]);
		}
	}
}

int main(){
	int cs = 1;
	while(cin >> n){
		for(int i=0 ; i<n ; i++){
			cin >> a[i];
		}
		int ans = 0; memset(vis,0,sizeof vis);
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<n ; j++){
				if(!vis[i][j] && a[i][j]=='1'){
					dfs(i,j), ans++;
				}
			}
		}
		cout << "Image number "<< cs++ <<
				" contains "   << ans  << " war eagles." << endl;
	}
}