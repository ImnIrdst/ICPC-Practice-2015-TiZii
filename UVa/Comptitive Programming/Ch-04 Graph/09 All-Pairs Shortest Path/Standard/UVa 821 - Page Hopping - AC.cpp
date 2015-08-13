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

int a[110][110],p[110][110],n=101;

void printpath(int s, int f){
	if(p[s][f]!=-1){
		printpath(s,p[s][f]);
		printf("%d ", p[s][f]);
		printpath(p[s][f],f);
	}

}

int main(){
	//ifstream fin("in.txt");
	int t=1; int x,y,w;
	while(cin >> x >> y && x && y){
		
		for(int i=0 ; i<110 ; i++){
			for(int j=0 ; j<110 ; j++){
				a[i][j]=INF;
				p[i][j]=-1;
			}
			p[i][i]=i;
			a[i][i]=0;
		}
		a[x][y]=1;
		while(cin >> x >> y && x && y){
				a[x][y]=1;
		}
		for(int k=0 ; k<=n ; k++){
			for(int i=0 ; i<=n ; i++){
				for(int j=0 ; j<=n ; j++){
					if(a[i][j]>=a[i][k]+a[k][j]){
						a[i][j]=a[i][k]+a[k][j];
						p[i][j]=k;
					}
				}
			}
		}
		double sum=0; double cnt=0;
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<n ; j++){
				if(a[i][j]!=INF && i!=j){
					sum+=a[i][j];
					cnt++;
				}
			}
		}
		printf("Case %d: average length between pages = %.3lf clicks\n",t++,sum/cnt);
		
	}
	return 0;
}