#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

char mp(char c){
	if('1' <= c && c <= '9') return c-'0';
	if(c == 'T') return 10;
	if(c == 'J') return 11;
	if(c == 'Q') return 12;
	if(c == 'K') return 13;
	if(c == 'A') return 14;
	if(c == 'C') return 15;
	if(c == 'D') return 16;
	if(c == 'S') return 17;
	if(c == 'H') return 18;
}

bool cmp(const string& a, const string& b){
	return (a[0]==b[0] ? mp(a[1])<mp(b[1]) : mp(a[0])<mp(b[0]));
}

int main(){
	char dir;
	while(cin >> dir && dir!='#'){
		vector< vector<string> > ans(4);
		if(dir == 'S') dir=0; if(dir == 'W') dir=1;
		if(dir == 'N') dir=2; if(dir == 'E') dir=3;
		
		string l1, l2; cin >> l1 >> l2; l1+=l2;
		for(int i=(dir+1)%4, j=0 ; j<2*52 ; j+=2, i++, i%=4){
			ans[i].push_back(l1.substr(j,2));
		}
		char dirs[] = "SWNE";
		for(int i=0 ; i<4 ; i++){
			cout << dirs[i] << ":";
			sort(ans[i].begin(), ans[i].end(), cmp);
			for(int j=0 ; j<ans[i].size() ; j++){
				cout << " " << ans[i][j] ;
			}cout << endl;
		}
	}
}