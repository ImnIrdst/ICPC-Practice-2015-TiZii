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
//#define cin fin
#define INF (int) 1e6

using namespace std;

char a[110][110];
int n,m,col;
int marks[110][110],markv[110][110];
vector<int> v;
//map<int, int> mp;
int solve2(int x, int y, int c){
	if( x>=n || y>=m || x<0 || y<0 || markv[x][y] || marks[x][y]!=c || a[x][y]=='.' || a[x][y]=='*')
		return 0;
	markv[x][y]=1;
	int ans=(a[x][y]=='X');
	ans+=solve2(x-1,y,c); ans+=solve2(x+1,y,c); ans+=solve2(x,y-1,c); ans+=solve2(x,y+1,c);
	return ans;
}

int solve(int x, int y){
	if(x>=n || y>=m || x<0 || y<0 || marks[x][y] || a[x][y]=='.' )
		return 0;
	marks[x][y]=col; 
	solve(x-1,y); solve(x+1,y); solve(x,y-1); solve(x,y+1);
	return 0;
}

int main(){
	//ifstream fin("in.txt");
	int t=1;
	while(cin >> m >> n && n && m){

		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<m ; j++){
				markv[i][j]=marks[i][j]=0;
			}
		}
		v.clear(); col=1;
		for(int i=0 ; i<n ; i++){
			cin >> a[i];
		}

		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<m ; j++){
				if(!marks[i][j] && a[i][j]!='.'){
					solve(i,j); col++;
				}
			}
		}
		int cnt=0;
		for(int c=1 ; c<col ; c++){
			for(int i=0 ; i<n ; i++){
				for(int j=0 ; j<m ; j++){
					if(!markv[i][j] && marks[i][j]==c && a[i][j]=='X'){
						solve2(i,j,c); cnt++;
					}
				}
			}
			if(cnt!=0)
				v.push_back(cnt); 
			cnt=0;
		}
		sort(v.begin(), v.end());
		cout << "Throw " << t++ << endl;
		for(int i=0 ; i<v.size() ; i++){
			if(i!=0) cout << " ";
			cout << v[i];
		}
		if(v.size()==0)
			cout << 0 << endl;
		cout << endl << endl;
		
	}
	return 0;
}