#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;
const int MAX = 9+5;
const double PI = 2*acos(0);

int freq[MAX], n, hasAns;
char arr[MAX][MAX];

void cntSquare(int i1, int j1){
	int i2 = i1+1, j2 = j1+1;
	int size = 1, ok;
	while(i2<=n && j2<=n){
		ok = true;
		if(arr[i2-1][j1] == 'H' || arr[i2-1][j1]=='=') break;
		if(arr[i1][j2-1] == 'V' || arr[i1][j2-1]=='=') break;
		for(int k=j1 ; k<j1+size ; k++) 
			if(arr[i2][k]!='H' && arr[i2][k]!='B') ok = false;
		for(int k=i1 ; k<i1+size ; k++) 
			if(arr[k][j2]!='V' && arr[k][j2]!='B') ok = false;
		if(ok) 
			freq[size]++, hasAns=true; 
		i2++, j2++; size++;
	}
}

int main(){
	int cs=1, first=true;
	while(cin >> n ){
		memset(freq, 0 ,sizeof freq);
		memset(arr ,'=',sizeof arr );
		int m; cin >> m;
		char c; int x, y;
		for(int i=0 ; i<m ; i++){
			cin >> c >> x >> y;// >> c;
			if(c == 'H'){
				if(arr[x][y] == 'V') arr[x][y] = 'B';
				else arr[x][y] = 'H';
			}
			if(c == 'V'){
				if(arr[y][x] == 'H') arr[y][x] = 'B';
				else arr[y][x] = 'V';
			}
		}
		hasAns = false;
		for(int i=1 ; i<n ; i++){
			for(int j=0 ; j<n ; j++){
				if(arr[i][j] == 'B') cntSquare(i,j);
			}
		}
		if (!first) printf ("\n**********************************\n\n"); first = false;
 
        printf ("Problem #%d\n\n", cs++);
 
		if (!hasAns) printf ("No completed squares can be found.\n");
        else {
            for ( int i = 1; i < 12; i++ )
                if ( freq [i] ) printf ("%d square (s) of size %d\n", freq [i], i);
		}
	}
}