#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#define INF (int)1e9
#define int64 long long

using namespace std;

int main(){
	string str; int tc; cin >> tc;
	while(tc--){
		cin >> str; int sum=0, tmp;
		if(str=="donate"){
			cin >> tmp; sum+=tmp;
		}
		else cout << sum << endl;
	}
	return 0;
}