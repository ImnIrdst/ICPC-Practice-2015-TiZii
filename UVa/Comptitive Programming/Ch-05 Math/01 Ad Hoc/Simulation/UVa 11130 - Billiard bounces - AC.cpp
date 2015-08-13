#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int main(){
	double a,b,v,ang,s; double PI=acos(-1);
	while(cin >> a >> b >> v >> ang >> s && (a||b||v||ang||s)){
		double dist=v*s/2; int ansh=0,ansv=0;
		double x=dist*cos((ang/180.)*PI);
		double y=dist*sin((ang/180.)*PI);
		if(x>a/2) ansh=(int)((x-(a/2))/a)+1;
		if(y>b/2) ansv=(int)((y-(b/2))/b)+1;
		printf("%d %d\n", ansh, ansv);
	}
	return 0;
}