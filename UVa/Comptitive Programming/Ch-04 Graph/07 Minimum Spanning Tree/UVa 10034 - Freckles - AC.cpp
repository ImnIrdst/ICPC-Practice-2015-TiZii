#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>

#define INF (int)1e9
#define MAX 1000
#define pii pair<int,int>
#define pdii pair<double, pii >
#define W first
#define U second.first
#define V second.second

using namespace std;

vector< pdii > E;// e==edges array
int m,n;

vector<int> par,rnk,cnt;

void SetInit(int n){
	par.assign(n,-1); rnk.assign(n,0); cnt.assign(n,1); //par==parent
}

int Find(int a){
	int i=a,j=a,tmp;
	while(par[i]!=-1){ i=par[i]; }
	while(par[j]!=-1){ tmp=par[j]; par[j]=i; j=tmp; } //path compression
	return i;
}
void Uni(int a, int b){
	int A=Find(a),B=Find(b);
	if(A!=B){
		if(rnk[A]<rnk[B]) swap(A,B); // union using rank
		if(rnk[A]==rnk[B]) rnk[A]++;
		par[B]=A;
	}
}

struct pt{ double x, y; pt(double x=0, double y=0):x(x), y(y){} };

double dist(pt a, pt b){ return hypot(a.x-b.x,a.y-b.y); }

int main(){
	int tc; cin >> tc;
	while(tc--){ cin >> n;
		E.clear(); vector<pt> vp(n);
		for(int i=0 ; i<n ; i++){
			cin >> vp[i].x >> vp[i].y; 
		}
		for(int i=0 ; i<n ; i++){
			for(int j=i+1 ; j<n ; j++){
				E.push_back(pdii(dist(vp[i],vp[j]), pii(i,j)));
				
			}	
		}
		sort(E.begin(), E.end()); SetInit(n); double ans=0; int j=0;
		for(int i=0; i<E.size(); i++){
			//cout << E.back().U << " " << E.back().V << " " << E.back().W << endl;
			if(Find(E[i].U)!=Find(E[i].V)){
				Uni(E[i].U,E[i].V); ans+=E[i].W; j++;
			}
		}
		printf("%.2lf\n", ans); if(tc) cout << endl;
	}
	return 0;
}
