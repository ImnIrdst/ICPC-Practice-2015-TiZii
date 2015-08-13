#include <iostream>
#include <vector>

using namespace std;

typedef long long int64;

int main(){
	int tc;
	cin >> tc;
	while( tc-- ){
		int n; cin >> n;
		vector<int64> c;

		int64 tmp, sum=0, ans=1; 
		cin >> tmp; c.push_back(1);
		for(int i=1 ; i<n ; i++){
			cin >> tmp; c.push_back(tmp);
			if(c[i-1]+sum < c[i]) sum+=c[i-1], ans++;
		}
		//if(n==3 || c[n-2]+sum < c[n-1])  ans++;
		cout << ans << endl;
	}
}