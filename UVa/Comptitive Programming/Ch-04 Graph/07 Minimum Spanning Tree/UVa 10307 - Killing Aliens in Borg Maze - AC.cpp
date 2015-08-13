#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdio>

#define INF (int)1e9
#define pii pair<int,int>
#define piii pair<int, pii >
#define W first
#define U second.first
#define V second.second

using namespace std;

vector<int> par,rnk,cnt;

void SetInit(int n){
	par.assign(n,-1); rnk.assign(n,0); cnt.assign(n,1); //par==parent
}

int Find(int a){
	int i=a,j=a,tmp;
	while(par[i]!=-1){ i=par[i]; }
	while(par[j]!=-1){ tmp=par[j]; par[j]=i; j=tmp; } //path compression
	return i;
}
void Uni(int a, int b){
	int A=Find(a),B=Find(b);
	if(A!=B){
		if(rnk[A]<rnk[B]) swap(A,B); // union using rank
		if(rnk[A]==rnk[B]) rnk[A]++;
		par[B]=A;
	}
}

int m,n; vector< piii > E;// e==edges array

const int MAX = 100+10;

int dx[] = {-1, 0, 0,+1};
int dy[] = {0 ,-1,+1, 0};
int d[MAX][MAX], a[MAX][MAX];

int inRange(int i, int j){
	return (i>=0 && i<n && j>=0 && j<m && a[i][j]!=-1);
}

void BFS(int sx, int sy){
	queue<pii> q; q.push(pii(sx,sy)); d[sx][sy]=0;
	while(!q.empty()){
		int x = q.front().first, y=q.front().second; q.pop();
		if( a[x][y]>=1 && a[x][y]!=a[sx][sy]) 
			E.push_back(piii(d[x][y],pii(a[sx][sy],a[x][y])));
		for(int dir=0 ; dir<4 ; dir++){
			if(inRange(x+dx[dir],y+dy[dir]) && d[x+dx[dir]][y+dy[dir]]==-1)
				q.push(pii(x+dx[dir],y+dy[dir])), d[x+dx[dir]][y+dy[dir]]=d[x][y]+1;
		}
	}
}

int main(){
	int tc; cin >> tc;
	while(tc--){
		cin >> m >> n; cin.ignore();
		memset(a,-1,sizeof a);
		char str[MAX]; int N=1;
		for(int i=0 ; i<n ; i++){
			gets(str);
			for(int j=0 ; j<m ; j++){
				if(str[j]==' ') a[i][j]=0;
				if(str[j]=='S') a[i][j]=N++;
				if(str[j]=='A') a[i][j]=N++;
			}
		}
		E.clear();
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<m ; j++){
				if(a[i][j]>=1) memset(d,-1,sizeof d), BFS(i,j);
			}
		}


		int u,v,w;int ans=0;
		sort(E.begin(), E.end()); SetInit(N); 
		for(int i=0; i<E.size(); i++){
			if(Find(E[i].U)!=Find(E[i].V)){
				Uni(E[i].U,E[i].V); ans+=E[i].W;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
