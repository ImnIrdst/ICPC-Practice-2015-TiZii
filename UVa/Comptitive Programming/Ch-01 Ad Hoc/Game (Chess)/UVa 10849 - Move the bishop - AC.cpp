#include <iostream>
#include <cmath>

using namespace std;

struct Pt{
	int x, y;
	Pt(int x = 0, int y = 0)
		:x(x), y(y){}
};

int main(){
	int tc1;
	cin >> tc1;
	while (tc1--){
		int tc2;
		cin >> tc2;

		int n;
		cin >> n;
		while (tc2--){
			Pt s, t; bool noMove = false;
			cin >> s.x >> s.y; if (s.x <1 || s.y>n) noMove = true;
			cin >> t.x >> t.y; if (t.x <1 || t.y>n) noMove = true;

			int dx = abs(s.x - t.x), dy = abs(s.y-t.y);
			if (noMove) { cout << "no move" << endl; continue; }
			if (dx == 0 && dy == 0) cout << 0 << endl;
			else if (dx == dy) cout << 1 << endl;
			else if (dx % 2 == 0 && dy % 2 == 0) cout << 2 << endl;
			else if (dx % 2 == 1 && dy % 2 == 1) cout << 2 << endl;
			else cout << "no move" << endl;
		}
	}
}