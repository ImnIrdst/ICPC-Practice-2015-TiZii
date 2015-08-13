#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <time.h>
#include <cmath>
#include <vector>
#define INF (int)1e9

using namespace std;

int n,m,sum,a[20+10], s[20+10],tmp,i,j,major,cnt,bitset,top;

int main(){
	int tc; scanf("%d",&tc);
	while(tc--){
		//int start=clock();
		scanf("%d",&n); m=n-1; tmp=0;
		for(i=0 ; i<n ; i++){ scanf("%d",&a[i]); tmp+=a[i]; }
		major=tmp/2; 
		for(i=0 ; i<n ; i++){
			for(j=0, top=0 ; j<n ; j++){
				if(j!=i) s[top++]=a[j];
			}
			cnt=0;
			for(bitset=0 ; bitset<(1<<m) ; bitset++){
				sum=0;
				for(j=0 ; j<m ; j++){
					sum+=s[j]*(((bitset>>j)&1));// using this cause time limit ==>> if(bitset&(1<<j)) sum+=s[j];
				}
				if(sum<=major && sum+a[i]>major) cnt++;
			}
			printf("party %d has power index %d\n", i + 1, cnt);
		}
		printf("\n");
		//cout << clock()-start << endl;
	}
	return 0;
}