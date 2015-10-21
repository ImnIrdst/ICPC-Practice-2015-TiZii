#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

int main(){
	string word; multiset<string> dict, ans;
	while (getline(cin, word) && word != "#") dict.insert(word);
		//if (!dict.count(word)) dict[word] = 1;
		//else dict[word]++;

	string line;
	while (getline(cin, line) && line != "#"){
		string cmprs = ""; ans.clear(); int cnt = 0;
		for (int i = 0; i < line.length(); i++)
			if (line[i] != ' ') cmprs += line[i];

		for (int sub = 1; sub < (1 << cmprs.length()); sub++){
			string subset = "";
			for (int i = 0; i < cmprs.length(); i++){
				if (sub & (1 << i)) subset += cmprs[i];
			}
			sort(subset.begin(), subset.end());
			do{
				if (dict.count(subset) && !ans.count(subset))
					ans.insert(subset), cnt += dict.count(subset);
			} while (next_permutation(subset.begin(), subset.end()));
		}
		cout << cnt << endl;
	}
}