#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main(){
	int tc, t=1; cin >> tc;
	while(tc--){
		double d,v,u; cin >> d >> v >> u;
		if(v>=u || u==0 || v==0) printf("Case %d: can't determine\n", t++);
		else{
			double a=d/u, b=d/sqrt(u*u-v*v);
			printf("Case %d: %.3lf\n",t++ ,fabs(a-b));
		}
	}
	
	return 0;
}