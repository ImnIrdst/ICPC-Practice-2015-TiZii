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
	int8 n,m;
	while(cin >> n >> m){
		int8 ans=1,t=0, f=0,tmp;
		for(int8 i=(n-m+1) ; i<=n ; i++){
			tmp=i;
			while(tmp%2==0){
				tmp/=2; t++;
			}
			while(tmp%5==0){
				tmp/=5; f++;
			}
			ans=(ans*tmp)%10;
		}
		for(int i=t ; i<f ; i++){
			ans=(ans*5)%10;
		}
		for(int i=f ; i<t ; i++){
			ans=(ans*2)%10;
		}
		cout << ans%10 << endl;
	}
	return 0;
}