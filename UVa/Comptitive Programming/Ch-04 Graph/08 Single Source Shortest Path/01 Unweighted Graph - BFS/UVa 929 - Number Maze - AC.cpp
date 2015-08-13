#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
#include <cstring>
#include <vector>

using namespace std;

const int MAX = 1000+10;

#define pii  pair<int,int>
#define piii pair<int,pii>
#define iii  second.first
#define jjj  second.second
#define ww   first
#define ii   first
#define jj   second

int di[] = {-1, 0,+1, 0};
int dj[] = { 0,-1, 0,+1};

int a[MAX][MAX], vis[MAX][MAX], n, m;

int inRange(int i, int j){
	return (i>=0 && i<n && j>=0 && j<m);
}

int main(){
	int tc; cin >> tc;
	while(tc--){
		cin >> n >> m;
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<m ; j++){
				cin >> a[i][j];
			}
		}
		pii s(0,0), g(n-1,m-1); int w=-1;
		memset(vis,-1,sizeof vis); vis[s.ii][s.jj]=a[0][0];
		priority_queue<piii, vector<piii>, ::greater<piii> > pq; pq.push(piii(0,s));
		while(!pq.empty()){
			pii u = pq.top().second; w = pq.top().ww; pq.pop();
			if( u == g ) break;
			if( w > vis[u.ii][u.jj]) continue;
			for(int d=0 ; d<4 ; d++){
				int i = u.ii + di[d];
				int j = u.jj + dj[d];
				if(inRange(i,j) && (vis[i][j]==-1 
					|| vis[u.ii][u.jj] + a[i][j] < vis[i][j])){
						vis[i][j] = vis[u.ii][u.jj] + a[i][j];
						pq.push(piii(vis[i][j], pii(i,j)));
				}
			}
		}
		cout << vis[g.ii][g.jj] << endl;
	}
}