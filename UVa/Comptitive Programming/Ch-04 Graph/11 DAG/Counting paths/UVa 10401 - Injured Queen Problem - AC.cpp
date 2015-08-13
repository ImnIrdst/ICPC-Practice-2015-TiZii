#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <queue>
#define INF (int)1e9
#define MAX (15+10)
#define int64 long long

using namespace std;

int64 a[MAX][MAX],n;

int inRange(int i, int j){return (i>=0 && j>=0 && j<n && i<n);}

void print(){
	cout << endl << n << endl;
	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<n ; j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int main(){
	string str;
	while(cin >> str){
		memset(a,0,sizeof a); 
		bool zero=0; n=str.length();
		//if(n==0) continue;
		for(int i=0 ; i<str.length()  && !zero; i++){
			if(str[i]=='?') continue; 
			int j; 
			if('1'<=str[i] && str[i]<='9') j=str[i]-'1';
			if('A'<=str[i] && str[i]<='F') j=str[i]-'A'+9;
			if(a[j][i]==-1) zero=1,cout << 0 << endl; 
			for(int x=-1 ; x<=1 ; x++){
				for(int y=-1 ; y<=1 ; y++){
					if(inRange(j+x,i+y)){
						a[j+x][i+y]=-1;
					}
				}
			}	
			for(int x=0 ; x<n ; x++) a[x][i]=-1;
			a[j][i]=0;
		}
		if(zero) continue;
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<n ; j++){
				if(a[j][i]!=-1){
					if(i==0) a[j][i]=1;
					for(int k=0 ; k<n ; k++){
						if(a[k][i+1]!=-1 && abs(k-j)>1){
							a[k][i+1]+=a[j][i];
						}
					}
				}
			}
		}
		int64 ans=0;
		for(int i=0 ; i<n ; i++) ans+=(a[i][n-1]==-1 ? 0 : a[i][n-1]); 
		cout << ans << endl;
	}
	return 0;
}