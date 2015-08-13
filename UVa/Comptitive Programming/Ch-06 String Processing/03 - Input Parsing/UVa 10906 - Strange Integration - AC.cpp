
#include <iostream>
#include <string>
#include <ctype.h>
#include <map>

using namespace std;

struct expr{ 
	string a, op, b; 
};

map<string, expr> rel;

string Type(string exp){
	if(rel.count(exp))
		return "exp,"+rel[exp].op;
	return "num";
}

string dfs(string u){
	expr &v = rel[u];
	string ret, lft, rgt;
	if(isdigit(v.a[0])) lft = v.a;
	else                lft = dfs(v.a);

	if(isdigit(v.b[0])) rgt = v.b;
	else				rgt = dfs(v.b);

	string lt=Type(v.a), rt=Type(v.b);
	if(lt == "num" && rt=="num") 
		return lft + v.op + rgt;
	if(v.op == "+"){
		if(rt=="num" || rt=="exp,*")
			return lft + "+" + rgt;
		return lft + "+(" + rgt + ")";
	}else{
		if(lt == "exp,+" && (rt=="exp,+" || rt=="exp,*"))
			return "(" + lft + ")*(" + rgt + ")";
		if(lt == "exp,+")
			return "(" + lft + ")*" + rgt;
		if(rt == "num")
			return lft + "*" + rgt;
		return lft + "*(" + rgt + ")";
	}
	return ret;
}

int main(){
	int tc;
	int cs=1;
	cin >> tc;
	while( tc-- ){
		int n; cin >> n;
		rel.clear();
		string s, tmp; expr ex;
		for(int i=0 ; i<n ; i++){
			cin >> s >> tmp >> ex.a >> ex.op >> ex.b;
			rel[s] = ex;
		}
		cout << "Expression #" << cs++ << ": " << dfs(s) << endl;
	}
}