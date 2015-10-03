#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Job{
	int time, fine, id; Job(){}
	Job(int time, int fine):time(time), fine(fine){}
	bool operator<(const Job op) const {
		return fine*op.time > op.fine*time;
		//return (fine == op.fine ? time > op.time : fine > op.fine);
	}
}; vector<Job> jobs;

int main(){
	int tc;
	cin >> tc;
	while (tc--){
		int n; 
		cin >> n; jobs.resize(n);
		for (int i = 0; i < n; i++){
			cin >> jobs[i].time >> jobs[i].fine; jobs[i].id = i+1;
		}
		sort(jobs.begin(), jobs.end());

		for (int i = 0; i < n; i++){
			if(i!=0) cout << " ";
			cout << jobs[i].id;
		} cout << endl;
		if (tc) cout << endl;
	}
}