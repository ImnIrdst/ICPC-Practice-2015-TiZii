#include <iostream>

using namespace std;

int main(){
	int tc;
	int cs=1;
	cin >> tc;
	while(tc--){
		int n; cin >> n;
		
		int freq[101]={0}, tmp;
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<n ; j++){
				cin >> tmp; freq[tmp]++;
			}
		}

		int yes = true;
		for(int i=0 ; i<=100 ; i++){
			if(freq[i]>n) yes=false;
		}
		cout << "Case " << cs++ << ": ";
		cout << (yes ? "yes" : "no") << endl;
	}
}