#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <vector>
#include <queue>
#define INF (int)1e9
#define int64 long long

using namespace std;

int main(){
	int n;
	while(cin >> n && n){
		int ans=0, tmp; priority_queue<int, vector<int>, ::greater<int> > pq;
		for(int i=0 ; i<n ; i++){
			cin >> tmp; pq.push(tmp);
		}
		int a; int b;
		while(pq.size()>1){
			a=pq.top(); pq.pop(); b=pq.top(); pq.pop();
			ans+=a+b;
			pq.push(a+b);
		}
		cout << ans << endl;
	}
	return 0;
}