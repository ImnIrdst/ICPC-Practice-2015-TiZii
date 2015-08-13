#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <sstream>
#define INF (int)1e9
#define int64 long long

using namespace std;

int main(){
	int tc; cin >> tc;
    while(tc--){
         string typ; cin >> typ;
        int row, col; cin >> row >> col;
        if( typ[0] == 'r' ){
            printf("%d\n",min(row,col));
        }else if( typ[0] == 'K'){
            printf("%d\n",( (row+1) / 2 ) * ( (col+1) / 2 ) );
        }else if( typ[0] == 'k' ){
            printf("%d\n",(row*col+1)/2  );
        }else if( typ[0] == 'Q' ){
            printf("%d\n",min(row,col));
        }
    }
	return 0;
}