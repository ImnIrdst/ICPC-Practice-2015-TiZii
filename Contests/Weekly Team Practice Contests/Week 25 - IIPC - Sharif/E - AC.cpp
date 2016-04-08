#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

typedef long long int64;

struct frac {
	int64 p, q;
	frac(int64 p = 1, int64 q = 1)
		:p(p), q(q) {}
	frac parent() {
		if (p > q) return frac(p - q, q);
		else	   return frac(p, q - p);
	}
	frac left() {
		return frac(p, q + p);
	}
	frac right() {
		return frac(p + q, q);
	}
	bool operator==(const frac& op) {
		return make_pair(p, q) == make_pair(op.p, op.q);
	}
};

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int64 p, q;
		char c;
		cin >> p >> c >> q;
		frac f(p, q);
		if (f.q == 1) {
			cout << (int)pow(2, f.p) - 1 << endl; continue;
		}
		stack<char> path;
		frac par = f, prev; int64 h = 0;
		while (par.q != 1 && par.p != 1) {
			prev = par; par = par.parent();
			if (par.left() == prev) path.push('L');
			else path.push('R');

			h++;
		}
		int depth = h - 1;
		int64 ans = 0;
		bool isInRight = false;
		if (par == frac()) h = h;
		else if (par.p != 1) h += par.p - 1, isInRight = true; //, ans += pow(2, h - 1), ;
		else if (par.q != 1) h += par.q - 1;

		frac child = par;
		ans += pow(2, h) - 1;
		int64 offset = 0;
		if (!isInRight){
			while (path.size()) {
				char c = path.top(); path.pop();
				if (c == 'L') child = child.left();
				else		  child = child.right(), offset += pow(2, depth);
				depth--;
			}
		}
		else{
			offset += pow(2, h)-1;
			while (path.size()) {
				char c = path.top(); path.pop();
				if (c == 'L') child = child.left(), offset -= pow(2, depth);
				else		  child = child.right();
				depth--;
			}
		}
		cout << ans + offset + 1 << endl;
	}
}