#include <iostream>]
#include <cstring>

using namespace std;

const int Max = 100+10;
int di[] = {-1,+1,+0,+0};
int dj[] = {+0,+0,-1,+1};

int  n, m, d;
char World[Max][Max], NewWorld[Max][Max];

int inRange(int i, int j){
	return (i<n && i>=0 && j<m && j>=0);
}

int main(){
	int tc; 
	cin >> tc;
	while(tc--){
		 cin >> n >> m >> d;
		for(int i=0 ; i<n ; i++) cin >> World[i];

		for(int i=0 ; i<d ; i++){
			memcpy(NewWorld, World, sizeof World);
			for(int i=0 ; i<n ; i++){
				for(int j=0 ; j<m ; j++){
					for(int k=0 ; k<4 ; k++){
						int ii=i+di[k];
						int jj=j+dj[k];
						if(World[i][j]=='R'){
							if(World[ii][jj]=='S') NewWorld[ii][jj]='R';
						}
						if(World[i][j]=='P'){
							if(World[ii][jj]=='R') NewWorld[ii][jj]='P';
						}
						if(World[i][j]=='S'){
							if(World[ii][jj]=='P') NewWorld[ii][jj]='S';
						}
					}
				}
			}
			memcpy(World,NewWorld,sizeof NewWorld);
		}
		for(int i=0 ; i<n ; i++) cout << World[i] << endl;
		if(tc) cout << endl;
	}

}