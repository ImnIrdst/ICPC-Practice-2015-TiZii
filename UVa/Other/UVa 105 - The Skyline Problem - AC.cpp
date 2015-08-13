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

int a[30000]={0};//max height for each coord

int main(){
	int l,r,h;
	for(int i=0 ; i<30000 ; i++) a[i]=-1;
	while(cin >> l >> r >> h){
		for(int i=l ; i<r ; i++){
			a[i+10000]=max(a[i+10000],h);
		}
	}
	int prevh=-1; int flag=0;
	for(int i=0 ; i<30000 ; i++){
		if(!flag++) cout << " ";
		if(a[i]!=prevh){
			cout << i-10000 << " " << a[i];
			prevh=a[i];
		}
	}
	cout << endl;
	return 0;
}