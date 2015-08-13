#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <sstream>
#include <set>
#define eps (double)1e-9
#define int64 long long

using namespace std;

char a[110][110];

int main(){
	int tc,t=1; cin >> tc; cin.get();
	while(tc--){
		char c; string str="";
		while(cin.get(c) && c!='\n'){
			if( 'a'<=c && c<='z')
				str+=c;
		}
		cout << "Case #" << t++ << ":" << endl; 
		double K=sqrt((double)str.length()); int k=(int)(K+eps);

		if(str.length()!=k*k){cout << "No magic :(" << endl; continue;}
		for(int i=0 ; i<k ; i++){
			for(int j=0 ; j<k ; j++){
				a[i][j]=str[i*k+j];
			}
		}
		string str2="", str3="", str4="";
		for(int i=0 ; i<k ; i++){
			for(int j=0 ; j<k ; j++){
				str2+=a[j][i];
			}
		}
		if(str!=str2){cout << "No magic :(" << endl; continue;}
		for(int i=k-1 ; i>=0 ; i--){
			for(int j=k-1 ; j>=0 ; j--){
				str3+=a[j][i];
			}
		}
		if(str!=str2){cout << "No magic :(" << endl; continue;}
		for(int i=k-1 ; i>=0 ; i--){
			for(int j=k-1 ; j>=0 ; j--){
				str4+=a[i][j];
			}
		}
		if(str!=str4){cout << "No magic :(" << endl; continue;}
		cout << k << endl;
	}
	return 0;
}