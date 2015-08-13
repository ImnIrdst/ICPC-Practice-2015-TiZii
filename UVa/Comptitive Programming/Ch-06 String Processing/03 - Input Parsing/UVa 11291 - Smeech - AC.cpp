#include <iostream>
#include <cstdio>
#include <sstream>
#include <string>
#include <cctype>

using namespace std;

const int Max = 1e7;

int id; string expr;

double nextDouble(){
	string str="";
	while(expr[id]!=' ' && expr[id]!=')' && id<expr.size()) str+=expr[id], id++;
	stringstream sstr(str);
	double ret; sstr >> ret; return ret;
}

double eval(){
	double ret = 0; id++;
	double p = nextDouble(), e1, e2; id++;
	if(expr[id]=='(') e1 = eval(); 
	else e1 = nextDouble(); id++;
	if(expr[id]=='(') e2 = eval(); 
	else e2 = nextDouble(); id++;
	return p*(e1+e2)+(1-p)*(e1-e2);
}

int main(){
	while(getline(cin, expr) && expr!="()"){
		id=0;
		if(expr[0]=='(') printf("%.2lf\n", eval());
		else			 printf("%.2lf\n", nextDouble());
	}
}