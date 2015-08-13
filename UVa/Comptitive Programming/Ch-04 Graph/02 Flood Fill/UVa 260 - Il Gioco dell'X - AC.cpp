#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 200+10;

char a[MAX][MAX]; int vis[MAX][MAX], n; char ans; 

int di[8]={-1,-1,+0,+0,+1,+1};
int dj[8]={-1,+0,-1,+1,+1,+0};

int valid(int i, int j){
	return (i<n && i>=0 && j<n && j>=0 && a[i][j]=='w');
}

void dfs(int i, int j){\
	if( vis[i][j] ){ return; } vis[i][j]=1;
	if( j == n-1  ){ ans = 'W'; return;   }
	for(int d=0 ; d<8 ; d++){
		if(valid(i+di[d], j+dj[d]))
			dfs(i+di[d], j+dj[d]);
	}
}

int main(){
	int cs = 1;
	while(cin >> n && n){
		for(int i=0 ; i<n ; i++){
			cin >> a[i];
		}
		ans = 'N'; memset(vis,0,sizeof vis);
		for(int i=0 ; i<n && ans=='N' ; i++){
			if(valid(i,0)) dfs(i,0);// memset(vis,0,sizeof vis);
		}
		if(ans == 'W') cout << cs++ << " " << 'W' << endl;
		if(ans != 'W') cout << cs++ << " " << 'B' << endl;
	}
}