#include <iostream>
#include <stdio.h>
#include <set>
#include <string.h>
#include <algorithm>
#include <climits>
#include <cmath>
#define MAX (5842+10)

using namespace std;

struct ratio{
	int a,b; ratio(){} ratio(int A, int B){a=A, b=B;}
};

struct cmp{
	bool operator()(ratio x, ratio y){ return x.a*y.b<y.a*x.b; }
};

int gcd(int a, int b){
	if(b==0) return a;
	else return gcd(b,a%b);
}

int main(){
	int n,k; //cout << gcd(8,5) << endl;
	while(cin >> n >> k){
		set<ratio,cmp> st;
		for(int i=1 ; i<=n ; i++){
			for(int j=i+1 ; j<=n ; j++){
				if(gcd(i,j)==1) st.insert(ratio(i,j));
			}
		}
		st.insert(ratio(1,1)); ratio ans; int i=1;
		for(set<ratio>::iterator itr=st.begin() ; itr!=st.end() ; itr++, i++){
			//printf("%d/%d\n",itr->a, itr->b);
			if(i==k){
				ans=*itr; break;
			}
		}
		printf("%d/%d\n",ans.a, ans.b);
	}
}
