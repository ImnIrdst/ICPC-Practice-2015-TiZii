#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <vector>
#define INF (int)1e9
#define int64 long long

using namespace std;

int a[10010]; long long sum,Min;;

int main(){
	int n;
	while(cin >> n && n){
		for(int i=0 ; i<n ; i++) scanf("%d",&a[i]);
		sort(a,a+n, ::greater<int>() );
		bool possible=true; sum=0;
		for(int i=0 ; i<n ; i++){
			sum+=a[i]; Min=0;
			for(int j=i+1 ; j<n; j++) Min+=min(a[j],i+1);
			if(sum>i*(i+1)+Min){
				possible=false;
				break;
			}
		}
		if(!possible || sum%2) cout << "Not possible" << endl;
		else cout << "Possible" << endl;
	}
	return 0;
}