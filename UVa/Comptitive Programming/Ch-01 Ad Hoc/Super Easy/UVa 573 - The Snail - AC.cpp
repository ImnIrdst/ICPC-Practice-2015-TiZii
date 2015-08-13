#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <sstream>
#include <set>
#define INF (int)1e9
#define int64 long long

using namespace std;

int main(){
	double h,u,d; double f,eps=(double)1e-9;
	while(cin >> h && h>0){
		cin >> u >> d >> f; f/=100.0; f=u*f;
		double dist=0;
		for(int i=1 ; i<=1000*1000*100 ; i++){
			dist+=u;
			if(dist>h){
				cout << "success on day " << i << endl;
				break;
			}
			dist-=d;
			if(dist<0){
				cout << "failure on day " << i << endl; 
				break;
			}
			u-=f;
			if(u<0) u=0;
		}
	}
	return 0;
}