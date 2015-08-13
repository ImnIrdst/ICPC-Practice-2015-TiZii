#include <iostream>
#include <stdio.h>
#include <set>
#include <string.h>
#include <algorithm>
#include <climits>
#include <cmath>
#define MAX (5842+10)

using namespace std;

long long h[MAX];

int main(){
	int n; set<long long> pq; pq.insert(1);
	for(int i=1 ; i<MAX ; i++){
		long long a=*(pq.begin()); pq.erase(pq.begin());
		pq.insert(2*a); pq.insert(3*a);
		pq.insert(5*a); pq.insert(7*a);
		h[i]=a;
	}
	while(cin >> n && n){
		
		printf("The %d",n);
		if(n%10==1 && (n/10)%10!=1) printf("st");
		else if(n%10==2 && (n/10)%10!=1) printf("nd");
		else if(n%10==3 && (n/10)%10!=1) printf("rd");
		else printf("th");
		printf(" humble number is %d.\n",h[n]);
	}
}