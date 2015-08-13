#include <iostream>
#include <cstring>

using namespace std;

const int  MAX = 30000;//+10;

int a[10000][10000];
//bool a[MAX][MAX]; 
int n;

int inRange(int x, int y){
	return (x>=0 && x<n && y<n && y>=0);
}

int main(){
	int q, x, y, pw, dir;
	while(cin >> n){
		cin >> q; cout << n << endl;
		/*for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<n ; j++){
				a[i][j]=0;
			}
		}*/
		memset(a, 0, sizeof a);
		cout << n << endl;
		while(q--){
			cin >> x >> y >> pw >> dir; if(pw>MAX) pw=MAX;
			if(dir==0){ // SW
				for(int i=0 ; i<pw ; i++){
					for(int j=0 ; j<pw-i ; j++){
						if(inRange(x+i,y-j)) a[x+i][y-j]=1-a[x+i][y-j];
					}
				}
			}
			if(dir==1){ // SE
				for(int i=0 ; i<pw ; i++){
					for(int j=0 ; j<pw-i ; j++){
						if(inRange(x+i,y+j)) 
							a[x+i][y+j]=1-a[x+i][y+j];
					}
				}
			}
			if(dir==3){ // NW
				for(int i=0 ; i<pw ; i++){
					for(int j=0 ; j<pw-i ; j++){
						if(inRange(x-i,y-j)) a[x-i][y-j]=1-a[x-i][y-j];
					}
				}
			}
			if(dir==2){ // NE
				for(int i=0 ; i<pw ; i++){
					for(int j=0 ; j<pw-i ; j++){
						if(inRange(x-i,y+j)) a[x-i][y+j]=1-a[x-i][y+j];
					}
				}
			}
		}
		int ans=0;
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<n ; j++){
				if(a[i][j]) ans++;
			}
		}
		cout << ans << endl;
	}
}