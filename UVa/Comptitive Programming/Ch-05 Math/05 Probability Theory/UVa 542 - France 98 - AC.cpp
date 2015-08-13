#include <iostream>
#include <cstdio>
#include <string>
#include <map>

using namespace std;

const int n = 16;

double p[n][n]; map<string, int> mp; string names[n];

int main(){
	for(int i=0 ; i<n ; i++){
		cin >> names[i]; mp[names[i]]=i;
	}
	double ans[n][5]={0};
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<n ; j++){
			cin >> p[i][j]; p[i][j]/=100.0;
		}
		ans[i][0]=1.0;
	}

	for(int r=1, pow2=1 ; r<=4 ; r++, pow2*=2){
		for(int i=0 ; i<16 ; i++){
			int Rid = i/pow2, k1, k2; // k1, k2 == index of teams possible to be chosen to play
			if( Rid % 2 ) k1=Rid*pow2-pow2, k2=k1+pow2; 
			else          k1=Rid*pow2+pow2, k2=k1+pow2;
			for(int k=k1 ; k<k2 ; k++){
				ans[i][r]+=ans[k][r-1]*p[i][k];
			}
			ans[i][r] *= ans[i][r-1];
		}
	}
	for(int i=0 ; i<n ; i++){
		printf("%-10s p=%.2lf%c\n", names[i].c_str(), ans[i][4]*100, '%');
	}
}