#include<iostream>
#include<algorithm>
#include<vector>
#include<functional>
#include<sstream>
#include<string>
#include<set>
#include<map>
using namespace std;

int main()
{
	int tc;
	cin >> tc;
	while (tc--) {
		int n, m;
		cin >> n >> m;
		vector<int> vote_hist(n + 1, 0);
		map<int, vector<int> > votes;
		int today = 0;
		cin.ignore();
		string line;
		//read & save input
		for (int i = 1; i <= m; ++i) {
			getline(cin, line);
			stringstream sstr(line);
			int day_id, free_day;
			sstr >> day_id;
			if (!votes.count(day_id)) {
				votes[day_id] = vector<int>(n + 1, 0);
			}
			while (sstr >> free_day) {
				votes[day_id][free_day]++;
			}
		}
		
		bool cond = true;
		int last_day = -1;
		while(today <= n - 1 && cond){
			//add vote of today
			int tommorow = today + 1;
			if (votes.count(today)) {
				last_day = today;//????????????????
								 //add next day votes to histogram
				for (int i = tommorow; i <= n; ++i) {
					vote_hist[i] += votes[today][i];
				}
			}
			//check if there is someday better that next day exist
			cond = false;
			for (int i = tommorow + 1; i <= n; ++i) {
				if (vote_hist[i] >= vote_hist[tommorow]) {
					cond = true;
					break;
				}
			}
			today++;
		}

		if (today <= n - 1 || last_day == -1) {
			cout << today << endl;
		}
		else {
			int m = vote_hist[last_day+1];
			int index = last_day+1;
			for (int i = index + 1; i <= n; ++i) {
				if (vote_hist[i] >= m) {
					m = vote_hist[i];
					index = i;
				}
			}
			cout << index << endl;
		}
	}
	return 0;
}