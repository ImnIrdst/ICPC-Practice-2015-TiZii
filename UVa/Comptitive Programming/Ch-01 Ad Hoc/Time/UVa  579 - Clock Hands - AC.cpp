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
	double h,m;
	while(scanf("%lf:%lf",&h,&m)){
		if(!h && !m) return 0;
		double ha=(h*30.0)+((m/60.0)*30.0); double ma=(m*6.0);
		double ans1=ha-ma, ans2=ma-ha;
		ans1=(ans1>=0 ? ans1 : 360+ans1); 
		ans2=(ans2>=0 ? ans2 : 360+ans2);
		printf("%.3lf\n",(ans1<ans2 ? ans1 : ans2));
	}
	return 0;
}