#include <iostream>
#include <string>

using namespace std;

int main(){
	int tc; cin >> tc; cin.ignore(), cin.ignore();
	while(tc--){
		int n=0, a[25+10][25+10]={0}; string str[25+10];
		while(getline(cin,str[n]) && str[n]!="") n++;
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<n ; j++){
				a[i+1][j]=(str[i][j]=='1'? 1 : -1e6);
			}
		}
		n++;
		for(int i=1 ; i<n ; i++)
			for(int j=0 ; j<n ; j++)
				a[i][j]+=a[i-1][j];

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
		cout << ans << endl; if(tc) cout << endl;
	}

}
