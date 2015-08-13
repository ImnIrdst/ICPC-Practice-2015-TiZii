#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <sstream>
#define INF (int)1e9
#define MAX (50+10)
#define pii pair<int,int> 

using namespace std;

int main(){
	int tc,t=1; cin >> tc;
	string str; stringstream sstr;
	while(tc--){
		double t=0,x1,x2,y1,y2,dx,dy; 
		cin >> x1 >> y1; cin.ignore();
		while(getline(cin,str) && str.size()){
			sstr.clear(); sstr << str;
			sstr >> x1 >> y1 >> x2 >> y2;
			dx=x1-x2; dy=y1-y2;
			t+=(sqrt(dx*dx+dy*dy)/20000.0)*2;	
		}
		int ans=(int)(t*60+0.5);
		printf("%d:%02d\n", ans/60, ans%60);
		if(tc) printf("\n");
	}
	return 0;
}