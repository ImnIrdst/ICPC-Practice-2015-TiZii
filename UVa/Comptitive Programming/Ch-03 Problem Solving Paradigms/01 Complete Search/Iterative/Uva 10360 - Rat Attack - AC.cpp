#include <iostream>
#include <math.h>
#include <algorithm>
#include <fstream>
#include <functional>
#include <string>
#include <bitset>
#include <vector>
#include <sstream>
#include <set>
#define int8 long long
#define p pair<int, int>

#define cost first
#define time second
//#define cin fin
//#define cout fout
#define INF (int)1e9

using namespace std;

int a[1100][1100]={0}, d, n;

int main(){
	//ifstream fin("in.txt");
	int tc; scanf("%d",&tc);
	while(tc--){
		scanf("%d %d",&d, &n);
		int x,y,w;
		for(int k=0 ; k<n ; k++){
			scanf("%d %d %d",&x,&y,&w);
			for(int i=x-d ; i<=x+d ; i++){
				if(!(i>=0 && i<1025)) continue;
				for(int j=y-d ;  j<=y+d ; j++){
					if(!(j>=0 && j<1025)) continue;
					a[i][j]+=w;
				}
			}
		}
		
		int Max=0,Maxi=0, Maxj=0;
		for(int i=0 ; i<1025 ; i++){
			for(int j=0 ; j<1025 ; j++){
				if(Max<a[i][j]){
					Max=a[i][j];
					Maxi=i; Maxj=j;
				}
				a[i][j]=0;
			}
		}
		printf("%d %d %d\n", Maxi , Maxj , Max);
	}
	return 0;
}
