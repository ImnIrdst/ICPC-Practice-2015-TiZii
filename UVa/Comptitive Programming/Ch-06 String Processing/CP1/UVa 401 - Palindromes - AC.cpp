#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

char rev[100]={0}; 

int ismirror(string& str, string& srev){
	string smir=srev;
	for(int i=0 ; i<smir.length() ; i++){
		if(rev[smir[i]]) smir[i]=rev[smir[i]];
		else return false;
	}
	return (smir == str);
}

int main(){
	rev['A']='A'; rev['E']='3'; rev['H']='H';
	rev['I']='I'; rev['J']='L'; rev['L']='J';
	rev['M']='M'; rev['O']='O'; rev['S']='2';
	rev['T']='T'; rev['U']='U'; rev['V']='V';
	rev['W']='W'; rev['X']='X'; rev['Y']='Y';
	rev['Z']='5'; rev['1']='1'; rev['2']='S';
	rev['3']='E'; rev['5']='Z'; rev['8']='8';
	string str;
	while(cin >> str){
		string srev=str; 
		reverse(srev.begin(), srev.end());
		if(str!=srev && !ismirror(str,srev))
			cout << str << " -- is not a palindrome."  << endl;
		if(str==srev && !ismirror(str,srev))
			cout << str << " -- is a regular palindrome."  << endl;
		if(str!=srev &&  ismirror(str,srev))
			cout << str << " -- is a mirrored string."  << endl;
		if(str==srev &&  ismirror(str,srev))
			cout << str << " -- is a mirrored palindrome."  << endl;
		cout << endl;
	}
}