#include <iostream>
#include <cmath>
#include <set>
#include <vector>
#include <string>

using namespace std;

int gcd(int a, int b){
	return (b == 0 ? a : gcd(b, a%b));
}


struct Ratio{
	int nume, deno;
	Ratio(int numee = 0, int denoo = 1){
		int s = 1;

		if (numee*denoo < 0) s = -1;
		numee = abs(numee), denoo = abs(denoo);

		int ggcd = gcd(numee, denoo);
		numee /= ggcd; denoo /= ggcd;
		
		nume = numee * s;
		deno = denoo;
		if (nume == 0) deno = 1;
	}
	bool operator<(const Ratio& op) const {
		return nume != op.nume ? nume < op.nume : deno < op.deno;
	}
};

set<Ratio> seen;
vector<Ratio> nums;

int x=0, y=1;
void insert(){
	if (x == 0) return;
	if (x == -4 && y == 8)
		y = y;
	Ratio ratio(y, x);
	
	if (!seen.count(ratio)) nums.push_back(ratio), seen.insert(ratio);
}

int main(){
	int bound = 5*1e5 + 10;
	for (int i = 2; nums.size() < bound; i += 2) {
		for (int j = 0; j < i && nums.size() < bound; j++, x++) insert();
		x--, y--;
		for (int j = 0; j < i && nums.size() < bound; j++, y--) insert();
		y++, x--;
		for (int j = 0; j < i && nums.size() < bound; j++, x--) insert();
		x++, y++;
		for (int j = 0; j < i && nums.size() < bound; j++, y++) insert();
	}
	int n;
	while (cin >> n){
		cout << nums[n].nume << " / " << nums[n].deno << endl;
	}
}