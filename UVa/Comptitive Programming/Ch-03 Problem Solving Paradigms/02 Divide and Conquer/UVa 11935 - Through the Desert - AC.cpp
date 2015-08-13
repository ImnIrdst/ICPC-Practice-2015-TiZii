#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <bitset>
#include <set>
#define INF (double)1e9
#define eps (double)1e-9

using namespace std;

struct ev{
	double cord,val;
	string state;
}events[50+10];

double initCons ,finish; int n;

bool check(double mid){
	double cons=initCons, prevCord=0,leak=0; double fuel=mid; 
	for(int i=0 ; i<n ; i++){
		double dist=events[i].cord-prevCord;
		fuel-=(dist/100.)*cons+leak*dist;
		if(fuel<0) return false;
		if(events[i].state=="consumption") cons=events[i].val;
		if(events[i].state=="Mechanic") leak=0;
		if(events[i].state=="Leak") leak++;
		if(events[i].state=="station") fuel=mid;
		prevCord=events[i].cord;
	}
	double dist=finish-prevCord;
	fuel-=(dist/100.)*cons+leak*dist;
	if(fuel<0) return false;
	return true;
}

int main(){
	double cord,val; string str;
	while(cin >> initCons >> str >> str >> initCons && initCons){
		n=0;
		while(cin >> cord >> str && str!="Goal"){
			if(str=="Fuel") cin >> str >> val;
			if(str=="Gas") cin >> str;
			events[n].cord=cord; events[n].state=str; events[n++].val=val;
		}
		double left=0, right=10000.0, mid; finish=cord;
		for(double i=0 ; right-left>eps && i<50 ; i++){
			mid=(right+left)/2;
			if(check(mid)) right=mid;
			else left=mid+0.00001;
		}
		printf("%.3lf\n",right);

	}
	return 0;
}