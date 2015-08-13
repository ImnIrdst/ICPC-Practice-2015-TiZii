#include <iostream>
#include <cstring>

using namespace std;

const int Max = 100+10; char field[Max]; int n, cs=1; 

bool inRange(int i){ return (i>=0 && i<n); }

int main(){
	int tc;
	cin >> tc;
	while( tc-- ){
		int ans=0;
		cin >> n >> field;
		for(int i=0 ; i<n ; i++){
			if(field[i] == '.'){
				if(inRange(i)) field[i]='s';
				if(inRange(i)) field[++i]='s';
				if(inRange(i)) field[++i]='s';
				ans++;
			}
		}
		cout << "Case " << cs++ << ": " << ans << endl;
	}
}