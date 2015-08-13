#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <bitset>
#include <set>
#define INF (int)1e9
#define MAX 100

using namespace std;

int n,m,q,i,j; char a[MAX+10][MAX+10]; enum face{north,south,east,west} f; // f = face;

void left(){
	if(f==north) f=west;
	else if(f==west) f=south;
	else if(f==south) f=east;
	else if(f==east) f=north;
}

void right(){
	if(f==north) f=east;
	else if(f==east) f=south;
	else if(f==south) f=west;
	else if(f==west) f=north;
}

bool check(int i, int j){
	if(i>=0 && j>=0 && i<n && j<m && a[i][j]!='#') return 1;
	return 0;
}

void forward(){
	if(f==north && check(i-1,j)) i--;
	if(f==south && check(i+1,j)) i++;
	if(f==east  && check(i,j+1)) j++;
	if(f==west  && check(i,j-1)) j--;
}

int main(){
	while(cin >> n >> m >> q && (n || m || q)){
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<m ; j++){
				cin >> a[i][j];
				if(a[i][j]=='N'){f=north; ::i=i; ::j=j;}
				if(a[i][j]=='S'){ f=south; ::i=i; ::j=j;}
				if(a[i][j]=='L'){ f=east; ::i=i; ::j=j;}
				if(a[i][j]=='O'){ f=west; ::i=i; ::j=j;}
			}
		}
		char cmd; int ans=0;
		while(q--){
			cin >> cmd;
			if(cmd=='D') right();
			if(cmd=='E') left();
			if(cmd=='F') forward();
			if(cmd=='F' && a[i][j]=='*') ans++,a[i][j]='.';
		}
		cout << ans << endl;
	}
	return 0;
}