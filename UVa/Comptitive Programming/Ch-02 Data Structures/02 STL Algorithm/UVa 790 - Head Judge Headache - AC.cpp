#include <iostream>
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

int iiid;

struct team{
	int id, solvedCnt, time, score; int solved[256];
	team():id(--iiid), solvedCnt(0), time(0), score(0) { 
		memset(solved, 0, sizeof solved); 
	}
	
	void submit(char problem, const string& tme, char status) {
		if (solved[problem] < 0) 
			return;
		
		if (status == 'Y') {
			int h, m; char c;

			stringstream sstr(tme);
			sstr >> h >> c >> m;

			time += 60 * h + m + solved[problem];
			solvedCnt++; solved[problem] = -1;
			score = solvedCnt * 1000000 + time;
		} else {
			solved[problem] += 20;
		}
	}

	bool operator<(const team& op) const {
		if (solvedCnt != op.solvedCnt) return solvedCnt > op.solvedCnt;
		if (time != op.time) return time < op.time;
		if (id != op.id) return id < op.id;
	}
};

struct submition {
	int id; char problem, status; string time;
	bool operator<(const submition& op) const {
		if (time != op.time) return time < op.time;
		if (time == op.time) return status < op.status;
	}
};

int main() {
	int tc;
	cin >> tc; cin.ignore(); cin.ignore();
	while (tc--) {
		string line; int n = 0; team teams[26]; 
		for (int i = 0; i < 26; i++) teams[i].id = i + 1;

		vector<submition> subs; submition sub;
		while (getline(cin, line) && line !="") {
			stringstream sstr(line);
			sstr >> sub.id >>sub.problem >> sub.time >> sub.status;
			subs.push_back(sub);
			n = max(sub.id, n);
		}

		sort(subs.begin(), subs.end());
		for (int i = 0; i < subs.size(); i++) {
			teams[subs[i].id - 1].submit(
				subs[i].problem, subs[i].time, subs[i].status);
		}
		
		sort(teams, teams + n);

		printf("RANK TEAM PRO/SOLVED TIME\n");
		int prevScore = -1, rank = 0;
		for (int i = 0; i<n ; i++) {
			if (teams[i].id < 0) break;
			if (teams[i].score != prevScore) rank=i+1;
			if (teams[i].solvedCnt != 0)
				printf("%4d %4d %4d       %4d\n", rank, teams[i].id, teams[i].solvedCnt, teams[i].time);
			else
				printf("%4d %4d\n", rank, teams[i].id);
			prevScore = teams[i].score;
		}
		if (tc) printf("\n");
		iiid = 0;
	}
}