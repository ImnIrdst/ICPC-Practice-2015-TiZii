#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <queue>
#define INF (int)1e9
#define MAX 26

using namespace std;

int old[MAX+10][MAX+10],yng[MAX+10][MAX+10],n=26,m,yngS,oldS;

int main(){
	char c1, c2, c3 ,c4; int d;
	while(cin >> m && m){
		for(int i=0 ; i<n ; i++) 
			for(int j=0 ; j<n ; j++) 
				if(i!=j) old[i][j]=yng[i][j]=INF; else old[i][j]=yng[i][j]=0;

		while(m--){
			cin >> c1 >> c2 >> c3 >> c4 >> d;
			if(c1=='Y'){
				yng[c3-'A'][c4-'A']=min(d,yng[c3-'A'][c4-'A']);
				if(c2=='B') yng[c4-'A'][c3-'A']=min(d,yng[c3-'A'][c4-'A']);
			}
			else{
				old[c3-'A'][c4-'A']=min(d,old[c3-'A'][c4-'A']);
				if(c2=='B') old[c4-'A'][c3-'A']=min(d,old[c3-'A'][c4-'A']);
			}
		}
		cin >> c1 >> c2; yngS=c1-'A'; oldS=c2-'A';
		for(int k=0 ; k<n ; k++){
			for(int i=0 ; i<n ; i++){
				for(int j=0 ; j<n ; j++){
					old[i][j]=min(old[i][j],old[i][k]+old[k][j]);
				}
			}
		}
		for(int k=0 ; k<n ; k++){
			for(int i=0 ; i<n ; i++){
				for(int j=0 ; j<n ; j++){
					yng[i][j]=min(yng[i][j],yng[i][k]+yng[k][j]);
				}
			}
		}
		int ans=INF;
		for(int i=0 ; i<n ; i++){
			ans=min(ans,yng[yngS][i]+old[oldS][i]);
		}
		vector<char> v;
		for(int i=0 ; i<n ; i++){
			if(ans==yng[yngS][i]+old[oldS][i]){
				v.push_back(i+'A');
			}
		}
		if(ans==INF) cout << "You will never meet." << endl;
		else{ cout << ans; for(int i=0 ; i<v.size() ; i++) cout << " " << v[i]; cout << endl; }
	}
	return 0;
}