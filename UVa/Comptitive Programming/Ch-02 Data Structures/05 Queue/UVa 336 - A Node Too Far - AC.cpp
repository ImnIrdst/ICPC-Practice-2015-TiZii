#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <fstream>
#include <string>
#include <string.h>
#include <map>
#include <sstream>
#include <stack>
//#define cin fin
#define INF (int)1e9

using namespace std;

int a[40][40], mark[40], fw[40][40];

int main(){
	//ifstream fin("in.txt");
	int n; int flag=0; int tc=1;
	while(cin >> n && n!=0){		
		int tmp1, tmp2, cnt=1;
		map<int, int> mp;
		for(int i=0 ; i<40 ; i++){
			for(int j=0 ; j<40 ; j++){
				a[i][j]=0;
				fw[i][j]=INF;
			}
			mark[i]=0;
		}
		for(int i=0 ; i<n ; i++){
			cin >> tmp1 >> tmp2;
			if(!mp[tmp1]){ mp[tmp1]=cnt++; }
			if(!mp[tmp2]){ mp[tmp2]=cnt++; }
			a[mp[tmp1]][mp[tmp2]]=a[mp[tmp2]][mp[tmp1]]=1;
		}
		for(int i=1 ; i<cnt ; i++){
			for(int j=1 ; j<cnt ; j++){
				if(a[i][j])
					fw[i][j]=1;
				if(i==j)
					fw[i][j]=0;
			}
		}
		for(int k=1; k<cnt ; k++){
			for(int i=1 ; i<cnt ; i++){
				for(int j=1; j<cnt ; j++){
					fw[i][j]=min(fw[i][j],fw[i][k]+fw[k][j]);
				}
			}
		}
		int qs, qlev;
		while(cin >> qs >> qlev){
			if(qs==0 && qlev==0) break;
			int ans=0;
			int node=mp[qs];
			for(int i=1 ; i<cnt ; i++){
				if(fw[node][i]<=qlev)
					ans++;
			}
			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n" , tc++ , cnt-ans-1, qs, qlev);
		}
		//tc++;
	}
}