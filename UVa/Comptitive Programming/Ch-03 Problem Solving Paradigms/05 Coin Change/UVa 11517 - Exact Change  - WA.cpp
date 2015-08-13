#include <iostream>
#include <math.h>
#include <algorithm>
#include <fstream>
#include <functional>
#define int8 long long
#define p pair<int, int>
#define cost first
#define cnt second
//#define cin fin
//#define cout fout
#define INF (int)1e9

 using namespace std;

int t,n, a[110];
p d[10010][110];

p Min(p& a, p& b){
	if(a.cost<b.cost)
		return a;
	else if( a.cost==b.cost && a.cnt<b.cnt )
		return a;
	return b;
}

p solve(int m, int i, int coins){
	if(m>=t) return p(m,coins);
	if(i<0) return p(INF,INF);
	if(d[m][coins].cost!=-1) return d[m][coins];
	
	p a1=solve(m+a[i],i-1,coins+1),a2=solve(m,i-1,coins);
	p ans=Min(a1,a2);
	
	return d[m][coins]=ans;
}

 int main(){
 	//ifstream fin("in.txt");
	//ofstream fout("out.txt");
 	int tc; cin >> tc;
	while(tc--){
		for(int i=0 ; i<10010 ; i++)
			for(int j=0 ; j<110 ; j++)
				d[i][j].cost=-1;
		cin >> t >> n;
		for(int i=0 ; i<n ; i++) cin >> a[i];
		p ans=solve(0,n-1,0);
		cout << ans.cost << " " << ans.cnt << endl;
	}
 	return 0;
 }
