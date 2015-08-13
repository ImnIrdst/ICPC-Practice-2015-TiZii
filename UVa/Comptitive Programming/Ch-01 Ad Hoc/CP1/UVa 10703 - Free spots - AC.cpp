#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAX = 500 + 10;

int main(){
	int w, h, n; bool b[MAX][MAX];
	while(cin >> w >> h >> n && (w||h||n)){
		int x1, y1, x2, y2; memset(b, 0, sizeof b);
		for(int i=0 ; i<n ; i++){
			cin >> x1 >> y1 >> x2 >> y2;
			for(int x=min(x1,x2) ; x<=max(x1,x2) ; x++){
				for(int y=min(y1,y2) ; y<=max(y1,y2) ; y++){
					b[x][y]=1;
				}
			}
		}
		int ans=0;
		for(int i=1 ; i<=w ; i++){
			for(int j=1 ; j<=h ; j++){
				if(!b[i][j]) ans++;
			}
		}
		if(ans == 0)	  printf("There is no empty spots.\n");
		else if(ans == 1) printf("There is one empty spot.\n");
		else		      printf("There are %d empty spots.\n", ans);
	}
}