#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	while(true){
		cin >> n;
		if(cin.eof()) break;
		vector<int> num(n);
		for(int i = 0 ; i <  n ; ++i) 
			cin >> num[i];
		int m;
		cin >> m;
		sort(num.begin(),num.end());
		int min_dif = 99999999;
		int p1 , p2;
		for(int i = 0 ; i < n; ++i){
			if(m - num[i] >= 0 && binary_search(num.begin() + i + 1,num.end(),m - num[i])){
				if(min_dif > abs(num[i] - (m - num[i]))){
					p1 = min(num[i],m-num[i]);
					p2 = max(num[i],m-num[i]);
					min_dif = p2 - p1;
				}
			}
		}
		printf("Peter should buy books whose prices are %d and %d.\n\n",p1,p2);
	}
	return 0;
}