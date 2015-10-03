#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string.h>
#include<cstdio>
using namespace std;

double dp_table[2010][2010];
vector<double> trees;
double L, W;
double spacing;

double dp(int left, int right)
{
	int index = left + right;
	if (index >= trees.size()) {
		return (left == right ? 0 : 1e9);
	}
	if (fabs(dp_table[left][right]+1)>1e-9) 
		return dp_table[left][right];
	double left_dist = fabs((left * spacing) - trees[index]);
	double dy = fabs(trees[index] - (right*spacing)), dx = W;
	double right_dist = sqrt(dx*dx + dy*dy);
	return dp_table[left][right] = min(dp(left+1,right) + left_dist, dp(left,right+1) + right_dist);
}

int main()
{
	int n;
	while (cin >> n) {
		cin >> L >> W;
		spacing = L / (double(n) / 2 - 1);
		trees.resize(n);
		for (int i = 0; i < n; ++i) {
			cin >> trees[i];
		}
		sort(trees.begin(), trees.end());
		//init dp
		memset(dp_table,-1, sizeof dp_table);
		//answer
		printf("%.10f\n", dp(0,0));
	}
	return 0;
}