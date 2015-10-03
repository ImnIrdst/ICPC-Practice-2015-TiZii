#include <iostream>
#include <string>
#include <deque>
#include <cstdio>

using namespace std;

const int Max = 20 + 10;

int cardVal(const string& card){
	char c = card[0];
	if (c == 'A') return 0;
	if (c >= '2' && c <= '9') return c - '1';
	if (c == 'T') return 9;
	if (c == 'J') return 10;
	if (c == 'Q') return 11;
	if (c == 'K') return 12;
}

int main(){
	string card;
	while (cin >> card && card != "#"){
		deque<string> piles[13];
		piles[12].push_back(card);
		for (int i = 0; i < 4; i++){
			for (int j = 12 - !i; j >= 0; j--){
				cin >> card;
				piles[j].push_back(card);
			}
		}

		int cnt = 0;
		int cur = 12;
		string ans="";
		while (!piles[cur].empty()){
			ans = piles[cur].front();
			piles[cur].pop_front();

			cur = cardVal(ans); cnt++;
		}

		printf("%02d,%s\n", cnt, ans.c_str());
	}
}