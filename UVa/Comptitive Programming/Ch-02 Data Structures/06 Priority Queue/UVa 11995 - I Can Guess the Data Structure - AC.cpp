#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <bitset>
#include <stack>
#include <queue>
#define INF (int)1e9
#define int64 long long

using namespace std;

bool multyzero(bool bit[]){
	int cnt=0;
	for(int i=0 ; i<3 ;i++)
		if(bit[i]) cnt++;
	return cnt>1;
}

int main(){
	int n;
	while(cin >> n){
		stack<int> st; queue<int> q; priority_queue<int> pq;
		int a; int b; bool bit[3]={1,1,1};
		for(int i=0 ; i<n ; i++){
			cin >> a >> b;
			if(a==1){
				st.push(b); q.push(b); pq.push(b);
			}
			if(a==2){
				if(st.empty() || st.top()!=b || !bit[0]) bit[0]=0; else st.pop(); 
				if(q.empty() || q.front()!=b || !bit[1]) bit[1]=0; else q.pop(); 
				if(pq.empty() || pq.top()!=b || !bit[2]) bit[2]=0; else pq.pop();
			}
		}
		if(!(bit[0] || bit[1] || bit[2])) cout << "impossible" << endl;
		else if(multyzero(bit)) cout << "not sure" << endl;
		else if(bit[0]) cout << "stack" << endl;
		else if(bit[1]) cout << "queue" << endl;
		else if(bit[2]) cout << "priority queue" << endl;
	}
	return 0;
}