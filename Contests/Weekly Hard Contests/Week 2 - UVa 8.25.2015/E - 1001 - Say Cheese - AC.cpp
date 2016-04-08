#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
#include<functional>
using namespace std;

struct Sphere{
	int x, y, z, r;
	Sphere(int x = 0,int  y = 0,int z = 0,int r = 0) : x(x), y(y), z(z), r(r){}
	double Dist(const Sphere& op) const
	{
		double dx = x - op.x;
		double dy = y - op.y;
		double dz = z - op.z;
		double dist2 = dx*dx + dy*dy + dz*dz;
		double dist = sqrt(dist2);
		if (dist <= r + op.r) return 0;
		return dist - (r + op.r);
	}
};

typedef Sphere Point;

double adjmtx[110][110];

int main()
{
	int n;
	int cs = 1;
	while (cin >> n && n != -1){
		n += 2;
		vector<Sphere> sp(n);
		for (int i = 0; i < n; ++i){
			cin >> sp[i].x >> sp[i].y >> sp[i].z;
			if(i < n - 2) cin >> sp[i].r;
		}
		//construct graph
		for (int i = 0; i < n; ++i){
			for (int j = i; j < n; ++j){
				adjmtx[i][j] = adjmtx[j][i] = 10*sp[i].Dist(sp[j]);
			}
		}
		//floyd -warshall
		for (int k = 0; k < n; ++k){
			for (int i = 0; i < n; ++i){
				for (int j = 0; j < n; ++j){
					adjmtx[i][j] = min(adjmtx[i][j], adjmtx[i][k] + adjmtx[k][j]);
				}
			}
		}
		//output
		printf("Cheese %d: Travel time = %.0f sec\n", cs++, adjmtx[n-2][n-1]);
	}
	return 0;
}