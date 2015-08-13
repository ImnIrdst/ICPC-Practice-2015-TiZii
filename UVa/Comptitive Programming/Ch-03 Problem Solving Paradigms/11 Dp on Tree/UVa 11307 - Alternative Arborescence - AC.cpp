//Minimum tree can be colored using only 6 Colors
//or for ensure use 10 or more colors
#include <iostream>
#include <math.h>
#include <algorithm>
#include <fstream>
#include <functional>
#include <string>
#include <bitset>
#include <vector>
#include <sstream>
#include <set>
#define int8 long long
#define p pair<int, int>

#define cost first
#define time second
//#define cin fin
//#define cout fout
#define INF (int)1e9

using namespace std;

vector<int> a[10010]; int n,d[10010][10];

int calc(int u, int color){
	int ans=color;
	if(d[u][color]!=-1) return d[u][color];
	for(int i=0 ; i<a[u].size() ; i++){
		int v=a[u][i];
		int Min=INF;
		for(int i=1 ; i<7 ; i++){
			if(i!=color)
				Min=min(Min,calc(v,i));
		}
		ans+=Min;
	}
	//if(Min==INF) Min=0;
	return d[u][color]=ans;
}

int main(){
	//ifstream fin("in.txt");
	while(cin >> n && n){
		set<int> st;
		for(int i=0 ; i<10010 ; i++){
			for(int j=0 ; j<10; j++){
				d[i][j]=-1;
			}
			a[i].clear();
		}
		string tmp; stringstream sin;
		for(int i=0 ; i<n+1 ; i++){
			getline(cin,tmp); sin << tmp; int u,v; sin >> u; char c; sin >> c;
			while(sin >> v){
				a[u].push_back(v); st.insert(v);
			}
			sin.clear();
		}
		int root=0;
		for(int i=0 ; i<n ; i++){
			if(a[i].size() && st.find(i)==st.end()){
				root=i;
				break;
			}
		}
		int ans=INF;
		for(int i=1 ; i<7 ; i++)
			ans=min(ans,calc(root,i));
		cout << ans << endl;
	}
	return 0;
}
