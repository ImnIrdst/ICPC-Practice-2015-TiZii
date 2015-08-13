#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <fstream>
#include <string>
#include <string.h>
#include <map>
#include <sstream>
//#define cin fin
#define MAX (int)1e8

using namespace std;

char str[100000000];

int main(){
	//ifstream fin("in.txt");
	
	while(cin >> str && strcmp(str,"#")!=0){
		string str1=str;
		next_permutation(str,str+strlen(str));
		string str2=str;
		cout << (str1<str2 ? str : "No Successor") << endl;
	}
}