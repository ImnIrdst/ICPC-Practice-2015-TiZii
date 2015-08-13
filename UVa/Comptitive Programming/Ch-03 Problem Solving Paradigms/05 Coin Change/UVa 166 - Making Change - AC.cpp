#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

const int inf = 1e9;
const int Max = 7489 + 10;

int coin[] = {5,10,20,50,100,200}, cnt[6], buy[Max], sell[Max];

int main(){
	int n, sum, ans; double x;
	while(1){
		sum=0; 
		for(int i=0 ; i<6 ; i++){ cin >> cnt[i]; sum+=cnt[i]*coin[i];}
		if(sum==0) break; cin >> x; x+=0.0001; n=(x*100);
		
		memset(sell, 0, sizeof sell); memset(buy, 0, sizeof buy);
		for(int i=1 ; i<=sum ; i++) sell[i] = buy[i] = inf;//  buy[0]=sell[0]=0;
		
		for(int i=0 ; i<6 ; i++){
			for(int j=sum ; j>0 ; j--){
				ans = inf;
				for(int k=0 ; k<=cnt[i] && k*coin[i]<=j ; k++){
					ans = min(ans, k + buy[j - k*coin[i]]);
				}
				buy[j] = ans;
			}
		}

		for(int i=0 ; i<6 ; i++){
			for(int j=sum ; j>0 ; j--){
				ans = inf;
				for(int k=0 ; k*coin[i]<=j ; k++){
					ans = min(ans, k + sell[j - k*coin[i]]);
				}
				sell[j] = ans;
			}
		}
		ans = inf;
		for(int i=n ; i<=sum ; i++) ans = min(ans,buy[i]+sell[i-n]);
		printf("%3d\n", ans);
	}
}