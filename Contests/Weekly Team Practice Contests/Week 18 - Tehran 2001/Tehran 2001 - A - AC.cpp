#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(){
	int tc;
	cin >> tc;
	while (tc--){
		int n, pi; cin >> n;
		vector<int> p, w, s;
		for (int i = 0; i < n; i++){
			cin >> pi; p.push_back(pi);
			if (i == 0){
				for (int j = 0; j < pi; j++){
					s.push_back(1);
				}
				s.push_back(2);
			}
			else{
				for (int j = 0; j < p[i] - p[i - 1]; j++){
					s.push_back(1);
				}
				s.push_back(2);
			}
		}
		stack<int> stk; vector<int> ans;
		for (int i = 0; i < s.size(); i++){
			if (s[i] != 2) continue;

			int tmp = 0; stk.push(s[i]);
			for (int j = i-1; j >= 0 && !stk.empty(); j--){
				if (s[j] == 2){
					stk.push(s[j]);
				}
				else{
					stk.pop(); tmp++;
				}
			}
			ans.push_back(tmp);
		}
		for (int i = 0; i < ans.size(); i++){
			if (i != 0) cout << " ";
			cout << ans[i];
		}
		cout << endl;
	}
}