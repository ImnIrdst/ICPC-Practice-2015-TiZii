#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>

using namespace std;

struct pt{ int x, y; pt(int x=0, int y=0): x(x), y(y){} };

double dist(pt a, pt b){ return hypot(a.x-b.x, a.y-b.y); };

const int MAX = 200+10;

double adj[MAX][MAX]; pt p[MAX];

int main(){
	int n, cs=1;
	while(cin >> n && n){
		for(int i=0 ; i<n ; i++){
			cin >> p[i].x >> p[i].y;
		}
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<n ; j++){
				adj[i][j]=dist(p[i],p[j]);
			}
		}
		for(int k=0 ; k<n ; k++){
			for(int i=0 ; i<n ; i++){
				for(int j=0 ; j<n ; j++){
					adj[i][j] = min(adj[i][j],max(adj[i][k],adj[j][k]));
				}
			}
		}
		printf("Scenario #%d\n", cs++);
		printf("Frog Distance = %.3lf\n\n", adj[0][1]);
	}
}