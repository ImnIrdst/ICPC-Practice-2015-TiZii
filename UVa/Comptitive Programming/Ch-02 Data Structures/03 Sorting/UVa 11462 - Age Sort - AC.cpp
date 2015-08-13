#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
//#define cin fin
#define MAX (int)1e8

using namespace std;

int a[MAX]; float b[MAX];

int main(){
	//ifstream fin("in.txt");
	long long tc; cin >> tc;
	while (tc--){

		for(int i=0 ; 1 ; i++){
			cin >> a[i]; 
			char c; c=getchar();
			if(c=='\n')
				break;
		}
		int i=0;
		for(i=0 ; 1 ; i++){
			float tmp; cin >> tmp;
 			b[a[i]-1]=tmp;
			char c; c=getchar();
			if(c=='\n')
				break;
			
		}
		int n=i+1;
		for(int i=0; i<n ; i++){
			printf("%.1f\n", b[i]);
		}
	}
}