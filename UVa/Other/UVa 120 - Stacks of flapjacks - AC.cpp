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
	string str;
	while(getline(cin,str)){
		int stack[40], top=0;
		stringstream sstr; sstr << str;
		int frstspc=0; // frstspc = avoiding present error, Dont print first space
		while(sstr >> stack[top++]){
			if(frstspc++) cout << " ";
			cout << stack[top-1];
		}
		top--;
		cout << endl;
		for(int i=top-1 ; i>=0 ; i--){
			int maxnum=-1, maxidx=-1;
			for(int j=0 ; j<=i ; j++){
				if(maxnum <= stack[j]){
					maxnum=stack[j]; maxidx=j;
				}
			}
			if(maxidx!=i){
				if(maxidx!=0){
					cout << top-maxidx << " ";
					for(int j=0 ; j<=maxidx/2 ; j++){
						swap(stack[j],stack[maxidx-j]);
					}
				}
				cout << top-i << " ";
				for(int j=0 ; j<=i/2 ; j++){
					swap(stack[j],stack[i-j]);
				}
			}
		}
		cout << 0 << endl;
	}
	return 0;
}