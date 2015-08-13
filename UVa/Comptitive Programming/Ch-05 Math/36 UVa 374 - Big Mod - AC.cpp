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

int8 poww(int8 b,int8 p,int8 m){
	if(p==0) return 1;
	if(p==1) return b%m;
	int ans=(poww(b,p/2,m)%m);
	if(p%2==0) return (ans*ans)%m;
	ans*=(poww(b,p/2+p%2,m)%m);
	return ans%m;
}

int main(){
	//ifstream fin("in.txt");
	int a,b,m;
	while(cin >> a >> b >> m){
		cout << poww(a,b,m) << endl;
	}
	return 0;
}