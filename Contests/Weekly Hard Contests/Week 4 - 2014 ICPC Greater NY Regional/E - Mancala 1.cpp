#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

const int MAX = 2 * 1e3 + 10;

int ans[MAX][80 + 10] = { 0 };

void preProcess(){
	ans[1][0] = 1;
	ans[1][1] = 1;
	for (int i = 2; i < MAX; i++){
		for (int j = 1; j <= ans[i-1][0]; j++)
			ans[i][j] = ans[i - 1][j];
		for (int j = 1; true ; j++){
			if (ans[i][j] != 0) ans[i][j]--;
			else{
				ans[i][j] = j; ans[i][0] = max(j, ans[i-1][0]); break;
			}
		}
	}
}

int main(){
	int tc;
	cin >> tc;
	preProcess();
	while (tc--){
		int cs, m; cin >> cs >> m;
		
		cout << cs << " " << ans[m][0] << endl;// << " ";
		for (int i = 1; i <= ans[m][0]; i++){
			if (i % 10 != 1) cout << " ";  
			cout << ans[m][i];
			if (i % 10 == 0 || i==ans[m][0]) cout << endl;
		}
	}

}