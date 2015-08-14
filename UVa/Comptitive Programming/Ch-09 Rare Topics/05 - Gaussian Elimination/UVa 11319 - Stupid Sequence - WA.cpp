#include <iostream>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

const int MAXC = 7, MAXR = 1500; 

struct Matrix{ double mat[MAXR][MAXC+1];
	double* operator[](int i){ return mat[i]; };
};

struct Vector{ double vec[MAXC];
	double& operator[](int i){ return vec[i]; };
};

Vector GaussianElimination(Matrix mat, const int n){
	int i, j, k, l; double t; Vector X;
	for(j = 0; j < n-1 ; j++){ l = j;
		for(i = j+1 ; i<n ; i++){
			if(fabs(mat[i][j]) > fabs(mat[l][j])) l = i;
		}
		for(k = j ; k <= n ; k++){
			swap(mat[j][k], mat[l][k]);
		}
		for(i = j+1 ; i < n ; i++){
			for(k = n ; k >= j ; k--){
				mat[i][k] -= mat[j][k]*mat[i][j]/mat[j][j];
			}
		}
	}
	for(j = n - 1; j >= 0 ; j--){
		for(t=0.0, k=j+1; k<n ; k++) t+=mat[j][k]*X[k];
		X[j] = (mat[j][n] - t) / mat[j][j];
		if(fabs(X[j]) < 1e-9) X[j] = fabs(X[j]);
	}
	return X;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int j; double v;
		Matrix inp; Vector a;
		for(int i = 0 ; i<1500 ; i++){
			cin >> inp[i][7]; inp[i][0] = 1;
			for(j = 1, v = (i+1) ; j<=6 ; j++ , v*=(i+1)){
				inp[i][j] = v;
			}
		}
		Vector X = GaussianElimination(inp, 7);

		bool isSmart = true;
		for(int i=0 ; i<1500 && isSmart ; i++){
			double val = 0;
			for(int j=0 ; j<7 ; j++){
				val += inp[i][j]*X[j];
			}
			if(fabs(val - inp[i][7]) > 1e-3) 
				isSmart=false;
		}

		if(isSmart){
			printf("%.0lf", X[0]);
			for(int j=1 ; j<7 ; j++){
				printf(" %.0lf", X[j]);
			} printf("\n");
		}
		else{
			printf("This is a smart sequence!\n");
		}
	}
}