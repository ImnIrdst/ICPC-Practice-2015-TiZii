#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <vector>
#define INF (int)1e9
#define MAX (75+5)

using namespace std;

int a[MAX*2][MAX]={0},s[MAX*2][MAX]={0};

int main(){
	int tc; cin >> tc;
	while(tc--){
		int n; cin >> n;
		for(int i=0 ; i<n+1 ; i++){
			for(int j=0 ; j<n ; j++){
				if(!i) a[i][j]=0;
				else cin >> a[i][j]; a[i+n][j]=a[i][j];
			}
		}
		for(int i=1 ; i<2*n+1 ; i++){
			for(int j=0 ; j<n ; j++){
				s[i][j]=a[i][j];
				s[i][j]+=s[i-1][j];
				//if(i>=n) s[i][j]-=a[i-n][j];
			}
		}
		int ans=-1*INF,Max=0, tMax=0, Min=0, tMin=0,cnt=0,sum=0; 
		for(int k=1 ; k<=n ; k++){
			for(int i=0 ; i<=2*n-k ; i++){
				Max=-1*INF, tMax=-1*INF, Min=0, tMin=0,sum=0;
				for(int j=0 ; j<n ; j++){
					if(Max<0) Max=s[i+k][j]-s[i][j]; 
					else Max+=s[i+k][j]-s[i][j]; 
					
					if(Min>0) Min=(s[i+k][j]-s[i][j]); 
					else Min+=(s[i+k][j]-s[i][j]); 

					tMax=max(tMax,Max); tMin=min(tMin,Min);
					sum+=(!k ? a[i][j] :s[i+k][j]-s[i][j]);
				}
				if(tMax>=0) ans=max(ans, max(tMax,sum-tMin));
				else ans=max(ans,tMax);
			}
		}
		cout << ans << endl;
	}
	return 0;
}