#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <math.h>
#include<vector>
#include <fstream>
//#define cin fin
using namespace std;

int a[110][110];

int main(){
	//ifstream fin("in.txt");
	int n;
	while(cin >> n){
		//init
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<n ; j++){
				cin >> a[i][j];
			}
		}
		//preprocess
		for(int i=1 ; i<n ; i++){
			for(int j=0 ; j<n ; j++){
				a[i][j]+=a[i-1][j];
			}
		}
		//calc
		int Max=0, ans=0;
		for(int k=0 ; k<n ; k++){
			for(int i=0 ; i<n-k ; i++){
				Max=0;
				for(int j=0 ; j<n ; j++){
					if(Max<0)
						Max=a[i+k][j]-a[i][j];
					else
						Max+=a[i+k][j]-a[i][j];
					if(Max>ans)
						ans=Max;
				}
			}
		}
		cout << ans << endl;
	}
	return 0;
}
