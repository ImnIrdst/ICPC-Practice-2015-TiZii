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

int a[101];//array of visited citys

int main(){
	int n;
	while(cin >> n && n){
		int flag=1;
		
		for(int m=1 ; flag ; m++){
			for(int i=0 ; i<n ; i++) a[i]=0;
			int idx=0; a[idx]=1;
			for(int cnt=0 ; cnt<n-1 ; cnt++){
				int i=0,j=0;
				for(i=1 ; j<m ; i++){
					if(!a[(idx+i)%n]){
						j++;
					}
				}
				idx+=i-1; idx%=n;
				a[idx]=1;
			}
			if(idx==12){
				flag=0; 
				cout << m << endl;
			}
		}
	}
	return 0;
}