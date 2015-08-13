#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <sstream>
#define INF (int)1e9
#define int64 long long

using namespace std;

struct hotel{
	int bed,cost;
	hotel(){}
	hotel(int b,int c){bed=b; cost=c;}
}a[20]; // a = array of hotels

bool cmp(hotel a, hotel b){
	return a.cost<b.cost;
}

int main(){
	int p,b,h,w;
	while(cin >> p >> b >> h >> w){
		for(int i=0 ; i<h ; i++){
			int cost, tmp, bed=0; cin >> cost;
			for(int j=0 ; j<w ; j++){
				cin >> tmp; bed=max(bed,tmp);
			}
			a[i]=hotel(bed,cost);
		}
		sort(a,a+h,cmp); int flag=1;
		for(int i=0 ; i<h ; i++){
			if(a[i].bed>=p && a[i].cost*p<=b){
				cout << a[i].cost*p << endl;
				flag=0; break;
			}
		}
		if(flag) cout << "stay home" << endl;
	}
	return 0;
}