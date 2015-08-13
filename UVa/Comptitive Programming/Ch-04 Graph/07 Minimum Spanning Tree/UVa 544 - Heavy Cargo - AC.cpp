#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include<vector>
#include <fstream>
#include <map>
#include <sstream>
#include <bitset>
#include <set>
//#define cin fin
#define INF (int)1e9

using namespace std;

int a[210][210],n=101,m,q;
map<string, int> mpsi;


int main(){
	//ifstream fin("in.txt");
	int t=1,w; string x,y; 
	while(cin >> n  >> m && n && m){
		mpsi.clear(); int cnt=1;
		for(int i=0 ; i<110 ; i++){
			for(int j=0 ; j<110 ; j++){
				a[i][j]=0;
			}
			a[i][i]=INF;
		}
		for(int i=0 ; i<m ; i++){
			cin >> x >> y >> w;
			if(!mpsi[x])
				mpsi[x]=cnt++; 
			if(!mpsi[y])
				mpsi[y]=cnt++;

			a[mpsi[x]][mpsi[y]]=w;
			a[mpsi[y]][mpsi[x]]=w;
		}
		for(int k=1 ; k<=n ; k++){
			for(int i=1 ; i<=n ; i++){
				for(int j=1 ; j<=n ; j++){
					a[i][j]=max(a[i][j],min(a[i][k],a[k][j]));
				}
			}
		}
		cin >> x >> y;
		cout << "Scenario #" << t++ << endl;
		cout << a[mpsi[x]][mpsi[y]] << " tons" << endl;
		cout << endl;
	}
	return 0;
}