#include <iostream>
#include <algorithm>
#define MOD (1000*1000*1000+7)

using namespace std;

int dp[1000][1000]={0}, pathcnt[1000][1000]={0}; char a[1000][1000],tmp[1000][1000];
int cnt=1, maxcoin=0 ,n;

int calc(int i, int j){
	if(i<0 || j<0) return 0;
	if(i>=n || j>=n) return 0;
	if(a[i][j]=='B') 
		return 0; 
	if(dp[i][j]!=-1) 
		return dp[i][j]; 

	//dp[i][j]=max(dp[i-1][j], dp[i][j-1])+(a[i][j]=='C'? 1 : 0);
	dp[i][j]=max(calc(i-1,j), calc(i,j-1))+(a[i][j]=='C'? 1 : 0);
	if(i>0 && j>0){
		if(dp[i-1][j]==dp[i][j-1])
				pathcnt[i][j]=pathcnt[i-1][j]+pathcnt[i][j-1]%MOD;
	
		else if (j-1<0 || dp[i-1][j]>dp[i][j-1] )
				pathcnt[i][j]=pathcnt[i-1][j]%MOD;
	
		else if (i-1<0 || dp[i-1][j]<dp[i][j-1])
				pathcnt[i][j]=pathcnt[i][j-1]%MOD;
	}
	else if(i==0 && j==0)
		pathcnt[i][j]=1;
	else if(i==0) 
		pathcnt[i][j]=pathcnt[i][j-1]%MOD;
	else if(j==0)
		pathcnt[i][j]=pathcnt[i-1][j]%MOD;

	/*calc(i+1,j);
	calc(i,j+1);*/

	return dp[i][j];

}

int main(){
	while(cin >> n){
		//memset
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<n ; j++){
				pathcnt[i][j]=dp[i][j]=-1;
			}
		}
		//init
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<n ; j++){
				cin >> a[i][j];
				tmp[i][j]=a[i][j];
			}
		}
		//query
		int q; cin >> q;
		for(int i=0 ; i<q ; i++){
			int r1, c1, r2, c2; cin >> r1 >> c1>> r2 >> c2;
			for(int i=0 ; i<n ; i++){
				for(int j=0 ; j<n ; j++){
					a[i][j]=tmp[i][j];
				}
			}
			for(int i=r1 ; i<=r2 ; i++){
				for(int j=c1 ; j<=c2 ; j++){
					a[i][j]='B';
				}
			}
			dp[0][0]=(a[0][0] == 'C' ? 1 : 0); 
			pathcnt[0][0]=1;
			
			calc(n-1,n-1);//calc(0,1); calc(1,0);
			
			if((a[n-1][n-1]=='B') || (a[0][0]=='B') )
				cout << 0 << " " << 0 << endl;
			else cout << dp[n-1][n-1] << " " << pathcnt[n-1][n-1] << endl;
			
			for(int i=0 ; i<n ; i++){
				for(int j=0 ; j<n ; j++){
					pathcnt[i][j]=dp[i][j]=-1;
				}
			}

		}
	}
	return 0;
}
