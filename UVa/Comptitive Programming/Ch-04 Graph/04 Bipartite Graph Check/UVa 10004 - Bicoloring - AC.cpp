#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <fstream>
#include <map>
#include <sstream>
#include <bitset>
#include <set>
#include <queue>
#define pxw pair<int, int>
#define x first
#define w second
//#define cin fin
#define INF (int)1e9

using namespace std;

int n,m,c[210];
vector<int> a[210]; 

bool bfs(int t1){
	queue<int> q; q.push(t1);
	int u,v;
	while(!q.empty()){
		u=q.front(); q.pop();
		for(int i=0 ; i<a[u].size() ; i++){
			v=a[u][i];
			if(c[v]==-1){
				c[v]=1-c[u];
				q.push(v);
			}
			else if(c[v]==c[u]){
				return false;
			}
		}
	}
	return true;
}

int main(){
	//ifstream fin("in.txt");
	stringstream sin; string s;
	while(cin >> n  && n){
		cin >> m; int t1, t2, t3;
		for(int i=0 ; i<210 ; i++){ c[i]=-1; a[i].clear();}
		if(m==0){ cout <<  "BICOLORABLE." << endl; continue;}
		for(int i=0 ; i<m ; i++){
			cin >> t1 >> t2;
			a[t1].push_back(t2);
			a[t2].push_back(t1);
		}
		c[t1]=1;
		cout << (!bfs(t1) ? "NOT BICOLORABLE." : "BICOLORABLE.") << endl;
	}
	return 0;
}