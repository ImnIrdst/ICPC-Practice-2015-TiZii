#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <sstream>

using namespace std;

typedef vector<string> vs;

int diff(string s1, string s2){
	int ret=0; int len1=s1.length(), len2 = s2.length();
	for(int i=0 ; i<s1.length() && i<s2.length() ; i++){
		if(s1[i]!=s2[i]) ret++;
	}
	return ret+abs(len1-len2);
}

int main(){
	int tc; cin >> tc;
	while(tc--){
		string s1,s2; map<string, vs > adj;
		map<string, int> mp; map<string, vs >::iterator it1, it2;
		while(cin >> s1 && s1!="*"){
			adj[s1]=vs();
			for(it1=adj.begin() ; it1!=adj.end() ; it1++){
				// if diffrance of two strings is 1 add them to adj list
				string s2 = it1->first;
				if(s1.length()!=s2.length()) 
					continue;
				
				int diff = 0;
				for(int i=0 ; i<s1.length() && diff<2 ; i++){
					if(s1[i]!=s2[i]) diff++;
				}
				if(diff==1) 
					adj[s1].push_back(s2), adj[s2].push_back(s1);
			}
		}
		string s, d; cin.ignore();
		while(getline(cin,s) && s!=""){
			stringstream sstr(s); sstr >> s >> d;
			queue<string> q; q.push(s);
			map<string, int> dist; dist[s]=0;
			while(!q.empty()){
				string top = q.front(); q.pop();
				if(top == d) break;
				for(int i=0 ; i<adj[top].size() ; i++){
					if(!dist.count(adj[top][i])) q.push(adj[top][i]), dist[adj[top][i]]=dist[top]+1;
				}
			}
			cout << s << " " << d << " " << dist[d] << endl; //cin.ignore();
		}
		if(tc) cout << endl;
	}
}