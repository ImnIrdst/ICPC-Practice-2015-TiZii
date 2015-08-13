#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <math.h>
#include<vector>
#include <fstream>
//#define cin fin
#define INF (int) 1e6

using namespace std;

int n, a[1010][1010], d[1010][3], vis[1010], tmp, tmp2;

int calc(int node, int sel){
	if(d[node][sel]!=-1) return d[node][sel];
	vis[node]=1;
	int ans=1-sel;
	for(int i=1 ; i<=n ; i++){
		if(a[node][i] && !vis[i]){
			if(sel){
				ans+=calc(i,0);
			}
			else{
				ans+=min(calc(i,0),calc(i,1));
			}
		}
	}
	vis[node]=0;
	return d[node][sel]=ans;
}

int main(){
	//ifstream fin("in.txt");
	
	while(cin >> n && n ){
		//init
		for(int i=0 ; i<1010 ; i++){
			for(int j=0 ; j<1010 ; j++){
				a[i][j]=0;
			}
			for(int j=0 ; j<3 ; j++){
				vis[i]=0;
				d[i][j]=-1;
			}
		}
		for(int i=1 ; i<=n ; i++){
			cin  >> tmp;
			for(int j=0 ; j<tmp ; j++){
				cin >> tmp2;
				a[i][tmp2]=1;
			}
		}
		//calc
		cout << max(1,min(calc(1,0),calc(1,1))) << endl;
	}
	return 0;
}