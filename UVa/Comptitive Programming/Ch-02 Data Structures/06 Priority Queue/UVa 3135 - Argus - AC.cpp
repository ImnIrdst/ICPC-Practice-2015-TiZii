#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <queue>
#include <sstream>
#include <vector>
#define INF (int)1e9
#define p pair<int,int>
#define per first
#define qnum second

using namespace std;

int mp[4000]; priority_queue<p, vector<p>, ::greater<p> > pq;

int main(){
	string str; stringstream sstr; int Qnum, Period;
	while(getline(cin,str) && str!="#"){
		sstr << str; sstr >> str >> Qnum >> Period;
		mp[Qnum]=Period;
		pq.push(p(Period,Qnum));
		sstr.clear();
	}
	int k; cin >> k; p tmp;
	for(int i=0 ; i<k ; i++){
		tmp=pq.top(); pq.pop();
		cout << tmp.qnum << endl;
		tmp.per+=mp[tmp.qnum]; pq.push(tmp);
	}
	return 0;
}