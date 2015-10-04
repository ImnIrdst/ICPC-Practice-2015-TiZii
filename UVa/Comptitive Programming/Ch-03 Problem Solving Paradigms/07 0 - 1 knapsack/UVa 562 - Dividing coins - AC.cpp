#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <fstream>
//#define cin fin
#define INF (int) 1e9
using namespace std;

int a[100],d[60000][110];

int calc(int w, int idx){
	if(w<0) return INF;
	if(d[w][idx]!=-1) return d[w][idx];
	int Min=w;
	for(int i=0 ; i<idx ; i++){
		Min=min(Min,calc(w-a[i],i));
	}
	return d[w][idx]=Min;
}

int main(){
	//ifstream fin("in.txt");
	int tc; cin >> tc;
	while(tc--){
		for(int i=0 ; i<60000 ; i++)
			for(int j=0 ; j<110 ; j++)
				d[i][j]=-1;
		int n,sum=0; cin >> n;
		for(int i=0 ; i<n ; i++){ cin >> a[i]; sum+=a[i];}
		int ans=2*calc(sum/2+sum%2,n)-sum%2;
		cout << (ans>=0 ? ans : -1*ans) << endl;
	}
	return 0;
}