#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 20000 + 10;

int main(){
	int n, m, knight[MAX], head[MAX];
	while(cin >> n >> m && (n||m)){
		for(int i=0 ; i<n ; i++) cin >> head[i];
		for(int j=0 ; j<m ; j++) cin >> knight[j];
		sort(head,head+n); sort(knight,knight+n);

		int i=0, j=0, ans=0;
		for(i=0 ; i<n ; i++, j++){
			while( j<m && knight[j]<head[i] ) j++;
			ans += knight[j];
		}
		if(j<m) cout << ans << endl;
		else    cout << "Loowater is doomed!" << endl;
	}
}