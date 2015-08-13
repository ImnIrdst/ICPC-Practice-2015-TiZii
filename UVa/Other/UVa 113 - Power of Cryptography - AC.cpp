#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#define INF (int)1e9
#define int64 long long
using namespace std;

int main() {
	double n, p;

	while(scanf("%lf\n%lf",&n,&p)!=EOF){
		printf("%.0lf\n",pow(p,1.0/n));
	}

	return 0;
}