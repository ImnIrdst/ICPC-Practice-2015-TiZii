#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <sstream>
#include <vector>
#define INF (int)1e9
#define int64 long long

using namespace std;

vector<int> cycs;// cycles

bool check(int t){
	int cnt=0, orngs=0;
	for(int i=0 ; i<cycs.size() ; i++){
		if(t%(2*cycs[i]) < (cycs[i]-5)) cnt++;
		if(t>cycs[i]) orngs++;
	}
	return (cnt==cycs.size() && orngs);
}

int main(){
	int a,b,c; // total seconds;
	while(cin >> a >> b >> c && (a || b || c)){
		int totsecs=-1;
		cycs.clear(); cycs.push_back(a); cycs.push_back(b);
		while(c!=0){cycs.push_back(c); cin >> c;}
		for(int i=1 ; i<=3600*5 ; i++){
			if(check(i)){
				totsecs=i;
				break;
			}
		}
		if(totsecs!=-1){
			printf("%02d:",totsecs/3600); totsecs%=3600;
			printf("%02d:",totsecs/60); totsecs%=60;
			printf("%02d\n",totsecs);
		}
		else printf("Signals fail to synchronise in 5 hours\n");
	}
	return 0;
}