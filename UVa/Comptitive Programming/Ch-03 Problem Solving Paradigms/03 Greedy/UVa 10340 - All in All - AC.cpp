#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <math.h>
#include<vector>
#include <fstream>
//#define cin fin
#define INF (int) 1e6

using namespace std;

string s, t;

int main(){
	//ifstream fin("in.txt");
	
	while(cin >> s >> t){
		int i=0, j=-1; int flag=1;
		for(i=0 ; i<s.length() && flag ; i++){
			flag=0;
			for( j++ ; j<t.length() ; j++){
			if(s[i]==t[j]){
					flag=1; break;}
			}
		}
		cout << (i==s.length() && flag ? "Yes" : "No") << endl;
	}
	return 0;
}