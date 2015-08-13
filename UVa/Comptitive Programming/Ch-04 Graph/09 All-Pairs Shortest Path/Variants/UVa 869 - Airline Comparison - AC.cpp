#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <map>
#define INF (int)1e9
#define MAX 128 

using namespace std;

int adj1[MAX][MAX],adj2[MAX][MAX],n=MAX;

int main(){
	int tc; cin >> tc;
	while(tc--){
		for(int i=0 ; i<MAX ; i++){
			for(int j=0 ; j<MAX ; j++){
				adj1[i][j]=adj2[i][j]=0;
			}
		}
		int n1, n2; char c1,c2; cin >> n1;
		for(int i=0 ; i<n1 ; i++){
			cin >> c1 >> c2; adj1[c1][c2]=1;
		}
		cin >> n2;
		for(int i=0 ; i<n2 ; i++){
			cin >> c1 >> c2; adj2[c1][c2]=1;
		}
		
		for(int k=0 ; k<n ; k++){
			for(int i=0 ; i<n ; i++){
				for(int j=0 ; j<n ; j++){
					adj1[i][j]|=(adj1[i][k] & adj1[k][j]);
				}
			}
		}

		for(int k=0 ; k<n ; k++){
			for(int i=0 ; i<n ; i++){
				for(int j=0 ; j<n ; j++){
					adj2[i][j]|=(adj2[i][k] & adj2[k][j]);
				}
			}
		}
		bool yes=1;
		for(int i=0 ; i<n && yes ; i++){
			for(int j=0 ; j<n && yes ; j++){
				if(adj1[i][j]!=adj2[i][j]) yes=0;
			}
		}
		cout << (yes ? "YES" : "NO") << endl;
		if(tc) cout << endl;
	}
	return 0;
}
