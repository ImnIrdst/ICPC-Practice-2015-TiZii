#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <fstream>
#include <string>
#include <string.h>
#include <map>
#include <sstream>
#include <stack>
#include <queue>
//#define cin fin
#define mapii map<int,int>
#define INF (int)1e9
#define MAX (int)1e6+10

using namespace std;

class cmp{
public:
	bool operator()(string& a, string& b){
		return a>b;
	}
};

string s="12345678";
mapii mp;
priority_queue<string, vector<string>, cmp > pq;
int a[6][6]={
	{0,0,0,0,0,0},
	{0,0,1,1,0,1},
	{0,1,0,1,0,1},
	{0,1,1,0,1,1},
	{0,0,0,1,0,1},
	{0,1,1,1,1,0},
};

void bfs(int u, string str, string ans){
	if(str.length()==0)
		pq.push(ans);
	for(int i=1 ; i<6 ; i++){
		string tmp=str, tmp2; int f;
		if(a[u][i] && (f=tmp.find(mp[u*10+i]+'0'))!=-1){
			tmp2=i+'0';
			tmp.replace(f,1,"");
			bfs(i,tmp,ans+tmp2);
		}
	}
}

int main(){
	//ifstream fin("in.txt");
	mp[51]=mp[15]=1;
	mp[54]=mp[45]=2;
	mp[34]=mp[43]=3;
	mp[53]=mp[35]=4;
	mp[52]=mp[25]=5;
	mp[13]=mp[31]=6;
	mp[32]=mp[23]=7;
	mp[21]=mp[12]=8;
	bfs(1,s,"1");
	while(!pq.empty()){
		cout << pq.top() << endl;
		pq.pop();
	}
}
