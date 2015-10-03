#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

typedef vector<int> vi;
typedef vector<vi > vvi;

vvi adj; string nodes;

int main(){
	string line;
	while (getline(cin, line) && line[0]!='#'){
		// initilize adj and nodes
		adj.assign(26, vi()); nodes = "";
		
		// for each source node add the destination nodes
		for (int i = 0; i < line.length(); i++){
			char u = line[i]; i++; i++; 
			
			// add the nodes to the nodes array
			if (nodes.find(u) == -1) nodes += u;
			while (i < line.length() && line[i] != ';'){
				char v = line[i]; 
				adj[u - 'A'].push_back(v - 'A');
				if (nodes.find(v) == -1) nodes += v;
				i++;
			}
		}
		
		// loop for all permutations of nodes array and calculate the max badwith
		sort(nodes.begin(), nodes.end());
		//int ii = nodes.find('A'); // for Debug
		int Min = 1e9; string ans;
		do{
			int Max = 0;
			for (int i = 0; i < nodes.length(); i++){
				char u = nodes[i];
				for (int j = 0; j < adj[u - 'A'].size(); j++){
					char v = adj[u - 'A'][j] + 'A';
					Max = max(Max, (int)abs(i - (int)nodes.find(v)));
				}
			}
			if (Max < Min){
				Min = Max; ans = nodes;
			}
		} while (next_permutation(nodes.begin(), nodes.end()));
		
		// print the answer
		for (int i = 0; i < ans.length(); i++){
			cout << ans[i] << " ";
		}
		cout << "-> " << Min << endl;
	}
}