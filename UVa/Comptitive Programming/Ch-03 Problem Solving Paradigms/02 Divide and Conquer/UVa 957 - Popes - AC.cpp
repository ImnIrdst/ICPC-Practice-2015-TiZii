#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long int64;

const int MAX = 1e5 + 10;

int64 pops[MAX], freq[MAX * 10];

int64 RSQ(int i, int j){
	if (i == 0) return freq[j];
	else return freq[j] - freq[i - 1];
}

int main(){
	int y;
	while (cin >> y){
		int n; cin >> n; int64 nn = 0;
		memset(freq, 0, sizeof freq);
		for (int i = 0; i < n; i++){
			scanf("%d", &pops[i]); 
			freq[pops[i]]++; nn = max(nn, pops[i]);
		}
		
		for (int i = 1; i < nn; i++) {
			freq[i] += freq[i - 1];
		}

		int64 Max = 0 , lo, hi, hiId, loId;
		for (int i = 0; i <= nn-y; i++){
			int cnt = RSQ(i, i + y - 1);
			
			if (cnt > Max){ Max = cnt;

				loId = upper_bound(pops, pops + n, i) - pops;
				if (loId != 0 && pops[loId-1] == i) loId--;
				if (loId > n - 1) loId = n - 1;

				hiId = lower_bound(pops, pops + n, i + y - 1) - pops;
				if (pops[hiId] != i + y - 1 && hiId != 0) hiId--;
				if (hiId > n - 1) loId = n - 1;

				hi = pops[hiId]; lo = pops[loId];
			}
		}
		cout << Max << " " << lo << " " << hi << endl;
	}
}