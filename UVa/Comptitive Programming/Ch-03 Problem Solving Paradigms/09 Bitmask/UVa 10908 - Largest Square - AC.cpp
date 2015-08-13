#include <iostream>

using namespace std;

int n , m , q; 
int i1, i2, j1, j2;
char a[100+10][100+10];

int inRange(int i, int j){
	//cout << i << "*" << j << endl;
	return (i>=0 && i<n && j>=0 && j<m);
}

int isSquare(char c){
	//cout << i1  << " " << i2 << " " << j1 << " " << j2 << endl; 
	//cout << inRange(i1,j1) << "," << inRange(i2,j2) << endl;
	if(!inRange(i1,j1) || !inRange(i2,j2)) 
		return false;
	for(int i=i1 ; i<=i2 ; i++){
		for(int j=j1 ; j<=j2 ; j++){
			if(a[i][j]!=c) return false;
		}
	}
}

int main(){
	int tc; cin >> tc;
	while(tc--){
		cin >> n >> m >> q;
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<m ; j++){
				cin >> a[i][j];
			}
		}
		cout << n  << " " << m << " " << q << endl;

		int r, c;
		while(q--){
			int ans=0;  cin >> r >> c;
			i1=r, i2=r, j1=c, j2=c;
			while(isSquare(a[r][c])){
				i1--, i2++, j1--, j2++; ans+=2;
			}
			cout << ans-1 << endl;
		}
	}
}