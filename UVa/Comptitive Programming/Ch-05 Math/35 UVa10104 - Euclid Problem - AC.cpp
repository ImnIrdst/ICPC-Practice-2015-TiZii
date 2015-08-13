#include <iostream>
#include <math.h>
#include <algorithm>
#include <fstream>
#include <string>
#include <map>
#define int8 long long
//#define cin fin
#define INF (int)1e9

using namespace std;

int x,y,d;

void extendedEuclid(int a, int b){
	if(b==0){x=1; y=0; d=a; return;}
	extendedEuclid(b,a%b);
	int x1=y;
	int y1=x-(a/b)*y;
	x=x1; y=y1;
}

int main(){
	//ifstream fin("in.txt");
	int n,m,c;
	while(cin >> n >> m){
		extendedEuclid(n,m);
		printf("%d %d %d\n", x, y, d);
	}
	return 0;
}