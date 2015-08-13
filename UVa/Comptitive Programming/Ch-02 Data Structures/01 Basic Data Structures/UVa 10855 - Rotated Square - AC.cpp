#include <iostream>
#include <vector>

using namespace std;

int n, m;
typedef vector<char> vch;
typedef vector<vch > vvch;

void RotateCW(vvch& b){
	vvch tmp(b); //cout << endl; // DEB
	for(int i=0 ; i<m ; i++){
		for(int j=0 ; j<m ; j++){
			//cout << b[i][j]; //DEB
			b[i][j]=tmp[m-j-1][i];
		}
		//cout << endl; // DEB
	}
	//cout << endl; // DEB
}

int CountOCC(vvch& a, vvch& b){
	int cnt=0;
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<n ; j++){
			int tmp=0;
			for(int ii=0 ; ii<m ; ii++){
				for(int jj=0 ; jj<m ; jj++){
					if(i+ii<n && j+jj<n){
						if(a[i+ii][j+jj]==b[ii][jj]) tmp++;
					}
				}
			}
			if(tmp==m*m) cnt++;
		}
	}
	return cnt;
}

int main(){	
	while(cin >> n >> m && (n||m)){
		vvch a(n, vch(n, 0));
		vvch b(m, vch(m, 0));
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<n ; j++){
				cin >> a[i][j];
			}
		}
		for(int i=0 ; i<m ; i++){
			for(int j=0 ; j<m ; j++){
				cin >> b[i][j];
			}
		}
		cout << CountOCC(a, b) << " "; RotateCW(b);
		cout << CountOCC(a, b) << " "; RotateCW(b);
		cout << CountOCC(a, b) << " "; RotateCW(b);
		cout << CountOCC(a, b) <<endl; RotateCW(b);
	}
}