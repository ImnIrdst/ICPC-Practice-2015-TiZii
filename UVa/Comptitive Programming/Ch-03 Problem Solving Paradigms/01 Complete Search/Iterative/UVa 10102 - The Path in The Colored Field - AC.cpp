#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct pii{ int x,y; pii(int x=0, int y=0): x(x), y(y){} };

int dist(pii a, pii b){
	return (abs(a.x-b.x) + abs(a.y-b.y));
}

typedef vector<char> vc;
typedef vector<vc > vvc;
typedef vector<pii> vii;

int main(){
	int n; char c;
	while(cin >> n){
		vii pos3;
		vvc field(n, vc(n)); 
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<n ; j++){
				cin >> field[i][j];
				if(field[i][j]=='3') pos3.push_back(pii(i,j));
			}
		}

		int MaxMin=-1;
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<n ; j++){
				if(field[i][j]=='1'){
					int Min=1e9;
					for(int k=0 ; k<pos3.size() ; k++){
						Min = min(Min, dist(pii(i,j), pos3[k]));
					}
					MaxMin = max(MaxMin, Min);
				}
			}
		}
		cout << MaxMin << endl;
	}
}