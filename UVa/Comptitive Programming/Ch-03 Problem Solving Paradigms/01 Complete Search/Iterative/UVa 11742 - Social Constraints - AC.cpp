#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <vector>
#define INF (int)1e9

using namespace std;

int ABS(int A){return (A>0 ? A : -1*A);}

int main(){
	int n,m;
	while(cin >> n >> m && (n || m)){
		vector<int> c[10][10]; int a[8]={0,1,2,3,4,5,6,7},x,y,cond,ans=0;
		for(int i=0 ; i<m ; i++){
			cin >> x >> y >> cond;
			c[x][y].push_back(cond);
		}
		do{
			bool OK=true;
			for(int i=0 ; i<n && OK; i++){
				for(int j=0 ; j<n && OK ; j++){
					for(int k=0 ; k<c[a[i]][a[j]].size() ; k++){
						if(c[a[i]][a[j]][k]>0){
							if(ABS(i-j)>c[a[i]][a[j]][k]) OK=false;
						}
						if(c[a[i]][a[j]][k]<0){
							if(ABS(i-j)<-1*c[a[i]][a[j]][k]) OK=false;
						}
					}

				}
			}
			if(OK) ans++;
		}while(next_permutation(a,a+n));
		cout << ans << endl;
	}
	return 0;
}