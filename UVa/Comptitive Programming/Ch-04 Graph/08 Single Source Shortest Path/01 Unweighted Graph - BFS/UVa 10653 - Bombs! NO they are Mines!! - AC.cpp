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

using namespace std;

struct pii{
	int x,y; pii(){} pii(int X, int Y){x=X,y=Y;}
	bool operator==(pii v){ return (v.x==x && v.y==y); }
};

struct piil{
	pii u; int lev; piil(){} piil(pii U, int L){u=U,lev=L;}
};

bool a[MAX][MAX], vis[MAX][MAX]; int r,c;
int dx[]={ 0, 0,-1,+1};
int dy[]={+1,-1, 0, 0};

bool inRange(int x, int y){
	return (x>=0 && y>=0 && x<r && y<c && a[x][y]!=1);
}

int bfs(pii s, pii e){
	queue<piil> q; q.push(piil(s,0));
	while(!q.empty()){
		pii u=q.front().u; int lev=q.front().lev; q.pop();
		if(u==e) return lev;
		if(vis[u.x][u.y]) continue; vis[u.x][u.y]=1;
		for(int i=0 ; i<4 ; i++){
			pii v=pii(u.x+dx[i], u.y+dy[i]);
			if(inRange(v.x,v.y)){
				q.push(piil(v,lev+1));
			}
		}
	}
	return -1;
}

int main(){
	while(cin >> r >> c && (r || c)){
		pii s,e; memset(vis,0,sizeof vis); memset(a,0,sizeof a);
		int n,m,x,y; cin >> n;
		for(int i=0 ; i<n ; i++){
			cin >> x >> m; 
			for(int j=0 ; j<m ; j++){
				cin >> y; a[x][y]=1;
			}
		}
		cin >> x >> y; s=pii(x,y);
		cin >> x >> y; e=pii(x,y);
		int ans=bfs(s,e); cout << ans << endl;
	}
	return 0;
}