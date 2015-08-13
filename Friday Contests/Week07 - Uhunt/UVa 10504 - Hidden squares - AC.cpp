#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

char table[101][101];

bool InRange(int i , int j , int n){
	return i >= 0 && i < n &&  j >= 0 && j < n;
}

int main()
{
	int n,q;
	bool first = true;
	while(cin >> n && n){
		if(!first) cout << endl;
		first = false;
		cin >> q;
		for(int i = 0 ; i < n ; ++i) cin >> table[i];
		vector<int> count('Z' - 'A' + 1);
		//compute
		for(int i1 = 0 ; i1 < n ; ++i1){
			for(int j1 = 0 ; j1 < n ; ++j1){
				for(int i2 = i1 ; i2 < n ; ++i2){
					for(int j2 = j1 + 1 ; j2 < n ; ++j2){
						/////////////
						if(table[i1][j1] != table[i2][j2]) continue;
						
						int i3 = i2 + (j2 - j1);
						int j3 = j2 - (i2 - i1);
						if(!InRange(i3,j3,n) || table[i1][j1] != table[i3][j3]) continue;

						int i4 = i3 - (i2 - i1);
						int j4 = j3 - (j2 - j1);
						if(!InRange(i4,j4,n) || table[i1][j1] != table[i4][j4]) continue;

						count[table[i1][j1] - 'A']++;
						/////////////
					}
				}
			}
		}
		//query
		char query;
		for(int i = 0 ; i < q ; ++i){
			cin >> query;
			cout << query << " " << count[query - 'A'] << endl;
		}

	}
	return 0;
}