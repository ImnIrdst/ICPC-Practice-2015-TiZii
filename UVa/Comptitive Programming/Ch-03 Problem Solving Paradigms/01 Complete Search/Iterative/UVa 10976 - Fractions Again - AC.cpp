#include <iostream>
#include <vector>

using namespace std;

typedef pair<int,int> pii;
typedef vector<pii > vpii;

int main(){
	int k;
	while(cin >> k){
		vpii ans;
		for(int y=k+1 ; y<=2*k ; y++){
			if((k*y)%(y-k)==0) ans.push_back(pii((k*y)/(y-k), y));
		}
		cout << ans.size() << endl;
		for(int i=0 ; i<ans.size() ; i++){
			cout << "1/" << k << " = 1/"
				 << ans[i].first << " + 1/" << ans[i].second << endl;
		}
	}
}