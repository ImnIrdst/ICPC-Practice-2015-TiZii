#include <iostream>
#include <math.h>
#include <algorithm>
#include <fstream>
#include <string>
#include <map>
#define int8 long long
//#define cin fin
#define INF (double)1e9

using namespace std;

int a[110],n; double b,r,v,e,f;
double d[110];

double time(int x){
	if(x>=r)
		return 1.0/(v-e*(x-r));
	return 1.0/(v-f*(r-x));
}

double calc(int x, int y){
	double ans=0;
	for(int k=0 ; k<a[y]-a[x] ; k++) 
		ans+=time(k);
	return ans+(x!=0)*b;
}

double solve(int c){
	if(c==0) return 0;
	if(d[c]>=-0.5) return d[c];
	double ans=INF, deb; 
	for(int i=0 ; i<c ; i++){
		ans=min(ans,deb=(solve(i)+calc(i,c)));
	}
	return d[c]=ans;
}

int main(){
	//ifstream fin("in.txt");
	while(cin >> n && n){
		for(int i=0 ; i<110; i++) d[i]=-1;
		a[0]=0;
		for(int i=1 ; i<=n ; i++) cin >> a[i];
		cin >> b >> r >> v >> e >> f;
		printf("%.4lf\n",solve(n));
	}
	return 0;
}
