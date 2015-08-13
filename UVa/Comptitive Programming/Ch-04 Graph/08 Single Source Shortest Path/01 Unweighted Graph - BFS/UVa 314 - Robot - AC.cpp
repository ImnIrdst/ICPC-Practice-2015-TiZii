#include <iostream>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

const int Max = 50 + 10;

int di[] = {-1, +0, +1, +0};
int dj[] = {+0, +1, +0, -1};
int t[Max][Max], a[Max][Max], vis[Max][Max][4], n, m;

struct state{
	int i, j, d, w;
	state(int i=0, int j=0, int d=0, int w=0):
		i(i), j(j), d(d), w(w) {}
};

int inRange(int i, int j){
	return (i<=n && i>=0 && j<=m && j>=0);
}


int dir(char c){
	if(c=='n') return 0;
	if(c=='e') return 1;
	if(c=='s') return 2;
	if(c=='w') return 3;
}

void go(){
	int si, sj, fi, fj; string d;
	cin >> si >> sj >> fi >> fj >> d;
	int dd = dir(d[0]);

	if(a[fi][fj] && a[si][sj]){
		queue<state> q;
		memset(vis,0,sizeof vis);
		q.push(state(si,sj,dd,0));
		while(!q.empty()){
			state s = q.front(); q.pop();
			//cout << s.w << endl;
			if(!inRange(s.i, s.j) || !a[s.i][s.j]) continue;
			if(vis[s.i][s.j][s.d]) continue; vis[s.i][s.j][s.d]=1;
			
			if(s.i==fi && s.j==fj){
				cout << s.w << endl; return;
			}

			q.push(state(s.i, s.j, (s.d+1)%4, s.w+1));
			q.push(state(s.i, s.j, (s.d+3)%4, s.w+1));
			for(int k=1 ; k<=3 ; k++){
				int ii=s.i+k*di[s.d], jj=s.j+k*dj[s.d];
				if(!inRange(ii, jj) || !a[ii][jj]) break;
				q.push(state(ii,jj,s.d,s.w+1));
			}
		}
	}
	cout << -1 << endl;
}

int main(){
	while(cin >> n >> m && n+m){
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<m ; j++){
				cin >> t[i][j];
			}
		}

		for(int i=0 ; i<=n ; i++){
			for(int j=0 ; j<=m ; j++){
				if(i==0 || i==n || j==0 || j==m) a[i][j]=0;
				else a[i][j] = !t[i-1][j-1] && !t[i-1][j] && !t[i][j-1] && !t[i][j];
			}
		}
		go();
	}
}