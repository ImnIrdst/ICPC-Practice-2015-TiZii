#include <iostream>
#include <algorithm>

using namespace std;

int a[10010]; long long sum,Min;;

int main(){
	int tc; cin >> tc;
	while(tc--){ 
		int n; cin >> n;
		for(int i=0 ; i<n ; i++) cin >> a[i];
		sort(a,a+n, ::greater<int>() );
		bool possible=true; sum=0;
		for(int i=0 ; i<n ; i++){
			sum+=a[i]; Min=0;
			for(int j=i+1 ; j<n; j++) Min+=min(a[j],i+1);
			if(sum>i*(i+1)+Min){
				possible=false;
				break;
			}
		}
		if(!possible || sum%2) cout << "No" << endl;
		else cout << "Yes" << endl;
	}
	return 0;
}
