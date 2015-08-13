#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <math.h>
#include<vector>
#include <fstream>
#include <map>
#include <sstream>
//#define cin fin
#define INF (int) 1e6

using namespace std;

int d, i; 

int solve(int node, int rem){
	int l=node*2, r=node*2+1;
	if(l < (1<<d) && r < (1<<d)){
		if(rem%2) return solve(l,rem/2+1);
		else return solve(r,rem/2);
	}
	else return node;
}

int main(){
	//ifstream fin("in.txt");
	int tc; cin >> tc;
	while(tc--){
		cin >> d >> i;
		cout << solve(1,i) << endl;
	}
	return 0;
}