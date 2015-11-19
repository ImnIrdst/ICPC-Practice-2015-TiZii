#include <iostream>
#include <math.h>
#include <algorithm>
#include <fstream>
#include <string>
#include <map>
#define int8 long long
//#define cin fin
#define INF (int8)1e9

using namespace std;

int main(){
	//ifstream fin("in.txt");
	int8 tc; cin >> tc;
	while(tc--){
		int8 n; cin >> n;
		int8 sum=0, Max=0, tmp;
		for(int8 i=0 ; i<n ;i++){
			scanf("%lld",&tmp);
			sum+=tmp; Max=max(Max,tmp);
		}
		if(sum%2==0 && Max*2<=sum)
			cout << "YAAAYYYY" << endl;
		else cout << "NOOOO" << endl;
	}
	return 0;
}