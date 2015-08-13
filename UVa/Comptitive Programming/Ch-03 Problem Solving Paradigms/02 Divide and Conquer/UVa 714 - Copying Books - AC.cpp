#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <bitset>
#include <vector>
#define INF (int)1e9
#define int64 long long

using namespace std;

int n,a[500+10],m;

int main(){
	int tc; cin >> tc;
	while(tc--){
		cin >> n >> m; int64 l=0,r=0,mid,sum=0,i,j;
		for(int i=0 ; i<n ; i++){ cin >> a[i]; r+=a[i]; l=max(l,(int64)a[i]);}
		while(l<r){
			mid=(l+r)/2; 
			bool empty=true; sum=0,j=0;
			for(int i=0 ; i<n ; i++){
				if(sum+a[i]>mid){ j++; sum=0; }
				sum+=a[i];
			}
			if(j<m) r=mid;
			else l=mid+1;
		}
		vector<int> ans;
		for(i=n-1, j=m-1, sum=0 ; i>=0 ; i--){
			if(sum+a[i] > r || j>i){
				j--; sum=0;
				ans.push_back(-1);
			}
			sum+=a[i];
			ans.push_back(a[i]);
		}
		bool first=true;
		for(int i=ans.size()-1 ; i>=0 ; i--){
			if(!first) cout << " "; first=false;
			if(ans[i]==-1) cout << "/";
			else cout << ans[i];
		}
		cout << endl;
	}
	return 0;
}