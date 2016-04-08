#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct vect {
	int x, y;
	vect(int x=0, int y=0) :x(x), y(y) {}
	vect neg() {
		return vect(-x, -y);
	}
	bool operator<(const vect& op) const {
		return make_pair(x, y) < make_pair(op.x, op.y);
	}
	bool operator==(const vect& op) const {
		return make_pair(x, y) == make_pair(op.x, op.y);
	}
	void operator+=(const vect& op) {
		x += op.x; y += op.y;
	}
};

vector<vect> vects; multiset<vect> st;

int main() {
	int tc; 
	cin >> tc;
	while (tc--) {
		int n; 
		cin >> n;
		if (n <= 0) {
			cout << 0 << endl; continue;
		}
		vects.resize(n); st.clear();
		for (int i = 0; i < n; i++) cin >> vects[i].x >> vects[i].y;
		
		vect sum; int nn = n/2;
		for (int bit = 1; bit < (1 << nn); bit++) {
			sum.x = 0; sum.y = 0;
			for (int i = 0; i < nn; i++) {
				if (bit&(1 << i)) sum += vects[i];
			}
			st.insert(sum);
		}
		nn += (n % 2); long long ans = 0;
		for (int bit = 1; bit < (1 << nn); bit++) {
			sum.x = 0; sum.y = 0;
			for (int i = 0; i < nn; i++) {
				if (bit&(1 << i)) sum += vects[i+n/2];
			}
			if (sum.x == 0 && sum.y == 0) ans++;
			ans += st.count(sum.neg());
		}

		cout << ans << endl;
	}
}