#include <iostream>
#include <string>

using namespace std;

int main(){
	int tc; cin >> tc;
	while(tc--){
		int n,b; cin >> n >> b;
		int a[100+10][100+10]={0};

		for(int i=0 ; i<n+2 ; i++){
			for(int j=0 ; j<n+2 ; j++){
				a[i][j]=(!j || !i ? 0 : 1);
			}
		}

		while(b--){
			int r1,c1,r2,c2;
			cin >> r1 >> c1 >> r2 >> c2;
			for(int i=r1 ; i<r2+1 ; i++){
				for(int j=c1 ; j<c2+1 ; j++){
					a[i][j]=-1e3;
				}
			}
		}
		n++;
		// for(int i=0 ; i<n ; i++){
		// 	for(int j=0 ; j<n ; j++){
		// 		cout << (a[i][j]>0 ? 1 : 0) << " ";
		// 	}
		// 	cout << endl;	
		// }

		for(int i=1 ; i<n ; i++){
			for(int j=0 ; j<n ; j++){
				a[i][j]+=a[i-1][j];
			}
		}

		int Max=0, ans=0;
		for(int k=0 ; k<n ; k++){//calc
			for(int i=0 ; i<n-k ; i++){ Max=0;
				for(int j=0 ; j<n ; j++){
					if(Max<0) Max=a[i+k][j]-a[i][j];
					else Max+=a[i+k][j]-a[i][j];
					if(Max>ans) ans=Max;
				} 
			} 
		}
		cout << ans << endl;
	}

}
