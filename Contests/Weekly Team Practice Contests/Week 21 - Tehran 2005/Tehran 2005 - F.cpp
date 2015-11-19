#include<iostream>
#include<algorithm>
#include<functional>
#include<string>
#include<vector>
#include<string.h>
#include<set>
using namespace std;

struct Point{
	int x, y;
	Point(int x= 0, int y = 0)
		: x(x), y(y){}
	bool operator<(const Point& op) const{
		if (x == op.x) return y < op.y;
		return x < op.x;
	}
};

int rectSum[1001][1001];
bool treeMtx[1001][1001];

void ComputeRectSub()
{
	for (int i = 1; i <= 1000; ++i){
		for (int j = 1; j <= 1000; ++j){
			rectSum[i][j] = rectSum[i - 1][j] + rectSum[i][j - 1] 
				- rectSum[i - 1][j - 1] + treeMtx[i][j];
		}
	}
}

int GetSum(const Point& p1, const Point& p2)
{
	return rectSum[p2.y][p2.x] - rectSum[p1.y - 1][p2.x] 
		- rectSum[p2.y][p1.x - 1] + rectSum[p1.y - 1][p1.x - 1];
}

void CorrectOrder(Point& p1, Point& p2)
{
	Point p1_t;
	p1_t.x = min(p1.x, p2.x);
	p1_t.y = min(p1.y, p2.y);
	Point p2_t;
	p2_t.x = max(p1.x, p2.x);
	p2_t.y = max(p1.y, p2.y);

	p1 = p1_t;
	p2 = p2_t;
}

int GetArea(const Point& p1, const Point& p2)
{
	if (p2.y == p1.y && p2.x == p1.x) return 1;
	if (p2.y == p1.y) return p2.x - p1.x;
	if (p2.x == p1.x) return p2.y - p1.y;
	return (p2.y - p1.y) * (p2.x - p1.x);
}

int main()
{
	int tc;
	cin >> tc;
	while (tc--){
		int F, A;
		//init. table
		memset(rectSum, 0, sizeof rectSum);
		memset(treeMtx, 0, sizeof treeMtx);
		cin >> F >> A;
		vector<Point> trees(F);
		for (int i = 0; i < F; ++i){
			int x, y;
			cin >> x >> y;
			treeMtx[y][x] = true;
			trees[i].y = y;
			trees[i].x = x;
		}
		//preprocess
		ComputeRectSub();
		//compute the ans
		int max_tree = 0;
		vector<Point> new_list;
		set<Point> unique_points;
		for (int i = 0; i < F; ++i){
			for (int j = i; j < F; ++j){
				Point a = trees[i];
				Point b = trees[j];
				CorrectOrder(a, b);
				unique_points.insert(a);
				unique_points.insert(b);
				unique_points.insert(Point(b.x, a.y));
				unique_points.insert(Point(a.x, b.y));
			}
		}

		for (set<Point>::iterator it = unique_points.begin(); it != unique_points.end(); ++it){
			new_list.push_back(*it);
		}

		int T = new_list.size();
		for (int i = 0; i < T; ++i){
			for (int j = i; j < T; ++j){
				Point a = new_list[i];
				Point b = new_list[j];
				CorrectOrder(a, b);
				if (GetArea(a, b) > A) continue;
				int tmp = GetSum(a, b);
				if (tmp > max_tree) max_tree = tmp;
			}
		}
		cout << max_tree << endl;
	}
	return 0;
}