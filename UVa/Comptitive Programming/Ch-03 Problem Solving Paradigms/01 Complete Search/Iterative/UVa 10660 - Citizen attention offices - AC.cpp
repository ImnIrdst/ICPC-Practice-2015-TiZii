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

const int N=25,M=5;

int dist(int a, int b){
	return abs(a/M-b/M)+abs(a%M-b%M);
}

int main(){
	int tc; cin >> tc;
	while(tc--){
		int n, city[N]={0}; cin >> n;
		int x,y,ppl;
		for(int i=0 ; i<n ; i++){
			cin >> x >> y >> ppl; city[x*M+y]=ppl;
		}
		int ans[5],Min=INF;
		for (int a=0   ; a<N-4 ; a++){
		for (int b=a+1 ; b<N-3 ; b++){
		for (int c=b+1 ; c<N-2 ; c++){
		for (int d=c+1 ; d<N-1 ; d++){
		for (int e=d+1 ; e<N   ; e++){
			int tmpAns[5]={a,b,c,d,e}, sum=0;
			for(int i=0 ; i<N ; i++){
				if(!city[i]) continue;
				int tmpDist=INF;
				for(int j=0 ; j<M ; j++){
					tmpDist=min(tmpDist,dist(i,tmpAns[j]));
				}
				tmpDist*=city[i]; sum+=tmpDist;
			}
			if(sum<Min){
				Min=sum;
				for(int i=0 ; i<M ; i++) ans[i]=tmpAns[i];
			}
		}}}}}
		bool first=true;
		for(int i=0 ; i<M ; i++){
			if(!first) cout << " "; first=false;
		 	cout << ans[i];
		}
		cout << endl;
	}

	return 0;
}