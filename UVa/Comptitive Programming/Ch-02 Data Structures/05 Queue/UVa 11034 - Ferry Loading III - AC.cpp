#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <queue>
#include <vector>
#define INF (int)1e9
#define int64 long long
#define p pair<int,int>
#define LEFT 0
#define RIGHT 1

using namespace std;

queue<p> q[2];//q[0] = q[LEFT], q[1] = q[RIGHT]
priority_queue< p, vector<p> , greater<p> > ans;//sort answers by index
int pos, m, t, n;

int main(){
	int tc; cin >> tc; bool first=true;
	while(tc--){
		pos=LEFT; cin >> m >> t >> n;
		string tmpstr; int tmpt; //
		for(int i=0 ; i<n ; i++){
			cin >> tmpt >> tmpstr;
			if(tmpstr=="left") q[LEFT].push(p(i,tmpt)); //keep indexes
			else q[RIGHT].push(p(i,tmpt));//keep indexes
		}
		int Time=0;
		while(!q[LEFT].empty() || !q[RIGHT].empty()){
			int i=m; bool wait=true;
			if((q[pos].empty() || q[pos].front().second>Time) && (!q[1-pos].empty() && q[1-pos].front().second<=Time)){
				pos=1-pos; Time+=t; continue;
			}
			while(!q[pos].empty() && q[pos].front().second<=Time && i--){
				ans.push(p(q[pos].front().first,Time+t));//insert pair(index,finish time) into ans p_queue
				q[pos].pop();
				wait=false;
			}
			if(!wait){ pos=1-pos; Time+=t; }
			else Time++;
		}
		if(!first) cout << endl; first=false;
		while(!ans.empty()){
			cout << ans.top().second << endl;
			ans.pop();
		}
	}
	return 0;
}
