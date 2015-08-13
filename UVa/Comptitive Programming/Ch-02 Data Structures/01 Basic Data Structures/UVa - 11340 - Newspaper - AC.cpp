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

int charval[258], n; unsigned char tmpchar; int tmpval;

int main(){
	int tc; cin >> tc;
	while(tc--){
		cin >> n;
		memset(charval,0,sizeof charval);
		while(n--){
			cin >> tmpchar >> tmpval;
			charval[(int)tmpchar]=tmpval;
		}
		cin >> n; cin.get();
		int ans=0; unsigned char c;
		while(n--){
			while((c=cin.get())!='\n'){
				ans+=charval[(int)c];
			}
		}
		printf("%d.%02d$\n", ans/100,ans%100);
	} 
	return 0;
}