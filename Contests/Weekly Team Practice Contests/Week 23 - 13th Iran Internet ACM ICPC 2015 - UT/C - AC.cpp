#include<iostream>
#include<map>
#include<algorithm>
#include<functional>
#include<vector>
using namespace std;

struct Point{
	int x, y;
	Point(int _x = 0, int _y = 0)
		: x(_x), y(_y) {}
	Point operator+(const Point& p) const{
		return Point(x + p.x, y + p.y);
	}
	bool operator<(const Point& p) const{
		if (x == p.x) return y < p.y;
		return x < p.x;
	}
	bool operator==(const Point& p) const{
		return x == p.x && y == p.y;
	}
};

typedef unsigned long long int64;

int main()
{
	int tc;
	cin >> tc;
	while (tc--){
		int N; cin >> N;
		map<Point, int64> dict;
		map<Point, int64>::iterator it;
		vector<Point> points(N, Point());

		for (int i = 0; i < N; ++i){
			cin >> points[i].x >> points[i].y;
		}
		for (int i = 0; i < N; ++i){
			Point p = points[i];
			//creat new vectors
			vector<pair< Point, int64> > tmp;
			for (it = dict.begin(); it != dict.end(); ++it){
				//if (it->first == p) continue;
				Point new_p = p + it->first;
				tmp.push_back(pair<Point,int64>(new_p, it->second));
			}
			//add to dict
			if (!dict.count(p))
				dict[p] = 1;
			else
				dict[p]++;

			int s = tmp.size();
			for (int j = 0; j < s; ++j){
				pair< Point, int64> top = tmp[j];
				p = top.first; 
				int64 num = top.second;
				if (!dict.count(p)) dict[p] = num;
				else dict[p] += num;
			}
		}
		//print answer
		it = dict.find(Point(0, 0));
		if (it == dict.end())
			cout << "0" << endl;
		else
			cout << it->second << endl;
	}
	return 0;
}