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
#define n 1500

using namespace std;

int64 a[1500];//ugly numbers array
set<int64> st;//min heap

int main(){
	st.insert(1);
	for(int i=0 ; i<n ; i++){
		int64 top=*(st.begin()); st.erase(st.begin());
		a[i]=top;
		st.insert(top*2); st.insert(top*3); st.insert(top*5);
	}
	cout << a[n-1] << endl;
	return 0;
}