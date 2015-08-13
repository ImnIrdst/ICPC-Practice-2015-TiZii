#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <sstream>
#define INF (int)1e9
#define mx (int)1e6
#define int64 long long

using namespace std;

int p, sl, d;
int pos[mx+10], snk[mx+10];

int main(){
	int tc; cin >> tc;
	while(tc--){
		cin >> p >> sl >> d;
		memset(snk,-1,sizeof snk);
		for(int i=0 ; i<mx+10 ; i++) pos[i]=1; 
		
		int h,t;
		for(int i=0 ; i<sl ; i++){
			cin >> h >> t; snk[h]=t;
		}
		int dnum; int flag=0;
		for(int i=0 ; i<d ; i++){
			cin >> dnum;
			if(flag || pos[i%p]+dnum>100) continue;
			
			pos[i%p]+=dnum;
			if(snk[pos[i%p]]!=-1) pos[i%p]=snk[pos[i%p]];
			if(pos[i%p]==100) flag=1;
		}
		for(int i=0 ; i<p ; i++){
			printf("Position of player %d is %d.\n", i+1, pos[i]);
		}
	}
	return 0;
}