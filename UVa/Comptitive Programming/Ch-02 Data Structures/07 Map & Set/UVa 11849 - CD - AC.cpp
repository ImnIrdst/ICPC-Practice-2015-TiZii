#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int main(){
	int n, m, tmp;
	while(scanf("%d %d", &n, &m) && (n||m)){
		set<int> jack, jill;
		for(int i=0 ; i<n ; i++){
			scanf("%d", &tmp); jack.insert(tmp);
		}
		for(int i=0 ; i<m ; i++){
			scanf("%d", &tmp); jill.insert(tmp);
		}

		vector<int> inter(max(n,m), -1);
		set_intersection(jack.begin(), jack.end(), jill.begin(), jill.end(), inter.begin());
		int ans=0;
		for(int i=0 ; i<n ; i++){
			if(inter[i]!=-1) ans++;
		}
		cout << ans << endl;
	}
}