//UVa 357 - Let Me Count The Ways - AC
#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <math.h>
#include<vector>
#include <fstream>
#define INF (long long)1e9
//#define cin fin

using namespace std;

long long d[30003][5], c[]={1,5,10,25,50};

long long solve(long long w, long long coin){
	if(w<0) 
		return 0;
	if(w==0) 
		return 1;
	if(d[w][coin]!=-1)
		return d[w][coin];
	long long cnt=0;
	for(long long i=4 ; i>=0 ; i--){
		if(c[i]<=c[coin])
			cnt+=solve(w-c[i],i);
		/*long long x=solve(w-c[i]);
		if(x!=-1)
			cnt+=x;*/
	}
	return d[w][coin]=cnt;
}

int main(){
	//ifstream fin("in.txt");
	long long n;
	for(long long i=0 ; i<30003 ; i++)
		for(long long j=0 ; j<5 ; j++) d[i][j]=-1;
	while(cin >> n){
		long long ans=solve(n,4);
		if(ans==1 || n==0)
			cout << "There is only " << 1 << " way to produce "<< n <<" cents change." << endl;
		else
			cout << "There are " << ans << " ways to produce "<< n <<" cents change." << endl;
		n=n;
	}
	return 0;
}