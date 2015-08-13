#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <stack>
#include <queue>
#define INF (int)1e9
#define int64 long long

using namespace std;

int main(){
	int tc; cin >> tc;
	while(tc--){
		int n, sc, qc, cnt=0; stack<int> st; queue<int> q[110];
		cin >> n >> sc >> qc;
		for(int i=0 ; i<n ; i++){
			int m,tmp; cin >> m;
			for(int j=0 ; j<m ; j++){
				cin >> tmp;
				q[i].push(tmp);
			}
			if(m!=0) cnt++;
		}
		int pos=0, ans=0;
		while(cnt || !st.empty()){
			if(q[pos].empty()) cnt++;
			while(!st.empty() && (st.top()-1==pos || q[pos].size()<qc) ){
				if(st.top()-1==pos) 
					st.pop();
				else{q[pos].push(st.top()); st.pop();}
				ans++;
			}
			while(!q[pos].empty() && st.size()<sc){
				st.push(q[pos].front()); q[pos].pop();
				ans++;
			}
			if(q[pos].empty()) cnt--;
			ans+=2; pos++; pos%=n;
		}
		cout << ans-2 << endl;
	}
	return 0;
}