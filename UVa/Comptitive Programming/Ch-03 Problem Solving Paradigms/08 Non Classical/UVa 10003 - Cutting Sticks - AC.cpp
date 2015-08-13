#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <math.h>
#include<vector>
#include <fstream>
//#define cin fin
#define INF (int) 1e9
using namespace std;

int a[55],d[55][55];

int calc(int left, int right){
	if(left+1==right) return 0;
	//if(left>=right) return -INF;*/
	if(d[left][right]!=-1) return d[left][right];
	int ans=INF;
	for(int i=left+1 ; i!=right ; i++){
		ans=min(ans,calc(left, i)+calc(i,right)+a[right]-a[left]);
	}
	return d[left][right]=ans;
}

int main(){
	//ifstream fin("in.txt");
	int maxn; 
	while(cin >> maxn && maxn){
		for(int i=0 ; i<55 ; i++)
			for(int j=0 ; j<55 ; j++)
				d[i][j]=-1;
		
		int n,sum=0; cin >> n; a[0]=0;
		for(int i=1 ; i<=n ; i++){ cin >> a[i]; sum+=a[i];}
		a[n+1]=maxn;
		//cout << calc(0,n+1) << endl;
		printf("The minimum cutting is %d.\n",calc(0,n+1));
	}
	return 0;
}