#include <iostream>
#include <cstring>
#include <queue>
#include <set>
#define X first
#define Y second

using namespace std;

typedef pair<int, int> pii;

int a[100+10][100+10], vis[100+10][100+10], r, c, n, m, w;

int inRange(int i, int j){
	return (i<r && i>=0 && j<c && j>=0);
}

int main(){
	int tc;
	int cs=1;
	cin >> tc;
	while(tc--){
		cin >> r >> c >> m >> n >> w;
		int dx[] = {-m,+m,-m,+m,-n,+n,+n,-n};
		int dy[] = {+n,-n,-n,+n,-m,+m,-m,+m};
		memset(vis, 0, sizeof vis);
		memset(a, 0, sizeof a);

		int x, y; vis[0][0]=1;
		for(int i=0 ; i<w ; i++){
			cin >> x >> y; vis[x][y]=2;
		}

		set<pii> moves;
		queue<pii> q;
		q.push(pii(0, 0));
		while(!q.empty()){
			moves.clear();
			pii u = q.front(); q.pop(); 
			for(int i=0 ; i<8 ; i++){
				pii v = pii(u.X+dx[i], u.Y+dy[i]);
				if(!inRange(v.X, v.Y) || moves.count(v) || vis[v.X][v.Y]==2) continue;

				moves.insert(v);
				a[u.X][u.Y]++;
				if(!vis[v.X][v.Y]) 
					q.push(pii(v.X,v.Y)), vis[v.X][v.Y]=1;
			}
		}
		if(a[0][0]==0) 
			a[0][0]=2;
		int odd=0, even=0; 
		for(int i=0 ; i<r ; i++){
			for(int j=0 ; j<c ; j++){
				if(vis[i][j]==2 || !a[i][j]) continue;
				if(a[i][j]%2==0) even++;
				if(a[i][j]%2==1) odd++;
			}
		}
		
		cout << "Case " << cs++ <<": ";
		cout << even << " " << odd << endl;
	}
}