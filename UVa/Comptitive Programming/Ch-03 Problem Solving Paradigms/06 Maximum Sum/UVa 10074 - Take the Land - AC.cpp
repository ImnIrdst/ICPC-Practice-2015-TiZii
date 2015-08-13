#include <iostream>
#include <string>

using namespace std;

int main(){
	int n,m,tmp;
	while(cin >> n >> m && (n||m)){
		int a[100+10][100+10]={0}; 
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<m ; j++){
				cin >> tmp; a[i+1][j+1]=(tmp!=1 ? 1 : -1e3);
			}
		}
		

		for(int i=1 ; i<n+1 ; i++){
			for(int j=0 ; j<m+1 ; j++){
				a[i][j]+=a[i-1][j];
			}
		}

		// for(int i=0 ; i<n+1 ; i++){
		// 	for(int j=0 ; j<m+1 ; j++){
		// 		cout << a[i][j] << "";
		// 	}
		// 	cout << endl;	
		// }


		int Max=0, ans=0; n++; m++;
		for(int k=0 ; k<n ; k++){//calc
			for(int i=0 ; i<n-k ; i++){ Max=0;
				for(int j=0 ; j<m ; j++){
					if(Max<0) Max =a[i+k][j]-a[i][j];
					else	  Max+=a[i+k][j]-a[i][j];
					if(Max>ans) ans=Max;
				} 
			} 
		}
		cout << ans << endl;
	}

}
