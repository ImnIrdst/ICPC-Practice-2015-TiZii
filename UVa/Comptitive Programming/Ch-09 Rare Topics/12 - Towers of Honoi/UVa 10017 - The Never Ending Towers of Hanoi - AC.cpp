#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

typedef vector<int> vi;

int n, m, cs = 1;
vector<int> A, B, C;

void print(const vi& peg, char name) {
	printf("%c=>", name);
	if (peg.size()) {
		printf("  ");
		for (int i = 0; i < peg.size(); i++)
			printf(" %d", peg[i]);
	}
	printf("\n");
	if(name == 'C') printf("\n");
}

void solve(vi& from, vi& mid, vi& to, int n) {
	if (n <= 0) return;
	solve(from, to, mid, n - 1);

	to.push_back(from.back()); from.pop_back();
	if (m-- > 0) 
		print(A, 'A'), print(B, 'B'), print(C, 'C');
	else return;

	solve(mid, from, to, n - 1);
}

int main() {
	while (cin >> n >> m && (n||m)) {
		A.clear(), B.clear(), C.clear();
		for (int i = 0; i < n; i++) A.push_back(n-i);

		printf("Problem #%d\n\n", cs++);
		print(A, 'A'), print(B, 'B'), print(C, 'C');
		
		solve(A, B, C, n);
	}
}