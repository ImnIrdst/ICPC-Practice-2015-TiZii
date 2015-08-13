#include <iostream>
#include <math.h>
#include <algorithm>
#define g 10
#define err 0.0000001

using namespace std;

struct ant{
	ant(){}
	ant(int a, int b, int c){ l=a; w=b; h=c; v=a*b*c; }
	int h,w,l,v;
}ants[100];


int cmp(ant a, ant b){
	if(a.h > b.h) return 1;
	else if(a.h==b.h && a.v > b.v) return 1;
	return 0; 
}

int main(){
	int n; cin >> n;
	while(n){
		for(int i=0 ; i<n ; i++){
			int a,b,c; cin >> a >> b >> c;
			ants[i]=ant(a,b,c);
		}
		sort(ants,ants+n,cmp);

		cout << ants[0].v << endl;
		cin >> n;
	}
	return 0;
}