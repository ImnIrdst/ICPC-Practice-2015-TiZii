#include <algorithm>
#include <iostream>
#include <string>
#include <set>

using namespace std;

int isPalind(string str){
	string rev = str;
	reverse(rev.begin(), rev.end());
	return str == rev;
}

int main(){
	string str;
	while(getline(cin,str)){
		set<string> st;
		for(int i=0 ; i<str.length() ; i++){
			for(int j=i+1 ; j<=str.length() ; j++){
				if(isPalind(str.substr(i,j-i))){
					st.insert(str.substr(i,j-i));
				}
			}
		}
		cout << "The string \'" << str << "\' contains "<< st.size() << " palindromes." << endl;
	}
}