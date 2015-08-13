#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <vector>
#define INF (int)1e9

using namespace std;

vector<int> v[1000010];

int main(){
	int n,q,tmp;
	while(cin >> n >> q){
		for(int i=0 ; i<1000010 ; i++) v[i].clear();
		for(int i=0 ; i<n ; i++){
			cin >> tmp;
			v[tmp].push_back(i+1);
		}
		int ocr, num; // ocr == occurrence 
		for(int i=0 ; i<q; i++){
			cin >> ocr >> num; ocr--;
			if(ocr >= v[num].size()) cout << 0 << endl;
			else cout << v[num][ocr] << endl;
		}
	}

	return 0;
}