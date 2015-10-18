#include <iostream>
#include <vector>

using namespace std;

struct Pt {
	int x, y; 
	Pt(int x = 0, int y = 0) 
		:x(x), y(y){}
};

struct Rect {
	Pt a, b;
	Rect(const Pt& a = Pt(-1, -1), const Pt& b = Pt(-1, -1))
		:a(a), b(b) {}
};

bool inRect(Pt p, Rect r) {
	return r.a.x <= p.x && p.x <= r.b.x
		&& r.a.y <= p.y && p.y <= r.b.y;
}

int main() {
	int tc;
	cin >> tc;
	while (tc--) {
		int n, r; cin >> n >> r;
		
		vector<Pt> pts(n);
		for (int i = 0; i < n; i++) {
			cin >> pts[i].x >> pts[i].y;
		}

		int ans = 0, cnt; 
		for (int i = 0; i < n; i++) {
			Rect rect1(Pt(pts[i].x, pts[i].y)
				, Pt(pts[i].x + r, pts[i].y + r));
			cnt = 0;
			for (int j = 0; j < n; j++) {
				if (inRect(pts[j], rect1)) cnt++;
			}
			if (cnt > ans) ans = cnt;
			Rect rect2(Pt(pts[i].x - r, pts[i].y)
				, Pt(pts[i].x, pts[i].y + r));
			cnt = 0;
			for (int j = 0; j < n; j++) {
				if (inRect(pts[j], rect2)) cnt++;
			}
			if (cnt > ans) ans = cnt;
			Rect rect3(Pt(pts[i].x, pts[i].y - r),
				Pt(pts[i].x + r, pts[i].y));
			cnt = 0;
			for (int j = 0; j < n; j++) {
				if (inRect(pts[j], rect3)) cnt++;
			}
			if (cnt > ans) ans = cnt;
			Rect rect4(Pt(pts[i].x-r, pts[i].y-r)
				, Pt(pts[i].x, pts[i].y));
			cnt = 0;
			for (int j = 0; j < n; j++) {
				if (inRect(pts[j], rect4)) cnt++;
			}
			if (cnt > ans) ans = cnt;
		}

		cout << ans << endl;

	}
}