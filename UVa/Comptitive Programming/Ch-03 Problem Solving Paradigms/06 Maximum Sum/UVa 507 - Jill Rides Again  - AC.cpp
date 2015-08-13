#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <fstream>
#include <functional>
#define int8 long long
//#define cin fin
//#define cout fout
#define INF (int)1e9

using namespace std;

struct p{
	int val, st, fin;
	p(){}
	p(int x, int y , int z){
		val=x; st=y; fin=z;
	}
};

int t,n, a[30000];

p Max(p& a, p& b){
	if(a.val>b.val)
		return a;
	else if( a.val==b.val && a.fin-a.st>b.fin-b.st )
		return a;
	else if( a.val==b.val && a.fin-a.st==b.fin-b.st && a.st<b.st )
		return a;
	return b;
}

 int main(){
 	//ifstream fin("in.txt");
	//ofstream fout("out.txt");
 	int tc; cin >> tc; t=1;
	while(tc--){
		cin >> n;
		for(int i=1 ; i<n ; i++) cin >> a[i];
		p ans=p(-1,0,0); int sum=0,id=1;
		for(int i=1 ; i<n ; i++){
			if(sum<0){
				sum=0; id=i;}
			sum+=a[i];
			p tmp=p(sum,id,i+1);
			ans=Max(ans,tmp);
			
		}
		if (ans.val == -1 && n!=0)
            printf("Route %d has no nice parts\n", t++);
        else
            printf("The nicest part of route %d is between stops %d and %d\n", t++, ans.st, ans.fin);
	}
 	return 0;
 }