#include <iostream>
#include <cstdio>
#include <vector>
#define pow2(x) ((x)*(x))

using namespace std;

int main() {
	vector<int> q2, q4, q6, q8;
	for (int num = 0; num < 1e2; num++) 
		if (pow2(num / 10 + num%10) == num) q2.push_back(num);
	for (int num = 0; num < 1e4; num++) 
		if (pow2(num / 100 + num % 100) == num) q4.push_back(num);
	for (int num = 0; num < 1e6; num++) 
		if (pow2(num / 1000 + num % 1000) == num) q6.push_back(num);
	for (int num = 0; num < 1e8; num++) 
		if (pow2(num / 10000 + num % 10000) == num) q8.push_back(num);

	int d;
	while (cin >> d) {
		if (d == 2) 
			for (int i = 0; i < q2.size(); i++) printf("%02d\n", q2[i]);
		if (d == 4) 
			for (int i = 0; i < q4.size(); i++) printf("%04d\n", q4[i]);
		if (d == 6) 
			for (int i = 0; i < q6.size(); i++) printf("%06d\n", q6[i]);
		if (d == 8) 
			for (int i = 0; i < q8.size(); i++) printf("%08d\n", q8[i]);
	}
}
