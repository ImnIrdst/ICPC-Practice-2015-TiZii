#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <sstream>
#include <vector>
#define INF (int)1e9
#define int64 long long

using namespace std;

vector<int> par,rnk;

void SetInit(int n){for(int i=0 ; i<n ; i++){ par.push_back(-1); rnk.push_back(0);}}

int Find(int a){
	int i=a,j=a,tmp;
	while(par[i]!=-1){ i=par[i]; }
	while(par[j]!=-1){ tmp=par[j]; par[j]=i; j=tmp; } //path compression
	return i;
}
void Uni(int a, int b){
	int A=Find(a),B=Find(b);
	if(A!=B){
		if(rnk[A]<rnk[B]) swap(A,B); // union using rank
		if(rnk[A]==rnk[B]) rnk[A]++;
		par[B]=A;
	}
}

int main(){
	int tc; cin >> tc; bool first=true;
	while(tc--){
		int n; cin >> n; n++; cin.ignore(); 
		par.clear(); rnk.clear(); int suc=0, unsuc=0;
		string str; stringstream sstr; int a,b; char c; SetInit(n);
		while(getline(cin,str) && str.length()!=0){
			sstr.clear(); sstr << str;
			sstr >> c >> a >> b;
			if(c=='c') Uni(a,b);
			else{
				if(Find(a)==Find(b)) suc++;
				else unsuc++;
			}
		}
		if(!first) printf("\n"); first=false;
		printf("%d,%d\n",suc,unsuc);
	}
	return 0;
}