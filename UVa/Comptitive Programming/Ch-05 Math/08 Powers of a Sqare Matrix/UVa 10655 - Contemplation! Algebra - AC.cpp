#include <iostream>
#include <vector>

using namespace std;

typedef long long int64;
typedef vector< int64 > vi;
typedef vector< vi > Matrix;

const int size = 2;

Matrix MatrixMul(Matrix a, Matrix b){
	Matrix c(size, vi(size,0));
	for(int i=0 ; i<size ; i++){
		for(int j=0 ; j<size ; j++){
			for(int k=0 ; k<size ; k++){
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	return c;
}

Matrix MatrixPow(Matrix a,int p){
	if(p == 1) return a;
	if(p%2==0){
		a = MatrixPow(a,p/2);
		a = MatrixMul(a,a);
	}
	if(p%2==1){
		a = MatrixMul(a , MatrixPow(a,p-1));
	}
	return a;
}

int main(){
	int64 p, q, n;
	while(cin >> p >> q >> n){
		if(n==0){
			cout << 2 << endl; continue;
		}

		Matrix a(size, vi(size));
		a[0][0]=p; a[0][1]=-q;
		a[1][0]=1; a[1][1]= 0;

		Matrix mat = MatrixPow(a,n);
		int64 ans = mat[1][0]*p + mat[1][1]*2;

		
		cout << ans << endl;
	}
}

//#include <iostream>
//#include <cmath>
//#include <complex>
//
//using namespace std;
//
//typedef long long int64;
//typedef long double ld;
//
//int main(){
//	complex<ld> p=0, q=0; ld n;
//	while(cin >> p >> q >> n){ 
//		complex<ld> a, b; 
//		a = (p + (sqrt(p*p-q.real()*4)))/complex<ld>(2,0) ; 
//		b = (p-a);
//		a = pow(a,n); b = pow(b,n);
//		ld ans = a.real()+b.real();
//		ld s = (ans>=0 ? 1 : -1);
//		cout << (int64)(ans+s*0.0001) << endl;
//	}
//}
