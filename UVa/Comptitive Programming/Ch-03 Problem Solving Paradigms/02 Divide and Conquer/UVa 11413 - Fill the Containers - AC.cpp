#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <bitset>
#include <set>
#define INF (int)1e9

using namespace std;

int a[1000+10],n,m;

int main(){
	while(cin >> n >> m){
		int left=0,right=0,mid=0,sum,i,j; bool flag;
		for(int i=0 ; i<n ; i++){cin >> a[i]; right+=a[i]; left=max(left,a[i]);}
		while(left<right){
			mid=(left+right)/2; flag=true; sum=0;
			for(i=0, j=0; i<n ; i++){
				if(sum+a[i]>mid) sum=0, j++;
				if(j>=m){ flag=false; break; }
				sum+=a[i];
			}
			if(flag) right=mid;
			else left=mid+1;
		}
		cout << right << endl;
	}
	return 0;
}