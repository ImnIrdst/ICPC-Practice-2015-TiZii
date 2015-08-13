#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

const int MAX = 1e6 + 10;

int sum[MAX];

int main(){
	int cs=1;
	string seq;
	while(cin >> seq){
		memset(sum, 0, sizeof sum);
		sum[0] = 0; sum[1] = seq[0]-'0';
		for(int k=2 ; k<seq.length()+2 ; k++){
			sum[k]=sum[k-1]+(seq[k-1]-'0');
		}
		cout << "Case " << cs++ << ":" << endl;
		int q; cin >> q;
		while(q--){
			int i, j; cin >> i >> j; //cout << i << " " << j;
			if((max(i,j)-min(i,j)+1 == sum[max(i,j)+1]-sum[min(i,j)]
				|| sum[max(i,j)+1]-sum[min(i,j)] == 0) && i<seq.length() && j<seq.length())
				cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
}