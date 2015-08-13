#include <iostream>

using namespace std;

typedef long long int64;

const int Max = 26;

int64 Cat[Max+10], SupCat[Max+10];

void Init(){
	// Catalan Numbers
	Cat[0]=Cat[1]=1, Cat[2]=2;
	for(int n=3 ; n<=Max ; n++){
		Cat[n] = Cat[n-1]*(2*(n*2-1))/(n+1);
	}

	// Super Catalan Numbers
	SupCat[0]=SupCat[1]=SupCat[2]=1;
	for(int n=3 ; n<=Max ; n++){
		SupCat[n] = (3*(n*2-3 )*SupCat[n-1]-(n-3)*SupCat[n-2])/n;
	}
}

int main(){
	int n; Init();
	while( cin >> n ){
		cout << SupCat[n] - Cat[n-1] << endl;
	}
}