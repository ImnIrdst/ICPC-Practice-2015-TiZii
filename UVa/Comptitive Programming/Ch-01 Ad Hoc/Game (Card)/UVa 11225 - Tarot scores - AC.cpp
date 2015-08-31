#include <iostream>
#include <string>

using namespace std;

int is_oulder(const string& card){
	if (card == "fool") return true;
	if (card == "one") return true;
	if (card == "twenty-one") return true;
	return false;
}


int val(const string& card){
	if (is_oulder(card)) return 45;
	if (card == "king") return 45;
	if (card == "queen") return 35;
	if (card == "knight") return 25;
	if (card == "jack") return 15;
	return 5;
}


int oulds_score(int count){
	if (count == 3) return 36;
	if (count == 2) return 41;
	if (count == 1) return 51;
	if (count == 0) return 56;
}

int cs = 1;

int main(){
	int tc;
	cin >> tc;
	while (tc--){
		int n; cin >> n;

		
		int oulds=0;
		int score=0;
		while (n--){
			string card, tmp;
			cin >> card; if (card != "fool") cin >> tmp >> tmp;
			score += val(card);
			if(is_oulder(card)) oulds++;
		}

		cout << "Hand #" << cs++ << endl;
		if (score/10 >= oulds_score(oulds)){
			cout << "Game won by " << score / 10  - oulds_score(oulds) << " point(s)." << endl;
		}
		else{
			cout << "Game lost by " << oulds_score(oulds) - score / 10 << " point(s)." << endl;
		}
		if (tc) cout << endl;
	}
}
