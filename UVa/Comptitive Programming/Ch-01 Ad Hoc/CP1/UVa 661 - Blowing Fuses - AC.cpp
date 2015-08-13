#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
	int n, m, c, cs=1;
	while(cin >> n >> m >> c && (n || m || c)){
		int on[20+2]={0}, cns[20+10];
		for(int i=0 ; i<n ; i++) cin >> cns[i];
		int Max=-1, cur=0; bool blow=0;
		for(int i=0 ; i<m ; i++) {
			int d; cin >> d; d--;
			if(on[d]) cur-=cns[d];
			else	  cur+=cns[d];
			on[d]=1-on[d]; Max=max(Max,cur);
			if(cur > c) blow = 1;
		}
		         printf("Sequence %d\n", cs++);
		if(blow) printf("Fuse was blown.\n");
		else     printf("Fuse was not blown.\nMaximal power consumption was %d amperes.\n", Max);
		printf("\n");
	}
}