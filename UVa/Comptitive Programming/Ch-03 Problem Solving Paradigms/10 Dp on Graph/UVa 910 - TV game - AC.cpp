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

vector<int> a[40]; int n,d[40][40],sp[40];

int solve(int u, int moves){
	if(moves==0 && sp[u]) return 1;
	if(moves==0 && !sp[u]) return 0;
	if(d[u][moves]!=-1) return d[u][moves];
	int ans=0,v;
	for(int i=0 ; i<a[u].size() ; i++){
		v=a[u][i];
		ans+=solve(v,moves-1);
	}
	return d[u][moves]=ans;
}

int main(){
	//ifstream fin("in.txt");
	while(cin >> n){
		for(int i=0 ; i<40 ; i++){
			for(int j=0 ; j<40 ; j++){
				d[i][j]=-1;
			}
			a[i].clear(); sp[i]=0;
		}
		string x,y,z,w;
		for(int i=0 ; i<n ; i++){
			cin >> x >> y >> z >> w;
			a[x[0]-'A'].push_back(y[0]-'A');
			a[x[0]-'A'].push_back(z[0]-'A');
			if(w=="-") sp[i]=0;
			else sp[i]=1;
		}
		int moves; cin >> moves;
		cout << solve(0,moves) << endl;
	}
	return 0;
}
