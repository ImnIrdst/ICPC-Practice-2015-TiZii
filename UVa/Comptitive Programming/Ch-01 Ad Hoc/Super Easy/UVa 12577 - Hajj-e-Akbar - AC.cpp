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

int main(){
	string str; int t=1;
	while(cin >> str && str!="*"){
		if(str=="Hajj") printf("Case %d: Hajj-e-Akbar", t++);
		else  printf("Case %d: Hajj-e-Asghar\n",t++);
	}
	return 0;
}