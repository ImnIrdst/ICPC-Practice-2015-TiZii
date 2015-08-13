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
#define MAX 20

using namespace std;

double adj[MAX+10][MAX+10][MAX+10]; int path[MAX+10][MAX+10][MAX+10], n;


int main(){
	while(cin >> n){
		for(int k=0 ; k<n ; k++){
			for(int i=0 ; i<n ; i++){
				for(int j=0 ; j<n ; j++){
					if(i!=j) adj[k][i][j]=0; else adj[k][i][j]=1.0;
					path[k][i][j]=i;
				}
			}
		}
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<n ; j++){
				if(i!=j) cin >> adj[0][i][j];
			}
		}
		for(int s=1 ; s<n ; s++){
			for(int k=0 ; k<n ; k++){
				for(int i=0 ; i<n ; i++){
					for(int j=0 ; j<n ; j++){
						if(adj[s][i][j]<adj[s-1][i][k]*adj[0][k][j]){
							adj[s][i][j]=adj[s-1][i][k]*adj[0][k][j];
							path[s][i][j]=k;
						}
					}
				}
			}
		}
		bool found=false; int out[MAX];
		for(int s=1; s<n && !found ; s++){
			for(int i=0 ; i<n && !found ; i++){
				if(adj[s][i][i]>1.01){
					out[s]=path[s][i][i];
					for(int j=s-1 ; j>=0 ; j--) out[j]=path[j][i][out[j+1]];
					for(int j=0 ; j<=s ; j++) cout << out[j]+1 << " ";
					cout << i+1 << endl; found=true; break;
				}
			}
		}
		if(!found) cout << "no arbitrage sequence exists" << endl;
	}
	return 0;
}