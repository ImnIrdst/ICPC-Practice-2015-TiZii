#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Pt{
	double x, y;
	Pt(double x = 0, double y = 0):x(x), y(y){}
};

double dist(Pt a, Pt b){
	return hypot(a.x - b.x , a.y - b.y);
}

int main(){
	int tc;
	cin >> tc;
	
	while (tc--){
		int n = 0;
		Pt p[200 + 10];
		cin >> p[n].x >> p[n].y; n++;
		cin >> p[n].x >> p[n].y; n++;
		double adj[200 + 10][200 + 10] = { 0 };

		
		string line;
		getline(cin, line); // ignore;
		while (getline(cin, line) && line.size()){
			stringstream sstr(line);

			sstr >> p[n].x >> p[n].y; n++;
			while (sstr >> p[n].x >> p[n].y && (p[n].x != -1 || p[n].y != -1)){
				adj[n - 1][n] = adj[n][n - 1] = dist(p[n - 1], p[n]); n++;
			}
		}
		for (int i = 0; i < n; i++){
			for (int j = 0; j < n; j++){
				if (fabs(adj[i][j]) < 1e-9) adj[i][j] = dist(p[i], p[j])*4;
			}
		}

		for (int k = 0; k < n; k++){
			for (int i = 0; i < n; i++){
				for (int j = 0; j < n; j++){
					adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
				}
			}
		}

		printf("%.0lf\n", (adj[0][1] * 6) / 4000.0); if (tc) printf("\n");
	}
}