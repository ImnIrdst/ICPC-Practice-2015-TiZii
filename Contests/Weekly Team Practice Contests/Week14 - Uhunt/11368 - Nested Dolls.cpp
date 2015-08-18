
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>

using namespace std;

const int inf = 1e9;

struct Doll{
	int h, w;
	Doll(int h = 0, int w = 0) :h(h), w(w){}
	bool operator<(const Doll& d) const {
		return (h == d.h ? w < d.w : h > d.h);
	}
};

int main(){
	int tc;
	cin >> tc;
	while (tc--){
		int n; cin >> n;
		vector<Doll> dolls(n);
		for (int i = 0; i < n; i++){
			cin >> dolls[i].w >> dolls[i].h;
		}
		sort(dolls.begin(), dolls.end());

		vector<int> v;
		v.push_back(inf);
		for(int i=0 ; i<n ; i++) {
			int x = dolls[i].w;
			int id = lower_bound(v.begin(), v.end(), x + 1) - v.begin();
			if (id == v.size() - 1) v.push_back(inf);
			v[id] = x;
		}
		cout << v.size()-1 << endl;
	}
}