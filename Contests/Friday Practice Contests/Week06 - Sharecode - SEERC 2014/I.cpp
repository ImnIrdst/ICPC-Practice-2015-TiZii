#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<functional>
using namespace std;

typedef	pair<int,int>		PII;
typedef unsigned long long ull;

int main()
{
	int tc;
	cin >> tc;
	while(tc--){
		int ns1,ns2,m;
		vector<PII> time[2];
		//reading inputs
		cin >> ns1 >> ns2 >> m;
		for(int i = 0 ; i < 2 ; ++i){
			for(int j = 0 ; j < m ; ++j){
				int t;
				cin >> t;
				time[i].push_back(PII(t,j));
			}
		}
		//calculate
		sort(time[0].begin(),time[0].end());
		sort(time[1].begin(),time[1].end());

		ull min_time;
		if(ns1 > ns2){
			min_time = ns1 * time[0][0].first;
			if(m > 1){
				if(time[1][0].second != time[0][0].second){
					min_time = max<ull>(min_time,ns2 * time[1][0].first);
				}
				else{
					ull step_parallel = (ull)(min_time / time[1][1].first);
					ull step_remain = ns2 - step_parallel;
					min_time += step_remain * time[1][0].first;
				}
			}
			else{
				min_time += ns2 * time[1][0].first;
			}

		}
		else{
			min_time = ns2 * time[1][0].first;
			if(m > 1){
				if(time[1][0].second != time[0][0].second){
					min_time = max<ull>(min_time,ns1 * time[0][0].first);
				}
				else{
					ull step_parallel = (ull)(min_time / time[0][1].first);
					ull step_remain = ns1 - step_parallel;
					min_time += step_remain * time[0][0].first;
				}
			}
			else{
				min_time += ns1 * time[0][0].first;
			}
		}
		cout << min_time << endl;
	}
	return 0;
}