#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 1e8;

int dp[100 + 10][200 + 10];
int cost[10000 + 10], dist[100 + 10], n;

int solve(int city, int gas){
	if (gas < 0 || gas > 200 ) return INF; // TODO: check this (< or <=)
	if (city >= n - 1 && gas >= 100) return 0;
	if (city >= n - 1 && cost[dist[city]] == -1) return INF;
	int& dpp = dp[city][gas];
	if (dpp != -1) return dpp;

	dpp = INF;
	dpp = min(dpp, solve(city + 1, gas - (dist[city + 1] - dist[city])));
	if (cost[dist[city]] != -1) 
		dpp = min(dpp, solve(city, gas + 1) + cost[dist[city]]);
	return dpp;
}

int main(){
	int tc;
	cin >> tc;
	while (tc--){
		int distw, tmp; cin >> distw;
		memset(cost, -1, sizeof cost);

		n = 0;
		dist[n++] = 0;
		
		string line; 
		getline(cin, line); // ignore
		while (getline(cin, line) && line.size()){
			stringstream sstr(line); 
			int d, c; sstr >> d >> c; dist[n++] = d; cost[d] = c;
		}
		dist[n++] = distw;
		memset(dp, -1, sizeof dp); 
		int ans = solve(0, 100);
		if (ans != INF) cout << ans << endl;
		if (ans == INF) cout << "Impossible" << endl;
		if (tc) cout << endl;
	}
}