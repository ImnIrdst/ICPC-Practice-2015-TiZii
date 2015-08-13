#include <iostream>
#include <math.h>
#include <algorithm>
#include <fstream>
#include <string>
#include <map>
#include <stack>
#include <vector>
//#define cin fin
#define MAX (int)1e2+10
#define fr( i , n )for( int i = 0; i < n ; i++ )

using namespace std;

int n,m; 
int a[MAX][MAX]={0}, mark[MAX]={0}, in[MAX]; vector<int> ans;


void dfs(int v){
	mark[v]=1;
	for(int i=1 ; i<=n ; i++){
		if(a[v][i] && !mark[i])
			dfs(i);
	}
	ans.push_back(v);
}

int main(){
	//ifstream fin("in.txt");
	
	while(cin >> n >> m){
		if( !n && !m ) break;
		for(int i=0 ; i<MAX ; i++){
			mark[i]=0; in[i]=0;
		}
		ans.clear();
		for(int i=0 ; i<m ; i++){
			int x,y; cin >> x >> y;
			a[x][y]=1;
			in[y]++;
		}
		for(int i=1 ; i<=n ; i++){
			if(!mark[i] && in[i]==0) 
				dfs(i);
		}
		reverse(ans.begin(), ans.end());
		for(int i=0 ; i<ans.size() ;i++){
			if(i!=0) cout << " ";
			cout << ans[i];
		}
		cout << endl;
	}
	return 0;
}