#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <vector>
#define eps (double)1e-9
#define INF (int)1e9
#define p pair<int,int>
#define X first
#define Y second

using namespace std;

p a[10], ansSF; int n,path[10][1<<10],ans[10][1<<10], snode, fnode; // snode == start node, fnode == finish node
double dp[10][1<<10];
int abss(int a){ return (a>0 ? a : -1*a); } double fabss(double a){ return (a>0 ? a : -1*a); }
double dist(p a, p b){ int x=a.X-b.X, y=a.Y-b.Y; return sqrt(x*x+y*y)+16.; }
int allone(int bitset){int cnt=0; for(int i=0 ; i<n ; i++) if(bitset&(1<<i)) cnt++; return cnt==n-1;}

double solve(int pos, int bitset){
	double& dpp=dp[pos][bitset];
	if(allone(bitset)) return dist(a[pos],a[fnode]);
	if(fabss(dpp+1)<eps) return dpp;
	dpp=INF;
	for(int i=0 ; i<n ; i++){
		if(!(bitset&(1<<i)) && i!=fnode){
			double slv=solve(i,bitset|(1<<i))+dist(a[pos],a[i]);
			if(dpp>slv){
				dpp=slv; path[pos][bitset]=i;
			}
		}
	}
	return dpp;
}

void print(int i,int bitset){
	if(allone(bitset)){ printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n",
		a[i].X, a[i].Y, a[ansSF.Y].X, a[ansSF.Y].Y, dist(a[i],a[ansSF.Y])); return;}
	int next=ans[i][bitset];
	printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n",
		a[i].X, a[i].Y, a[next].X, a[next].Y, dist(a[i],a[next])); 
	print(next, bitset|(1<<next));
}

int main(){
	int t=1;
	while(cin >> n && n){
		for(int i=0 ; i<n ; i++) cin >> a[i].X >> a[i].Y;
		//cout << dist(a[0],a[1]) << endl;
		double Min=INF;  // answer start and finish node
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<n ; j++){
				if(i!=j){
					snode=i; fnode=j;
					memset(dp,-1,sizeof dp);
					double slv=solve(snode,1<<snode);
					if(slv+0.01<=Min){
						Min=slv; ansSF=p(snode,fnode);
						for(int i=0 ; i<n ; i++){
							for(int j=0 ; j<(1<<n) ; j++){
								ans[i][j]=path[i][j];
							}
						}
						//print(ansSF.X, 1<<ansSF.X);
					}
				}
			}
		}
		printf("**********************************************************\n");
		printf("Network #%d\n",t++); print(ansSF.X, 1<<ansSF.X);
		printf("Number of feet of cable required is %.2lf.\n",Min);
	}
	return 0;
}