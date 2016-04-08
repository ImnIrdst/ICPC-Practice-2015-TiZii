#include <iostream>
#include <vector>

using namespace std;

int main(){
	int tc;
	cin >> tc;
	while (tc--){
		int vis[100] = { 0 };
		int n, k; cin >> n >> k;
		int digit = k;
		int carry = 0;
		vector<int> ans;
		ans.push_back(digit);

		
		
		bool hasAns = true;
		while (true){

			if (vis[n*digit + carry]) {
				hasAns = false; break;
			}
			vis[n*digit + carry] = 1;
			int prev = digit;
			digit = (n*prev + carry) % 10;
			carry = (n*prev + carry) / 10;
			ans.push_back(digit);
			if (carry == 0 && digit == k && prev != 0) break;
			if (carry == 0 && digit == k && prev == 0) {
				hasAns = false; break;
			}
		}
		if (hasAns == false) cout << 0 << endl;
		else{
			ans.pop_back();
			while (!ans.empty()){
				cout << ans.back(); ans.pop_back();
			}
			cout << endl;
		}
	}
}