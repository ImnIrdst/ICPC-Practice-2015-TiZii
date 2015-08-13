#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>

using namespace std;

const int MAX = 256*256;

void parse(string str, int& v, string& p){
	stringstream sstr(str); sstr.ignore();
	sstr >> v ; sstr.ignore(); sstr >> p;
	p[p.length()-1]='\0';
}

int main(){
	string str; int tree[MAX];
	while(cin >> str){
		memset(tree,-1,sizeof tree); int ok=1;
		vector<string> vec;
		do{
			int val; string p; parse(str,val,p);
			
			int node = 1; vec.push_back(str);
			for(int i=0 ; i<p.length() ; i++){
				if(p[i]=='L') node=node*2;
				if(p[i]=='R') node=node*2+1;
			}
			if(tree[node]!=-1) ok=0; tree[node]=val;
		}while(cin >> str && str!="()");

		for(int i=0 ; i<vec.size() ; i++){
			int val; string p; parse(vec[i],val,p);
			
			int node = 1;
			for(int i=0 ; i<p.length() ; i++){
				if(tree[node]==-1) ok=0;
				if(p[i]=='L') node=node*2;
				if(p[i]=='R') node=node*2+1;
			}
		}

		if(ok){
			string ws="";//white space
			for(int i=0 ; i<MAX ; i++){
				if(tree[i]!=-1) cout << ws << tree[i], ws=" ";
			}cout << endl;
		}
		else cout << "not complete" << endl;
	}
	
}