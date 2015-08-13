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

using namespace std;

int s, p; pxy a[510];

struct xyw{
	int x, y; double w;
	xyw(){}
	xyw(int a1,int a2){x=a1; y=a2;
		int dx=a[a1].x-a[a2].x;
		int dy=a[a1].y-a[a2].y;
		w=sqrt(dx*dx+dy*dy);
	}
	xyw(int a1,int a2 ,int a3){
		x=a1; y=a2; w=a3;
	}
};

vector<xyw> v;

int set[510];
int parent(int i){return (i==set[i] ? i : parent(set[i]));}
int uni(int i, int j){set[parent(i)]=parent(j); return 0;}

bool cmp(xyw a, xyw b){
	return a.w < b.w;
}

int main(){
	int tc; cin >> tc;
	while(tc--){
		cin >> s >> p;
		int cnt=0; double sum=0; v.clear();
		for(int i=0 ; i<510 ; i++) set[i]=i;
		for(int i=0 ; i<p ; i++){
			cin >> a[i].x >> a[i].y;
		}
		for(int i=0 ; i<p ; i++){
			for(int j=0 ; j<p ; j++){
				v.push_back(xyw(i,j));
			}
		}
		sort(v.begin(), v.end(),cmp);
		vector<double> ansv;
		for(int i=0 ; cnt<p-1 ; i++){
			if(parent(v[i].x)!=parent(v[i].y)){
				cnt++; sum+=v[i].w;
				uni(v[i].x,v[i].y);
				ansv.push_back(v[i].w);
			}
		}
		printf("%.2lf\n", ansv[p-s-1]);
	}
}