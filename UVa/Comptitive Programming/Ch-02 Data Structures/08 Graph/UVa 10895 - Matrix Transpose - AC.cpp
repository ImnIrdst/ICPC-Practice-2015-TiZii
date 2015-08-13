#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <vector>
#define INF (int)1e9
#define p pair< pair<int,int> , int>
#define x first.first
#define y first.second
#define w second

using namespace std;

int eachrow[10010]; p a[10010]; // a = transpose matrix

int main(){
	int n,m,k;
	while(cin >> n >> m){//wrong
		k=0;
		for(int i=1 ; i<n+1 ; i++){
			int nn; cin >> nn;
			for(int j=0 ; j<nn ; j++){
				a[k].y=i;
				cin >> a[k++].x;
			}
			k-=nn;
			for(int j=0 ; j<nn ; j++){
				cin >> a[k++].w;
			}
		}
		sort(a,a+k);
		memset(eachrow,0,sizeof eachrow);
		for(int i=0 ; i<k ; i++){
			eachrow[a[i].x]++;
		}
		k=0;
		cout << m << " " << n << endl;
		for(int i=1 ; i<m+1 ; i++){
			cout << eachrow[i];
			for(int j=0 ; j<eachrow[i] ; j++){
				cout << " " << a[k++].y;
			}
			k-=eachrow[i]; cout << endl;
			bool first=true;
			for(int j=0 ; j<eachrow[i] ; j++){
				if(!first) cout << " "; first=false;
				cout << a[k++].w;
			}
			cout << endl;
		}
	}
	return 0;
}