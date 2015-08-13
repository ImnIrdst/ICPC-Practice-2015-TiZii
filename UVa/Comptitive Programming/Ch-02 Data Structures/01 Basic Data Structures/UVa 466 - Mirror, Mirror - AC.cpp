#include <algorithm>
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

typedef vector<char> vc;
typedef vector< vc > vvc;

int n, cs=1;

void Rotate(vvc& p){
	for(int i=0 ; i<n/2 ; i++){
		for(int j=0 ; j<(n+1)/2 ; j++){
			char tmp = p[i][j];
			p[i][j]         = p[n-1-j][i];
			p[n-1-j][i]     = p[n-1-i][n-1-j];
			p[n-1-i][n-1-j] = p[j][n-1-i];
			p[j][n-1-i]     = tmp;
		}
	}
}

void Reflect(vvc& p){
	for(int i=0 ; i<n/2 ; i++){
		for(int j=0 ; j<n ; j++){
			swap(p[i][j], p[n-1-i][j]);
		}
	}
}

void Solve(vvc& org, vvc& pat, int& rot, int& ref){
	while(ref < 2){
		while(rot < 4){
			if(org==pat) return;
			Rotate(org); rot++;
		}
		rot=0; Reflect(org); ref++;
	}
}

int main(){
	while(cin >> n){
		vvc org(n,vc(n)), pat(n, vc(n));
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<n ; j++) cin >> org[i][j];
			for(int j=0 ; j<n ; j++) cin >> pat[i][j];
		}
		int rotate=0, reflect=0;
		Solve(org, pat, rotate, reflect);
		printf("Pattern %d was ", cs++);
		if(reflect == 2) printf("improperly transformed.\n");
		else if(reflect==0){
			if(rotate==0) printf("preserved.\n");
			else printf("rotated %d degrees.\n", 90 * rotate);
		}
		else{
			printf("reflected vertically");
			if(rotate==0) printf(".\n");
			else printf(" and rotated %d degrees.\n", 90 * rotate);
		}
	}
}