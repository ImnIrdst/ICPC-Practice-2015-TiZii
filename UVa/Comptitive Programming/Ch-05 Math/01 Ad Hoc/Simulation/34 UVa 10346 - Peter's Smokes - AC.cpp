#include <iostream>
#include <math.h>
#include <algorithm>
#include <fstream>
#include <string>
#include <map>
#define int8 long long
//#define cin fin
#define INF (int)1e9

using namespace std;

int main(){
	//ifstream fin("in.txt");
	int n,k;
	while(cin >> n){
		cin >> k;
		int ans=0, newcig=0, rem=0;
		while(n>=k){
			rem=n%k;
			newcig=n/k;
			ans+=n-rem;
			n=rem+newcig;
		}
		ans+=n;
		cout << ans << endl;
	}
	return 0;
}