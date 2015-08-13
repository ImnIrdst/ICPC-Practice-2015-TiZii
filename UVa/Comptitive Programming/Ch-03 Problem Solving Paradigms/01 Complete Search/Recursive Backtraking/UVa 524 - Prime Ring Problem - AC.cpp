#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> vi;

int n, cs=1;

int isprime(int n){
	for(int i=2 ; i*i<=n ; i++)
		if(n%i==0) return 0;
	return 1;
}

void solve(vi ring, int d){// d depth
	if(d==n){
		if(!isprime(ring[0]+ring[n-1])) return;
		
		string ws="";
		for(int i=0 ; i<ring.size() ; i++){
			cout << ws << ring[i]; ws=" ";
		}cout << endl;
		
		return;
	}
	for(int i=1 ; i<=n ; i++){
		if(find(ring.begin(), ring.end(), i)==ring.end() && isprime(i+ring[d-1])){
			ring.push_back(i); solve(ring, d+1); ring.pop_back();
		}
	}
}

int main(){
	string ws="";//white space;
	while(cin >> n && n){
		cout << ws; ws = "\n";
		cout << "Case " << cs++ << ":" << endl;
		vi ring; ring.push_back(1); solve(ring, 1);
	}
}