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
//#define cin fin
#define INF (int)1e9

using namespace std;

int a[110][110],n=101,m,q;

int main(){
	//ifstream fin("in.txt");
	int t=1; int x,y,w;
	while(cin >> n  >> m >> q && n && m && q){
		if(t!=1)
			cout << endl;
		for(int i=0 ; i<110 ; i++){
			for(int j=0 ; j<110 ; j++){
				a[i][j]=INF;
			}
			a[i][i]=0;
		}
		for(int i=0 ; i<m ; i++){
			cin >> x >> y >> w;
			a[x][y]=min(a[x][y],w);
			a[y][x]=min(a[y][x],w);
		}
		for(int k=0 ; k<=n ; k++){
			for(int i=0 ; i<=n ; i++){
				for(int j=0 ; j<=n ; j++){
					a[i][j]=min(a[i][j],max(a[i][k],a[k][j]));
				}
			}
		}
		cout << "Case #" << t++ << endl;
		for(int i=0 ; i<q ; i++){
			cin >> x >> y;
			if(a[x][y]!=INF)
				cout << a[x][y] << endl;
			else 
				cout << "no path" << endl;
		}
		
	}
	return 0;
}