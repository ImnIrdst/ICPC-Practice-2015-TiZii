#include <iostream>
#include <stdio.h>
#include <cmath>
#define int64 long long
#define MAX (100+10)
using namespace std;

int64 cube(int64 x){return x*x*x;}

int main(){
	int n;
	while(cin >> n && n){
		int64 y=0,x=0; bool found=0;
		for(y=0 ; y<(int64)1e5 && !found ; y++){
			int64 lo=0, hi=(int64)1e6, plo=-1, phi=-1, y3=cube(y);
			while(lo<hi && !found){
				int64 mid  = (lo+hi)/2;
				int64 x3   = cube(mid);
				
				if(lo==plo && hi==phi) break; 
				plo=lo; phi=hi;
				
				if(n==x3-y3) x=mid, found=1;
				if(n>x3-y3) lo=mid; else if(n<x3-y3) hi=mid;
			}
			if(n==cube(lo)-y3) x=lo, found=1;
		}
		if(y==(int)1e5) cout << "No solution" << endl;
		else			cout << x << " " << y-1 << endl;
	}
	return 0;
}
