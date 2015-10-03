#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<int> nums;
void check(const string& num) {
	if (num.length() <= 1) return;

	int first = num[0] - '0';
	int idx   = 0;
	int cur   = num[idx] - '0';
	
	for (int i = 0; i < num.length(); i++) {
		if (i!=0 && cur == first) return;
		idx = (idx + cur) % num.length();
		cur = num[idx] - '0';
	}

	if (cur == first) {
		stringstream sstr(num);
		int x; sstr >> x; nums.push_back(x);
	}
}

bool used[10] = { 0 };
void backtrack(const string& num) {
	check(num); 
	if (num.length() > 7) return;
	for (int i = 1; i < 10; i++) {
		if (used[i] == false) {
			used[i] = true;
			backtrack(num + char('0' + i));
			used[i] = false;
		}
	}
}
int main() {
	backtrack("");
	sort(nums.begin(), nums.end());


	int n, cs=1;
	while (cin >> n && n) {
		int i = lower_bound(nums.begin(), nums.end(), n) - nums.begin();

		cout  << "Case " << cs++ << ": " << nums[i] << endl;
	}
}