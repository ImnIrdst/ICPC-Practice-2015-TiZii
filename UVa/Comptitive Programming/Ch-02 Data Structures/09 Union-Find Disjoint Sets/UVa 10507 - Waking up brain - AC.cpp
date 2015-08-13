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

int a[30][30],awake[30]; // a == graph

int main(){
	int n,m; string str;
	while(cin >> n >> m){
		cin >> str; memset(a,0,sizeof a); memset(awake,0,sizeof awake);
		for(int i=0 ; i<3 ; i++) awake[str[i]-'A']=1;
		for(int i=0 ; i<m ; i++){
			char x,y; cin >> x >> y;
			a[x-'A'][y-'A']=1; a[y-'A'][x-'A']=1;
		}
		bool hasAns=false; int years;
		for(years=0 ; years<n ; years++){
			int tmpawake[30]={0}; 
			if(count(awake,awake+30,1)==n){ hasAns=true; break;}
			for(int i=0 ; i<30 ; i++){
				if(awake[i]) continue; int cnt=0;
				for(int j=0 ; j<30 ; j++){
					if(a[i][j] && awake[j]){
						cnt++;
					}
				}
				if(cnt>=3) 
					tmpawake[i]=1;
			}
			for(int i=0 ; i<30 ; i++){
				if(tmpawake[i]) awake[i]=1;
			}
		}
		if(hasAns) printf("WAKE UP IN, %d, YEARS\n", years);
		else printf("THIS BRAIN NEVER WAKES UP\n");
	}
	return 0;
}