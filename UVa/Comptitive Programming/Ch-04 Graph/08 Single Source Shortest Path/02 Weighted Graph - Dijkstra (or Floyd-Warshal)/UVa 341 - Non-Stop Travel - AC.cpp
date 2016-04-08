#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <fstream>
#include <map>
#include <sstream>
#include <bitset>
#include <set>
//#define cin fin
#define INF (int)1e9

using namespace std;

int a[20][20],p[20][20],n;

void printpath(int s, int f){
	/*if(s==f)
		printf("%d ", s);
	else */if(p[s][f]!=-1){
		printpath(s,p[s][f]);
		printf("%d ", p[s][f]);
		printpath(p[s][f],f);
	}

}

int main(){
	//ifstream fin("in.txt");
	int t=1;
	while(cin >> n && n){
		int x,y,w;
		for(int i=0 ; i<20 ; i++){
			for(int j=0 ; j<20 ; j++){
				a[i][j]=INF;
				p[i][j]=-1;
			}
			p[i][i]=i;
		}
		for(int i=1; i<=n ; i++){
			cin >> x;
			for(int j=0 ; j<x ; j++){
				cin >> y >> w;
				a[i][y]=min(w,a[i][y]);
				//p[i][y]=i;
			}
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
		int s,f; cin >> s >> f;
		printf("Case %d: Path = %d ",t++, s);
		printpath(s,f);
		printf("%d; %d second delay\n",f,a[s][f]);
	}
	return 0;
}