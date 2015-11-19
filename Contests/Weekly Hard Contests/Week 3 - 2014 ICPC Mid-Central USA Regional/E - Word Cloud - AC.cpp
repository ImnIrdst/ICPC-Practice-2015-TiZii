#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int computeP(double cw, double cmax){
	return 8 + (int)ceil(40.0*(cw - 4) / (cmax - 4));
}

int computeW(double t, double p){
	return ceil((9 * t*p) / 16);
}

int main(){
	int n, w, cs = 1;
	while (cin >> w >> n && (n || w)){
		string word; int c;
		vector<int> len, cnt;

		int cmax = 0;
		for (int i = 0; i < n; i++){
			cin >> word >> c; cmax = max(cmax, c);
			len.push_back(word.length()); cnt.push_back(c);
		}

		int h = 0;
		int i = 0;
		while(i<n){
			int heigh = 0;
			int width = 0;
			while(i<n){
				if (width != 0) width += 10; //computeW(1, 10);
				int p = computeP(cnt[i], cmax);
				width += computeW(len[i], p);
				if (width > w) break; else i++;
				heigh = max(heigh, p);
			}
			h += heigh;
		}
		cout << "CLOUD " << cs++ << ": " << h << endl;

	}
}