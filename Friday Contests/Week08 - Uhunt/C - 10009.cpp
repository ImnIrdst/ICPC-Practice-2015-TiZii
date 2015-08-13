#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<functional>
#include<map>
#include<string>
#include<vector>
#include<stack>
using namespace std;

#define		 VI			vector<int>
#define		VVI			vector<VI>
#define		PII			pair<int,int>

map<string,int>	 dict;
VVI		adjlist(54,VI());
vector<string> names;

int main()
{
	int m,q,tc;
	bool first = true;
	cin >> tc;
	while(tc--){
		if(!first) cout << endl;
		cin >> m >> q;
		dict.clear();
		names.clear();
		adjlist.assign(54,VI());
		int index = 0;
		while(m--){
			string name;
			int id1,id2;
			cin >> name;
			
			if(!dict.count(name)) {dict[name]=index++;names.push_back(name);}
			id1 = dict[name];
			cin >> name;
			if(!dict.count(name)) {dict[name]=index++;names.push_back(name);}
			id2 = dict[name];
			adjlist[id1].push_back(id2);
			adjlist[id2].push_back(id1);
		}
		//run bfs
		int start,end;
		while(q--){
			//reading input
			string q_name;
			cin >> q_name;
			start = dict[q_name];
			cin >> q_name;
			end = dict[q_name];
			//running bfs
			queue<PII> Q;
			vector<int> parents(54,-1);
			vector<bool> visited(54,false);
			Q.push(PII(start,0));
			while(!Q.empty()){
				PII u_top = Q.front();Q.pop();
				int u = u_top.first;
				int d = u_top.second;
				visited[u] = true;
				for(int i = 0 ; i < adjlist[u].size() ; ++i){
					int v = adjlist[u][i];
					if(v == end){parents[v] = u;break;}
					if(!visited[v]){
						parents[v] = u;
						Q.push(PII(v,d+1));
					}
				}
			}
			//print the path
			stack<char> path;
			path.push(names[end][0]);
			while(parents[end] != -1){
				path.push(names[parents[end]][0]);
				end = parents[end];
			}
			while(!path.empty()){
				cout << path.top();
				path.pop();
			}
			cout << endl;
		}
		
		first = false;
	}
	return 0;
}