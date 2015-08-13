#include <set>
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <functional>

using namespace std;

typedef vector<int> vi;
typedef vector<vi > vvi;
typedef multiset<int, ::greater<int> > msi;
typedef set<msi, ::greater<msi > > smsi;


int main(){
	int n, sum;
	while(cin >> sum >> n && (sum || n)){
		vi num; int tmp;
		for(int i=0 ; i<n ; i++){
			cin >> tmp; num.push_back(tmp);
		}
		
		// Pick a Subset
		smsi ans;
		bool found=0; 
		for(int bit=0 ; bit<(1<<n) ; bit++){
			int tmp=0; msi tmpmsi;
			for(int i=0; i<n ; i++){
				if(bit&(1<<i)) tmp += num[i], tmpmsi.insert(num[i]); 
			}
			if(tmp==sum) ans.insert(tmpmsi), found=1;
		}
		vvi buffer;
		cout << "Sums of " << sum << ":" << endl;
		for(smsi::iterator it1=ans.begin() ; it1!=ans.end() ; it1++){
			bool first = true;
			for(msi::iterator it2=(*it1).begin() ; it2!=(*it1).end() ; it2++){
				if(!first) cout << "+"; first=false;
				cout << *it2;
			} cout << endl;
		}
		if(!found) cout << "NONE" << endl;
	}
}