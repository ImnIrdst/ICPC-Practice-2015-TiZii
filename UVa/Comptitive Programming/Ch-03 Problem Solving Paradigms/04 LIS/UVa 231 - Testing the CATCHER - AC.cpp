#include <iostream>
#include <functional>
#include <set>

using namespace std;

int main(){
	int n, cs=1;
	while(cin >> n && n!=-1){
		multiset<int,::greater<int> > st; multiset<int,::greater<int> >::iterator it;
		do{
			st.insert(n); 
			it = st.find(n); 
			while(it!=st.end() && *it==n) 
				it++; 
			if(it!=st.end()) st.erase(it);
			
		}while(cin >> n && n!=-1);

		if(cs!=1) cout << endl;
		cout << "Test #" << cs++ << ":" << endl;
		cout << "  maximum possible interceptions: " << st.size() << endl; 
		
	}
}