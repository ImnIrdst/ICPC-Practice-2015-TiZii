#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#define INF (int)1e9
#define int64 long long

using namespace std;

multiset<int> st; multiset<int>::iterator itr;

int main(){
	int n, m, tmp; long long ans;
	while(scanf("%d",&n) && n){
		st.clear(); ans=0;
		for(int i=0 ; i<n ; i++){
			scanf("%d",&m);
			while(m--){
				scanf("%d",&tmp);
				st.insert(tmp);
			}
			ans-=*(st.begin()); st.erase(st.begin());
			itr=st.end(); itr--;
			ans+=*(itr); st.erase(itr);
		}
		cout << ans << endl;
	}
	return 0;
}