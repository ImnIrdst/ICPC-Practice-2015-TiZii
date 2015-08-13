#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n;
	while(cin >> n && n){
		vector<int> org(n), goal(n);
		for(int i=0 ; i<n ; i++){
			cin >> org[i] >> goal[i];
		}
		sort(org.begin() , org.end());
		sort(goal.begin(), goal.end());
		if(org == goal) cout << "YES" << endl;
		if(org != goal) cout << "NO"  << endl;
	}
}