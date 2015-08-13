#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi > vvi;

int Count1(int bit){
	int ret=0; while(bit) bit-=bit&(-bit), ret++; return ret;
}

int main(){
	int n, l, cs=1;
	while( cin >> n >> l && (n||l)){
		// Tower Description
		vi tower;
		for(int i=0 ; i<n ; i++){
			int tmp; cin >> tmp; tower.push_back(tmp);
		}
		// Intesection Descriptions
		int nn; cin >> nn;
		vi inter(nn,0), intersize(nn,0); 
		for(int i=0 ; i<nn ; i++){
			int m; cin >> m;
			for(int j=0 ; j<m ; j++){
				int tmp; cin >> tmp; inter[i]|=(1<<(tmp-1));
			}
			cin >> intersize[i];
		}
		// Pick a Subset
		int Max = 0, bestbit;
		for(int bit=0 ; bit<(1<<n) ; bit++){
			int Eval=0; 
			if(Count1(bit)!=l) 
				continue;
			for(int i=0; i<n ; i++){
				if(bit&(1<<i)){
					Eval += tower[i]; 
				}
			}
			for(int i=0 ; i<nn ; i++){
				int tmp = Count1(inter[i] & bit);
				if( tmp>1 ) Eval -= (tmp-1)*intersize[i];
			}
			if(Max<Eval) Max=Eval, bestbit=bit;
		}
		cout << "Case Number  " << cs++ << endl;
		cout << "Number of Customers: " << Max << endl;
		cout << "Locations recommended:";
		for(int i=0 ; i<n ; i++){
			if(bestbit&(1<<i)) cout << " " << i+1;// << endl;
		}cout << endl << endl;
	}
}