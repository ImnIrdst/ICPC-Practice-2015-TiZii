#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 100+10;

char a[MAX][MAX], vis[MAX][MAX]; int n,cs=1;

int di[] = {-1, 0,+1, 0};
int dj[] = { 0,-1, 0,+1};

int inRange(int i, int j){
	return (i>=0 && i<n && j>=0 && j<n);
}

void bfs(int i, int j){
	vis[i][j]=1;
	for(int d=0 ; d<4 ; d++){
		int ii=i+di[d], jj=j+dj[d];
		if(inRange(ii,jj) && !vis[ii][jj] 
			&& (a[ii][jj]=='@' || a[ii][jj]=='x')) bfs(ii,jj);
	}
}

int main(){
	int tc; cin >> tc;
	while(tc--){ cin >> n;
		for(int i=0 ; i<n ; i++){
			cin >> a[i];
		}
		int ans = 0;
		memset(vis,0,sizeof vis);
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<n ; j++){
				if(a[i][j]=='x' && !vis[i][j]){
					bfs(i,j); ans++;
				}
			}
		}

		cout << "Case " << cs++ << ": " << ans << endl;
	}
}