#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <queue>
#define INF (int)1e9
#define int64 long long
#define p pair<int,int>
#define LEFT 0
#define RIGHT 1

using namespace std;

queue<int> q[2]; int pos, l, n;

int main(){
	int tc; cin >> tc;
	while(tc--){
		pos=LEFT; cin >> l >> n; l*=100;
		string tmpstr; int tmpl;
		for(int i=0 ; i<n ; i++){
			cin >> tmpl >> tmpstr;
			if(tmpstr=="left") q[LEFT].push(tmpl);
			else q[RIGHT].push(tmpl);
		}
		int cnt=0,i=0;
		while(!q[LEFT].empty() || !q[RIGHT].empty()){
			tmpl=0;
			while(!q[pos].empty()){
				tmpl+=q[pos].front();
				if(tmpl>l || i>=n) break;
				q[pos].pop();
			}
			cnt++; pos=1-pos;
		}
		cout << cnt << endl;
	}
	return 0;
}