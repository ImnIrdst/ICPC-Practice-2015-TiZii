#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
	int n;
	while(cin >> n && n){
		int a[10000+10]={0};
		for(int i=0 ; i<n ; i++) cin >> a[i];
		
		int sum=0, ans=0;
		for(int i=1 ; i<n ; i++){
			if(sum<0)  sum=0; 
			sum+=a[i]; ans=max(ans,sum);	
		}
		if(ans <= 0 ) cout << "Losing streak." << endl;
		else cout << "The maximum winning streak is " << ans << "." << endl;
	}

}
