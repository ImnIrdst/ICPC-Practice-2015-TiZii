#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

typedef unsigned long long ull;

int main()
{
	int m,n;
	cin >> m >> n;
	ull card = 0;
	for(int i = 0 ; i <= m ; ++i){
		for(int j = i ; j <= m ; ++j){
			for(int k = j ; k <= m ; ++k){
				ull p_i = (ull)pow(i,2);
				ull p_j = (ull)pow(j,2);
				ull p_k = (ull)pow(k,2);
				if(p_i + p_j == p_k) {
					card++;
					//printf("x = %d y = %d z = %d p = %d\n",i,j,k,p);
				}
			}
		}
	}
	ull card2 = 0;
	for(int i = 0 ; i <= m ; ++i){
		for(int j = i ; j <= m ; ++j){
			for(int k = j ; k <= m ; ++k){
				ull p_i = (ull)pow(i,3);
				ull p_j = (ull)pow(j,3);
				ull p_k = (ull)pow(k,3);
				if(p_i + p_j == p_k) {
					card2++;
					//printf("x = %d y = %d z = %d p = %d\n",i,j,k,p);
				}
			}
		}
	}
	cout << card + (n-2)*card2 << endl;
	return 0;
}