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
#include <queue>
//#define cin fin
#define pxy pair<int, int>
#define x first
#define y second
#define INF (int)1e9
#define MAX (int)1e6+10
#define p pair<int , int>
#define x first
#define y second

using namespace std;

int n, m, dist[1010];
vector<p> a[1010];
int main(){
	int tc; cin >> tc;
	while(tc--){
		cin >> n >> m;
		for(int i=0 ; i<n ; i++){
			a[i].clear(); dist[i]=INF;
		}
		int a1,a2,a3;
		for(int i=0 ; i<m ; i++){
			cin >> a1 >> a2 >> a3;
			a[a1].push_back(p(a2,a3));
		}
		p v;
		dist[0]=0;
		for(int k=0 ; k<n ; k++){
			for(int u=0 ; u<n ; u++){
				for(int j=0 ; j<a[u].size() ; j++){
					v=a[u][j];
					if(dist[v.x]>dist[u]+v.y){
						dist[v.x]=dist[u]+v.y;
					}
				}
			}
		}
		bool negcyc=0;
		for(int u=0 ; u<n ; u++){
			for(int j=0 ; j<a[u].size() ; j++){
				v=a[u][j];
				if(dist[v.x]>dist[u]+v.y){
					negcyc=1;
				}
			}
		}
		cout << (negcyc ? "possible" : "not possible") << endl;
	}
}