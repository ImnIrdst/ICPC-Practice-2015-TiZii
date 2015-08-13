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
#define MAX (30+10)

using namespace std;

struct piii{
	int x,y,z; piii(){} piii(int X, int Y, int Z){x=X,y=Y,z=Z;}
	bool operator==(piii v){ return (v.x==x && v.y==y && v.z==z); }
};

struct piiil{
	piii u; int lev; piiil(){} piiil(piii p, int L){u=p,lev=L;}
};

char a[MAX][MAX][MAX]; bool vis[MAX][MAX][MAX]; int l,r,c;
int dx[]={ 0, 0, 0, 0,-1,+1};
int dy[]={ 0, 0,+1,-1, 0, 0};
int dz[]={-1,+1, 0, 0, 0, 0};

bool inRange(int x, int y, int z){
	return (x>=0 && y>=0 && z>=0 && x<r && y<c && z<l && a[z][x][y]!='#');
}

void print(){
	cout << "******************" << endl;
	for(int z=0 ; z<l ; z++){
		for(int x=0 ; x<r ; x++){
			for(int y=0 ; y<c ; y++){
				cout << vis[z][x][y];
			}
			cout << endl;
		}
		cout << endl;
	}
	cout << "******************" << endl;
}

int bfs(piii s, piii e){
	queue<piiil> q; q.push(piiil(s,0));
	while(!q.empty()){
		piii u=q.front().u; int lev=q.front().lev; q.pop();
		if(u==e) return lev;
		if(vis[u.z][u.x][u.y]) continue; vis[u.z][u.x][u.y]=1;
		//print(); // debug
		for(int i=0 ; i<6 ; i++){
			piii v=piii(u.x+dx[i], u.y+dy[i], u.z+dz[i]);
			if(inRange(v.x,v.y,v.z)){
				q.push(piiil(v,lev+1));
			}
		}
	}
	return -1;
}

int main(){
	while(cin >> l >> r >> c && (l || r || c)){
		piii s,e; memset(vis,0,sizeof vis);
		for(int z=0 ; z<l ; z++){
			for(int x=0 ; x<r ; x++){
				for(int y=0 ; y<c ; y++){
					cin >> a[z][x][y];
					if(a[z][x][y]=='S') s=piii(x,y,z);
					if(a[z][x][y]=='E') e=piii(x,y,z);
				}
			}
		}
		int ans=bfs(s,e);
		if(ans==-1) printf("Trapped!\n");
		if(ans!=-1) printf("Escaped in %d minute(s).\n", ans);
	}
	return 0;
}