#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<int , int> cows[5]; int ans[20000];

int cmp(int a , int b){
	int cnt=0;
	for(int i=0 ; i<5 ; i++)
		cnt += cows[i][a] < cows[i][b];
	return cnt>2;
}

int main(){
	int tc; cin >> tc;
	while(tc--){
		int n,temp;
		cin >> n;
		for(int i=0 ; i<5 ; i++){
			for(int j=0 ; j<n ; j++){
				cin >> temp;
				cows[i][temp]=j;
				ans[j]=temp;
			}
		}
		sort(ans,ans+n,cmp);
		for(int i=0 ; i<n ; i++)
			cout << ans[i] << endl;
	}
	
}

/*
1
5
10 
20 
30 
40 
50

20
10
30
40
50

30
10
20
40
50

40
10
20
30
50

50
10
20
30
40
*/