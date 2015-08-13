#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <map>

using namespace std;

void printpath(int i, map<int,int>& path){
	if(path[i]==-1){ cout << i << endl; return; }
	printpath(path[i], path); cout <<  i << endl;
}

int main(){
	int tc; cin >> tc; cin.ignore(); cin.ignore();
	while(tc--){
		map<int,int> path; multiset<int>::iterator it, it2;
		string str; int n, tmp; multiset<int> st;
		while(getline(cin, str) && str!=""){
			stringstream sstr(str); sstr >> tmp;

			st.insert(tmp); it = st.find(tmp); 
			if(it==st.begin()) path[tmp]=-1; else it--, path[tmp]=*it, it++;
			
			it++; if(it!=st.end()) st.erase(it);
			//for(it2 = st.begin() ; it2!=st.end() ; it2++) 
				//cout << *it2 << " ,"; cout << endl; //for Debug
		}
		cout << "Max hits: " << st.size() << endl;
		it = st.end(); it--; printpath(*it, path); if(tc) cout << endl;
	}
}