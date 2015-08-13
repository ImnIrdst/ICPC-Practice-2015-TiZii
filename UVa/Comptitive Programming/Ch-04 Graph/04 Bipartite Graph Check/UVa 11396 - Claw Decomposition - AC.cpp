#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <queue>
//#define cin fin
#define INF (int)1e9

using namespace std;

int n,m,c[300+10];
vector<int> a[300+10]; 

bool bfs(int t1){
	queue<int> q; q.push(t1);
	int u,v;
	while(!q.empty()){
		u=q.front(); q.pop();
		for(int i=0 ; i<a[u].size() ; i++){
			v=a[u][i];
			if(c[v]==-1){ c[v]=1-c[u]; q.push(v); }
			else if(c[v]==c[u]){return false;}
		}
	}
	return true;
}

int main(){
	//ifstream fin("in.txt");
	stringstream sin; string s;
	while(cin >> n  && n){
		int t1, t2, m=0;
		for(int i=0 ; i<300+10 ; i++){ c[i]=-1; a[i].clear();}
		while(cin >> t1 >> t2 && (t1||t2)){
			t1--; t2--;
			a[t1].push_back(t2);
			a[t2].push_back(t1);
			m++;
		}
		if(m==0){ cout <<  "YES" << endl; continue;}
		c[t1]=1;
		cout << (!bfs(t1) ? "NO" : "YES") << endl;
	}
	return 0;
}
/*
6
1 3
1 4
1 5
6 3
6 4
6 5
2 3
2 4 
2 5
0 0

YES
*/