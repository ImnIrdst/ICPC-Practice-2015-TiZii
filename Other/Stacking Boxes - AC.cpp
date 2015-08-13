#include <iostream>
#include <math.h>
#include <algorithm>
#include <fstream>
#include <string>
#include <map>
#include <stack>
//#define cin fin
#define MAX (int)1e2+1
#define fr( i , n )for( int i = 0; i < n ; i++ )

using namespace std;

int a[30][10], b[30]; int m,n;

bool cmp(int i, int j){
	return a[i][0]<a[j][0];
}

bool sat(int x, int y){
	for(int i=0 ; i<m ; i++){
		if(a[b[x]][i] >= a[b[y]][i]) return 0;
	}
	return 1;
}

void LIS(int lis[30], int path[30]){
 path[0]=b[0];
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<i ; j++){
			if(sat(j,i)){
				if(lis[j]+1>=lis[i]){
					lis[i]=lis[j]+1;
					path[b[i]]=b[j];
				}
			}
		}
	}
}

int main(){
	//ifstream fin("in.txt");
	
	while(cin >> n >> m && m){
		int lis[30]={0}; int path[30]={0};
		if(n==0){ cout << 0 << endl; continue;}
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<m ; j++){
				cin >> a[i][j];
			}
			b[i]=i;
		}

		for(int i=0 ; i<n ; i++){
			sort(a[i],a[i]+m);
		}

		sort(b,b+n,cmp);
		LIS(lis,path);
		int maxIdx=0, maxLis=0;
		for(int i=0 ; i<n ; i++){
			if(lis[i]>=maxLis){
				maxIdx=b[i];
				maxLis=lis[i];
			}
		}
		stack<int> s; s.push(maxIdx+1);
		for(int i=maxIdx, j=0 ; j<maxLis ; j++){
			i=path[i];
			s.push(i+1);
		}
		cout << s.size() << endl;
		while(!s.empty()){ cout << s.top() << " "; s.pop();}
		cout << endl;
	}
	return 0;
}