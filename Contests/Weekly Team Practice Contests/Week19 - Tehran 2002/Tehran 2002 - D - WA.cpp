#include<iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <stack>
#include <queue>
#include<map>
using namespace std;


typedef pair<int, bool> PIB;
typedef vector<PIB >	VI;
typedef vector<VI > VVI;



int main()
{
	int tc;
	cin >> tc;
	while (tc--) {
		int n, id, ch;
		char status;
		cin >> n;
		VVI	adjlist(n, VI());
		map<int, int> dict;
		map<int, int> rev_dict;
		dict.clear();
		rev_dict.clear();
		//reading input
		int index = 0;
		for (int i = 0; i < n; ++i) {
			cin >> id;
			if (dict.find(id) == dict.end()) {
				dict[id] = index;
				rev_dict[index++] = id;
			}
			cin >> ch;
			if (dict.find(ch) == dict.end()) {
				dict[ch] = index;
				rev_dict[index++] = ch;
			}
			cin >> status;
			adjlist[dict[id]].push_back(PIB( dict[ch], status == 'Y'));

			cin >> ch;
			if (dict.find(ch) == dict.end()) {
				dict[ch] = index;
				rev_dict[index++] = ch;
			}
			cin >> status;
			adjlist[dict[id]].push_back(PIB(dict[ch], status == 'Y'));
		}

		//Preprocess the graph
		vector<int> countValid(n, 0);
		vector<int> countInValid(n, 0);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < adjlist[i].size(); ++j) {
				PIB child = adjlist[i][j];
				int childID = child.first;
				bool valid = child.second;
				countValid[childID] += valid;
				countInValid[childID] += !valid;
			}
		}
		//process count lists
		vector<bool> isValid(n, false);
		queue<int> validNodes;
		vector<bool> visited(n, false);
		for (int i = 0; i < n; ++i) {
			if (countValid[i] >= 2 || (countValid[i] > 0 && countInValid[i] > 0)) {
				isValid[i] = true;
				validNodes.push(i);
				visited[i] = true;
			}
		}

		//bfs
		
		while (!validNodes.empty()) {
			int q = validNodes.front(); validNodes.pop();
			visited[q] = true;
			for (int i = 0; i < adjlist[q].size(); ++i) {
				PIB child = adjlist[q][i];
				int childID = child.first;
				bool claim = child.second;
				isValid[childID] = claim;
				if (!visited[childID] && claim)
					validNodes.push(childID);
			}
		}

		//check the visited list
		int unvisitedCount = 0;
		int invalidNode = -1;
		for (int i = 0; i < n; ++i) {
			if (!visited[i]) {
				invalidNode = i;
				unvisitedCount++;
			}
		}

		if (unvisitedCount > 1 || invalidNode == -1) {
			cout << "impossible" << endl;
		}
		else {
			cout << rev_dict[invalidNode] << endl;
		}
	}
	return 0;
}