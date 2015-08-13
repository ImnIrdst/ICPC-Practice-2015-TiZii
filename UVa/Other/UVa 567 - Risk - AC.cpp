#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#define INF (int)1e9

using namespace std;

int a[20][20],n=20;

int main()
{
	int tmp,u,v,t=1;
	while(cin >> tmp){
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<n ; j++){
				a[i][j]=INF;
			}
		}
		for(int i=0 ; i<n-1 ; i++){
			//cin >> tmp;
			for(int j=0 ; j<tmp ; j++){
				cin >> v; v--;
				a[i][v]=a[v][i]=1;
			}
			cin >> tmp;
		}
		for(int k=0 ; k<n ; k++){
			for(int i=0 ; i<n ; i++){
				for(int j=0 ; j<n ; j++){
					a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
				}
			}
		}
		printf("Test Set #%d\n", t++);
		while(tmp--){
			cin >> u >> v; u--; v--;
			printf("%2d to %2d: %d\n",u+1, v+1, a[u][v]);
		}
		printf("\n");
	}
	return 0;
}