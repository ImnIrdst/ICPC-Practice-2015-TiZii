#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include<vector>
#include <fstream>
#include <map>
#include <sstream>
#include <bitset>
#include <set>
#include <queue>
#define pxy pair<int, int>
#define x first
#define y second
//#define cin fin
#define INF (int)1e9

using namespace std;

int vis[10010];
vector<pxy> a[10010]; 

pxy bfs(int s, int d){
	queue<pxy> q; q.push(pxy(s,d));
	pxy u,v,mx;

	while(!q.empty()){
		u=q.front(); q.pop();
		for(int i=0 ; i<a[u.x].size() ; i++){
			v=pxy(a[u.x][i].x,a[u.x][i].y+u.y); 
			if(!vis[v.x]){
				vis[u.x]=1;
				q.push(v);
				if(v.y>mx.y){
					mx=v;
				}
			}
		}
	}
	return mx;
}


int main(){
	//ifstream fin("in.txt");
	stringstream sin; string s;
	while(getline(cin,s)){
		if(s==""){ cout << 0 << endl; continue;}
		sin << s;
		for(int i=0 ; i<10010 ; i++){ vis[i]=0; a[i].clear(); }

		int x,y,w; sin >> x >> y >> w; sin.clear();
		a[x].push_back(pxy(y,w));
		a[y].push_back(pxy(x,w));
		while(getline(cin,s) && s!=""){
			sin << s; sin >> x >> y >> w; sin.clear();
			a[x].push_back(pxy(y,w));
			a[y].push_back(pxy(x,w));
		}
		pxy mx=bfs(x,0);
		for(int i=0 ; i<10010 ; i++) vis[i]=0;
		pxy ans=bfs(mx.x,0);
		cout << ans.y << endl;
	}
	return 0;
}