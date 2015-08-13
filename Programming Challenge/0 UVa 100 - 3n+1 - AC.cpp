#include <algorithm>
#include <cstdio>

using namespace std;

long long solve(long long i){
		long long c=1;
		while(i!=1){
			if(i%2==0) i=i/2;
			else i=i*3+1;
			c++;
		}
	return c;
}

int main(){
	int a,b;
	while(scanf("%d %d", &a, &b)!=EOF){
		printf("%d %d ", a, b);
		if(a>b) swap(a,b);
		
		long long Max=0;
		for(long long i=a ; i<=b ; i++){
			Max=max(solve(i),Max);
		}
		printf("%d\n", Max);
	}
	return 0;
}