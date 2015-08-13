#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int y;
string tmp;
vector<string> cards;

int cardval(const string &card) {
  if('2'<=card[0]&& card[0]<='9') return card[0]-'0';
  else return 10;
}

int main(void) {
  int tc,t=1; cin >> tc;

  while(tc--){
    y = 0; cards.clear();
    for (int i = 0; i < 52; i++) {
      cin >> tmp;
      cards.push_back(tmp);
    }
  reverse(cards.begin(), cards.end());
    for (int i = 0; i < 3; i++) {
      int v = cardval(cards[25]);
      y += v;
      cards.erase(cards.begin()+25, cards.begin()+26+(10-v));
    }
  cout << "Case " << t++ << ": " << cards[cards.size()-y] << endl;
  }
  return 0;
}