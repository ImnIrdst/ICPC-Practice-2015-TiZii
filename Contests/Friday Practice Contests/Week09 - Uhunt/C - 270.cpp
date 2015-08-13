#include<iostream>
#include<algorithm>
#include<cmath>
#include<functional>
#include<vector>
#include<string>
#include<sstream>
#include<cstring>
using namespace std;

typedef pair<int,int>	PII;
typedef long long		int64;
PII origin;

int64 Cross(const PII &p,const PII& p1,const PII &p2)
{
	PII vec1(p1.first - p.first , p1.second - p.second);
	PII vec2(p2.first - p.first , p2.second - p.second);
	return  vec1.first * vec2.second - vec1.second * vec2.first;
}

int64 Dist2(const PII&  p1,const PII& p2)
{
	int dx = p1.first - p2.first;
	int dy = p1.second - p2.second;
	return dx*dx + dy*dy;
}

bool cmp(const PII &p1,const PII&p2)
{
	PII vec1(p1.first - origin.first , p1.second - origin.second);
	PII vec2(p2.first - origin.first , p2.second - origin.second);
	int64 c = vec1.first * vec2.second - vec1.second * vec2.first;
	if(c) return c > 0;
	if(Dist2(origin,p1) == Dist2(origin, p2))
		return p1<p2;
	return Dist2(origin,p1) <= Dist2(origin, p2);
}

int main()
{
	int tc;
	bool first = true;
	string input;
	vector<PII> points;
	cin >> tc;
	cin.ignore();
	cin.ignore();
	while(tc--){
		if(!first) cout << endl;
		first = false;
		points.clear();
		while(true){
			getline(cin, input);
			if(input.empty()) break;
			//add to vector
			stringstream sstr(input);
			PII tmp;
			sstr >> tmp.first >> tmp.second;
			points.push_back(tmp);
		}
		int n = points.size();
		int max_count = 0, tmp_count = 0;
		vector<PII> vecTemp(points);
		for(int i = 0 ; i < n ; ++i){
			origin = vecTemp[i];
			sort(points.begin() , points.end(), cmp);
			for(int j = 0 ; j < n ; ++j){
				tmp_count = 2; //TODO => Check this
				int k = j + 1;
				while(k < n && Cross(vecTemp[i], points[j], points[k]) == 0) {
					++k;
					if(vecTemp[i] == points[j] || vecTemp[i] == points[j]) continue;
					++tmp_count;
				}
				max_count = max(max_count, tmp_count);
			}
		}
		cout << max_count << endl;
	}
	return 0;
}