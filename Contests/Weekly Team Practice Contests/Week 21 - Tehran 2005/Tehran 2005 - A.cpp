#include <iostream>
#include <algorithm>

using namespace std;

int s[26 + 10], e[26 + 10]; char letter[26 + 10];

int main(){
	int tc; cin >> tc;
	while (tc--){
		int n; cin >> n;
		int Min = 1e9, Max = -1;
		for (int i = 0; i < n; i++){
			cin >> letter[i] >> s[i] >> e[i];
			Max = max(e[i], Max); Min = min(s[i], Min);
		}

		int on[26 + 10] = { 0 };
		for (int i = Min; i < Max; i++){
			for (int j = 0; j < n; j++){
				if (i == s[j] || i==e[j]) 
					on[letter[j] - 'A'] = 1 - on[letter[j] - 'A'];
			}
			int cnt = 0;
			for (int j = 0; j < 26; j++){
				if (on[j]) cnt++;
			}
			if(cnt) cout << char(cnt - 1 + 'A');
		}cout << endl;
	}
}