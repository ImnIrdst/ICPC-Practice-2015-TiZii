#include <iostream>
#include <math.h>
#include <algorithm>
#include <fstream>
#include <string>
#include <map>
//#define cin fin
#define MAX (int)1e6
#define fr( i , n )for( int i = 0; i < n ; i++ )

using namespace std;

int a[MAX];

int main(){
	//ifstream fin("in.txt");
	int tc; cin >> tc;
	fr(tcc,tc){
		int n; cin >> n;
		map<int, int> check;
		fr(m,n) cin >> a[m];
		
		int i,j,cnt, ans=0;
		for( i=0, j=0 ; i<n && j<n ; ){
			for(cnt=j-i ; j<n ; j++){
				if(!check[a[j]]){
					check[a[j]]=1;
					cnt++;
				}
				else {
					for(;a[i]!=a[j];i++) check[a[i]]=0;
					i++; j++;
					break;
				}

			}
			ans=max(cnt,ans);
		}
		cout << ans << endl;
	}
	return 0;
}