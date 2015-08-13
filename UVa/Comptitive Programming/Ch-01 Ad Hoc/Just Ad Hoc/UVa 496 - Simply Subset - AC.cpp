#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <string>
#include <set>

using namespace std;

set<int>::iterator it1, it2;

bool isSubset(set<int>& s1,set<int>& s2){
	for(it1 = s1.begin() ; it1!=s1.end() ; it1++){
		if(!s2.count(*it1)){
			return false;
		}
	}
	return true;
}

bool isDisjoint(set<int>& s1,set<int>& s2){
	for(it1 = s1.begin() ; it1!=s1.end() ; it1++){
		if(s2.count(*it1)){
			return false;
		}
	}
	return true;
}

int main(){
	string str;
	while (getline(cin, str)){
		int tmp;
		set<int> set1, set2;
		stringstream sstr1, sstr2;
		
		sstr1 << str;
		while(sstr1 >> tmp) set1.insert(tmp);
		getline(cin,str); sstr2 << str; 
		while(sstr2 >> tmp) set2.insert(tmp);

		if(isSubset(set1, set2) && isSubset(set2,set1)){
			cout << "A equals B" << endl;
		}
		else if(isSubset(set1,set2)){
			cout << "A is a proper subset of B" << endl;
		}
		else if(isSubset(set2,set1)){
			cout << "B is a proper subset of A" << endl;
		}
		else if(isDisjoint(set1,set2)){
			cout << "A and B are disjoint" << endl;
		}
		else{
			cout << "I'm confused!" << endl;
		}
	}
}