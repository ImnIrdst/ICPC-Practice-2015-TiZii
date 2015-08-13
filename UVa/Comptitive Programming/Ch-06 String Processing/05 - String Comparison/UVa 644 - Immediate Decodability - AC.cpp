#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

using namespace std;

bool isperfix(string& a, string& b){	
	int i=0;
	for(i=0 ; i<a.size() ; i++){
		if(a[i]!=b[i]) return false;
	}
	return (i==a.size() && i!=b.size());
}

bool check(vector<string>& v){
	for(int i=0 ; i<v.size() ;i++){	
		for(int j=0 ; j<v.size() ; j++){	
			if(i==j) continue;
			if(isperfix(v[i],v[j])) return false;
		}
	}
	return true;
}

int main(){
	int t=1; string str;
	while(cin >> str ){
		 vector<string> v; v.push_back(str); 
		 while(cin >> str && str!="9") 
			 v.push_back(str);
		if(check(v)) printf("Set %d is immediately decodable\n",t++);
		else printf("Set %d is not immediately decodable\n",t++);
	}
}
/*

01
10
0010
0000
9
01
10
010
0000
9

*/