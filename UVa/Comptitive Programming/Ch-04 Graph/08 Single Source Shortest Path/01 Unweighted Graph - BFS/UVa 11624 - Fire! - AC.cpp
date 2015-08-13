#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <queue>
#define INF (int)1e9
#define MAX (1000+10)
#define pii pair<int,int> 
#define X first
#define Y second

using namespace std;

char a[MAX][MAX]; int visf[MAX][MAX],visj[MAX][MAX]; int r,c; vector<pii> J,F;
int dx[]={ 0, 0,-1,+1};
int dy[]={+1,-1, 0, 0};

bool inRange(int x, int y){
	return (x>=0 && y>=0 && x<r && y<c && a[x][y]!='#');
}

bool exit(int x, int y){
	return ((x==0 || y==0 || x==r-1 || y==c-1) && (visj[x][y]<visf[x][y] || visf[x][y]==0));
}

int bfs(vector<pii>& s , int vis[MAX][MAX]){
	bool fire=(s==F);
	queue<pii> q;
	for(int i=0 ; i<s.size() ; i++){
		q.push(s[i]); vis[s[i].X][s[i].Y]=1;
	}
	while(!q.empty()){
		pii u=q.front(); int lev=vis[u.X][u.Y]; q.pop();
		//if(!fire) printf("bfs: %d %d : %d || %d \n", u.X, u.Y, lev, visf[u.X][u.Y] );
		if(!fire && exit(u.X,u.Y)) return lev;
		
		for(int i=0 ; i<4 ; i++){
			pii v=pii(u.X+dx[i], u.Y+dy[i]);
			if(inRange(v.X,v.Y) && !vis[v.X][v.Y]){
				q.push(v); vis[v.X][v.Y]=lev+1;
			}
		}
	}
	return -1;
}

int main(){
	int tc; cin >> tc;
	while(tc--){
		cin >> r >> c; J.clear(); F.clear();
		memset(visf,0,sizeof visf); memset(visj,0,sizeof visj);
		for(int i=0 ; i<r ; i++){
			for(int j=0 ; j<c ; j++){
				cin >> a[i][j];
				if(a[i][j]=='J') J.push_back(pii(i,j));
				if(a[i][j]=='F') F.push_back(pii(i,j));
			}	
		}
		int tf=bfs(F,visf); int tj=bfs(J,visj); //cout << tj << endl;
		if(tj>=tf && tj==-1) cout << "IMPOSSIBLE" << endl;
		else cout << tj << endl;
	}
	return 0;
}