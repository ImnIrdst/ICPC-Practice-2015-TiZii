#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <sstream>
#include <set>
#define INF (int)1e9
#define int64 long long
#define U 0
#define L 1
#define D 2
#define R 3

using namespace std;

int face,x,y; char a[1100][1100];
int h,w, cnt[1100][1100];
bool Begin, Terminate;

void move(){
	if(x==h && y==1 && !Begin){Terminate=true; return;}
	Begin=false;
	if(face==R){
		if(a[x][y+1]!='1' && a[x+1][y]=='1' && !Terminate){
			cnt[x][y]++; y++; move();
		}else if(a[x][y+1]=='1' && a[x+1][y]=='1' && !Terminate){
			face++; face%=4; move();
		}
		else if(a[x+1][y]=='0' && !Terminate){
			cnt[x][y]++; x++;
			face+=4; face--; face%=4; move();
		}
	}
	if(face==D){
		if(a[x+1][y]!='1' && a[x][y-1]=='1' && !Terminate){
			cnt[x][y]++; x++; move();
		}else if(a[x+1][y]=='1' && a[x][y-1]=='1' && !Terminate){
			face++; face%=4; move();
		}
		else if(a[x][y-1]=='0' && !Terminate){
			cnt[x][y]++; y--;
			face+=4; face--; face%=4; move();
		}
	}
	if(face==L){
		if(a[x][y-1]!='1' && a[x-1][y]=='1' && !Terminate){
			cnt[x][y]++; y--; move();
		}else if(a[x][y-1]=='1' && a[x-1][y]=='1' && !Terminate){
			face++; face%=4; move();
		}
		else if(a[x-1][y]=='0' && !Terminate){
			cnt[x][y]++; x--;
			face+=4; face--; face%=4; move();
		}
	}
	if(face==U){
		if(a[x-1][y]!='1' && a[x][y+1]=='1' && !Terminate){
			cnt[x][y]++; x--; move();
		}else if(a[x-1][y]=='1' && a[x][y+1]=='1' && !Terminate){
			face++; face%=4; move();
		}
		else if(a[x][y+1]=='0' && !Terminate){
			cnt[x][y]++; y++;
			face+=4; face--; face%=4; move();
		}
	}
}


int main(){
	
	while(cin >> h >> w && (h || w)){
		face=3; x=h; y=1;
		for(int i=0 ; i<=h+1 ; i++) a[i][0]=a[i][w+1]='1';
		for(int i=0 ; i<=w+1 ; i++) a[0][i]=a[h+1][i]='1';
		for(int i=1 ; i<=h ; i++){
			for(int j=1 ; j<=w ; j++){
				cin >> a[i][j]; cnt[i][j]=0;
			}
		}
		Begin=true; Terminate=false; move();
		int ans[5]={0};
		for(int i=1 ; i<=h ; i++){
			for(int j=1 ; j<=w ; j++){
				if(a[i][j]!='1')
					ans[cnt[i][j]]++;
			}
		}
		for(int i=0 ; i<5 ; i++)
			printf("%3d", ans[i]);
		printf("\n");
	}
	return 0;
}