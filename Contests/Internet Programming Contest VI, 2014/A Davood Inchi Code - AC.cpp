#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
//#define cin fin
#define INF (long long)1e9

using namespace std;

int main(){
	//ifstream fin("in.txt");
	long long tc; cin >> tc;
	while(tc--){
		long long n; cin >> n; //char c;
		char a[2000]; cin.get(); cin.getline(a,2000); string str=a,pass=""; str="0"+str;
		long long i=1, j=1, offset=0,len=str.length()-1; int cnt=0;
		if(len==1){
			while(n--){
				cout << str[1] ;
			}
			cout << endl;
			continue;
		}
		while(n){
			while(offset+j<=len && n){
				if(str[offset+j]=='-'){
					offset+=j; i=j=1; continue;
				}
				pass+=str[offset+j]; n--;
				if(!n) break;
				long long tmp=j; j+=i; i=tmp;
			}
			//offset=((offset+j+1)%len) - j;
			offset = offset-len;
			while(len-(offset+j)>0 && n){
				if(str[len-(offset+j)]=='-'){ 
					offset+=j; i=j=1; continue;
				}
				pass+=str[len-(offset+j)]; n--;
				if(!n) break;
				long long tmp=j; j+=i; i=tmp; 
			}
			offset = offset-len+2;
		}
		cout << pass << endl;
	}
}