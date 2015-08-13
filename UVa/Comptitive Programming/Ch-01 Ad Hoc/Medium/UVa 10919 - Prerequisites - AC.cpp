#include <iostream>
#include <set>

using namespace std;

int main(){
	int k, m;
	while(cin >> k && k){ cin >> m;
		set<int> taken; int tmp;
		for(int i=0 ; i<k ; i++){
			cin >> tmp; taken.insert(tmp);
		}

		bool yes=true;
		int c, r, cnt, crs;
		for(int i=0 ; i<m ; i++){
			cin >> c >> r; cnt=0;
			for(int j=0 ; j<c ; j++){
				cin >> crs;
				if(taken.count(crs)) cnt++;
			}
			if(cnt<r) yes=false;
		}

		cout << (yes ? "yes" : "no") << endl;
	}
}