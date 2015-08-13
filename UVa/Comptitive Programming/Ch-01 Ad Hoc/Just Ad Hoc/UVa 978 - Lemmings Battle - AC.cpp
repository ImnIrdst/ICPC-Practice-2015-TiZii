#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <sstream>
#include <queue>
#include <vector>
#define INF (int)1e9
#define pq priority_queue<int, vector<int> , less<int> > 
#define pii pair<int,int> 
#define int64 long long

using namespace std;

int b,SB,SG,tmp;

int main(){
	bool first=true; int tc; cin >> tc;
	while(tc--){
		pq sg,sb; queue<pii> tmpqu;
		cin >> b >> SG >> SB;
		for(int i=0 ; i<SG ; i++){
			cin >> tmp; sg.push(tmp);
		}
		for(int i=0 ; i<SB ; i++){
			cin >> tmp; sb.push(tmp);
		}
		while(!sb.empty() && !sg.empty()){
			for(int i=0 ; i<b && (!sb.empty() && !sg.empty()) ; i++){
				int s1=sb.top(), s2=sg.top(); sb.pop(); sg.pop();
				tmpqu.push(pii(s1,s2));
			}
			while(!tmpqu.empty()){
				pii s=tmpqu.front(); tmpqu.pop();
				if(s.first>s.second) sb.push(s.first-s.second);
				if(s.first<s.second) sg.push(s.second-s.first);
			}
		}
		if(!first) cout << endl;
		if(sb.empty() && sg.empty()) cout << "green and blue died" << endl;
		else if(sg.empty()){
			cout << "blue wins" << endl;
			while(!sb.empty()){ cout << sb.top() << endl; sb.pop(); }
		}
		else if(sb.empty()){ 
			cout << "green wins" << endl;
			while(!sg.empty()){ cout << sg.top() << endl; sg.pop(); }
		}
		first=false;
	}
	return 0;
}