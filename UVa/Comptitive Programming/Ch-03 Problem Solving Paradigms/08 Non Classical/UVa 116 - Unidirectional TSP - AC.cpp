#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>

using namespace std;

int a[10][100], dp[10][100], path[10][100], n, m;

int main(){
	while(cin >> n >> m){
		//int a[10][100], dp[10][100], path[10][100];
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<m ; j++){
				cin >> a[i][j];
			}
		}
		
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<m ; j++){
				if(j==m-1) dp[i][m-1]=a[i][m-1], path[i][m-1]=i;
				else     dp[i][j]=1e9;
			}
		}
		string anspath="z"; int ansmin;
		for(int j=m-1 ; j>0 ; j--){
			for(int i=0 ; i<n ; i++){
				for(int d=n-1 ; d<n+2 ; d++){
					int k=(i+d)%n;
					if(dp[i][j]+a[k][j-1] < dp[k][j-1]){
						 dp[k][j-1]   = dp[i][j]+a[k][j-1];
						 path[k][j-1] = i;
					}
				}
			}

		}

		int minid=-1, Min=1e9;
		for(int i=0 ; i<n ; i++){
			if(dp[i][0]<Min) Min=dp[i][0], minid=i;
		}

		int ii=minid; string str="";
		for(int jj=0 ; jj<m ; jj++){
			cout << str << ii+1 ; str=" "; ii=path[ii][jj];
		}cout << endl;
		 cout << Min << endl;
	}

}
