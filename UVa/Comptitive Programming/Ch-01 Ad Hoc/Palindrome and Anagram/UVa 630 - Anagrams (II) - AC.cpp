#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

int main(){
	int tc;
	cin >> tc;
	while (tc--){
		int n; cin >> n;
		
		map<string, vector<string> > dict;
		for (int i = 0; i < n; i++){
			string str; cin >> str;
			string tmp; tmp = str;
			sort(tmp.begin(), tmp.end());
			if (!dict.count(tmp)){
				dict[tmp] = vector<string>();
			}
			dict[tmp].push_back(str);
		}

		string str;
		while (cin >> str && str != "END"){
			cout << "Anagrams for: " << str << endl;

			string tmp = str;
			sort(tmp.begin(), tmp.end());
			if (dict[tmp].size() == 0){
				cout << "No anagrams for: " << str << endl;
			}
			else{
				int c = 1;
				for (int i = 0; i < dict[tmp].size(); i++){
					printf("%3d) %s\n", i+1, dict[tmp][i].c_str());
				}
			}
		}
		if (tc) cout << endl;
	}
}