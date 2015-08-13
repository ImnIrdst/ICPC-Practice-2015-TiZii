#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <math.h>
#include<vector>
#include <fstream>
//#define cin fin
#define INF (int) 1e9
using namespace std;

int d[1<<21][5],a[21],n,side,sum=0;

void print(int bit){
	for(int i=0 ; i<8 ; i++){
		if(bit & (1<<i)) 
			cout << "1" ;
		else 
			cout << "0";
	}
}

int calc(int bit, int l, int sum){
	if(bit==(1<<n)-1 && l==4)
		return 1;
	if(l>3) return 0;
	if(d[bit][l]!=-1) 
		return d[bit][l];
	for(int i=0 ; i<n ; i++){
		if(bit & (1<<i)) 
			continue;
		//print(bit); cout << " " << sum << " "  <<  endl;
		if(sum+a[i]<side*(l+1) && calc(bit|(1<<i),l,sum+a[i]) )
			return d[bit][l]=1;
		if(sum+a[i]==side*(l+1) && calc(bit|(1<<i),l+1,sum+a[i]) )
			return d[bit][l]=1;
	}
	//print(bit);
	return d[bit][l]=0;
}

int main(){
	//ifstream fin("in.txt");
	int tc; cin >> tc;
	while(tc--){
		cin >> n; sum=0;
		for(int i=0 ; i<n ; i++) { cin >> a[i]; sum+=a[i];}
		side=sum/4;
		for(int i=0 ; i<(1<<20) ; i++)
			for(int j=0 ; j<4 ; j++)
				d[i][j]=-1;
		if(sum%4==0 && calc(0,0,0) )
			cout << "yes" << endl;
		else
			cout << "no" << endl;
		
		//printf("The minimum cutting is %d.\n",calc(0,n+1));
	}
	return 0;
}