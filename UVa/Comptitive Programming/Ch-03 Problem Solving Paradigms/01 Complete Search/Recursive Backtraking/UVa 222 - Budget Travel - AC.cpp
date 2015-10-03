#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

double tmp, cap, mpg, cost[51 + 10], dist[51 + 10]; int n, cs=1;

double simulate(double traveled, int cur){
	if (traveled + cap*mpg >= dist[n - 1] || cur == n)
		return 0;

	double best = 1e9;
	for (int i = cur; i<n - 1; i++){
		double used = (dist[i] - traveled) / mpg;
		if (cap - used < 0) break;
		if (cap - used <= cap / 2){
			best = min(best, 200 + used * cost[i] + simulate(dist[i], i + 1));
		}
		else if(cap - used > cap/2 && i+1 < n-2 && dist[i+1] > traveled + cap*mpg){
			return 200 + used * cost[i] + simulate(dist[i], i + 1);
		}
	}
	return best;
}

int main(){
	//distance to destination
	while (cin >> tmp && tmp > -0.5){
		// cap, miles per galon, cost[0],  n
		cin >> cap >> mpg >> cost[0] >> n; n += 2;

		for (int i = 1; i < n - 1; i++){
			// dist[i], cost[i]
			cin >> dist[i] >> cost[i];
		}
		dist[n - 1] = tmp;
		printf("Data Set #%d\n", cs++);
		printf("minimum cost = $%.2f\n", cost[0] + simulate(0, 1) / 100);
	}
}