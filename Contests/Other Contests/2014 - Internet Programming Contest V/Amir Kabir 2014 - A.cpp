#include <iostream>
#include <math.h>
#include <algorithm>
#include <fstream>
//#define cin fin
#define MAX 1000000

using namespace std;

int a[MAX];

int main(){
	//ifstream fin("in.txt");
	int n,i; int cnt=0; a[0]=a[1]=a[2]=0;
	for( i=3 ; cnt<(int)1e8 ; i++){
			cnt += i; 
			a[i]=cnt;
	}
	while(cin >> n){
		for(i = 0 ; i<MAX && a[i]<=n ; i++)
			i=i;
		cout << i-3 << endl;
	}
	return 0;
}