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

int cord[100+10], cap[100+10], n, m; // cap -> capacity

int main(){
	int tc,t=1; cin >> tc;
	while(tc--){
		cin >> n >> m; char c[2]; int d,top=2,ans=0;
		cord[0]=cord[1]=0;
		for(int i=0 ; i<n ;i++){
			scanf("%1s-%d", c, &d); 
			cord[top++]=d; if(c[0]=='B') cord[top++]=d;
		}
		cord[top++]=m; cord[top++]=m;
		for(int i=0; i<top-2 ; i++){
			ans=max(ans,cord[i+2]-cord[i]);
		}
		printf("Case %d: %d\n",t++,ans);
	}
	return 0;
}