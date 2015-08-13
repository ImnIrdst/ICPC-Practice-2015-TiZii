#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <map>
#include <sstream>
#define INF (int)1e9
#define MAX 100

using namespace std;

string a[MAX+10]; int n,vis[MAX+10][MAX+10]; //a -> color

int d1[]={-1,-1,-1, 0,0, 1,1,1};
int d2[]={-1, 0, 1,-1,1,-1,0,1};

int bfs(int u, int v){
	if(u<0 || u>=n || v<0 || v>=a[0].length()) return 0;
	if(vis[u][v] || a[u][v]!='W') return 0;
	int cnt=1; vis[u][v]=1;
	for(int i=0 ; i<8 ; i++){
		cnt+=bfs(u+d1[i],v+d2[i]);
	}
	return cnt;
}

int main(){
	int tc; cin >> tc; cin.ignore(); string str;  cin.ignore();
	while(tc--){
		memset(vis,0,sizeof vis); n=0;
		stringstream sin; string str; 
		while(getline(cin,str) && (str[0] == 'L' || str[0] == 'W')){a[n++]=str;}
		while(str.length()>0){
			sin.clear(); sin << str; int i,j;
			sin >> i >> j;  i--; j--;// color++;
			memset(vis,0,sizeof vis);
			if(vis[i][j]==0) cout << bfs(i,j) << endl; 
			getline(cin,str);
		}
		if(tc!=0) cout << endl;
	}
	return 0;
}