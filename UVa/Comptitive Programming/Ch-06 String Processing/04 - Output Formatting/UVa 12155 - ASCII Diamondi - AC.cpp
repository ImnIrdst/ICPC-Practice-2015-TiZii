#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int n, r1, r2, c1, c2, cs=1;

char entry(int i, int j){
	int di = abs(i%(2*n-1) - (n-1));
	int dj = abs(j%(2*n-1) - (n-1));
	if(di+dj >= n) return '.'; 
	else return (di+dj)%26+'a';
}

int main(){
	while(cin >> n >> r1 >> c1 >> r2 >> c2 && n){
		cout << "Case " << cs++ << ":" << endl;
		for(int i=r1 ; i<=r2 ; i++){
			for(int j=c1 ; j<=c2 ; j++){
				cout << entry(i,j);
			}
			cout << endl;
		}
	}
}