
#include <iostream>
#include <string>
#include <sstream>
#include <cstdio>

using namespace std;

struct Data{
	char type, unit; double val;
	void Eval(char c=' '){
		if(c=='m') val *= 1e-3;
		if(c=='k') val *= 1e3;
		if(c=='M') val *= 1e6;
	}
};

int isVar(char c){
	return (c=='W' || c=='A' || c=='V');
}

Data parse(string s){
	Data d; char tmp, c;
	stringstream sstr(s);
	sstr >> d.type >> tmp >> d.val >> c;
	if(!isVar(c)) d.Eval(c), sstr >> d.unit;
	else d.unit = c;
	return d;
}

int main(){
	string str;	int cs=1;
	int tc; cin >> tc; cin.ignore();
	while(getline(cin, str)){
		Data d[2]; int id=0;
		stringstream sstr(str);
		while(sstr >> str){
			if(str.find('=')!=-1){
				d[id++] = parse(str); 
			}
		}
		printf("Problem #%d\n", cs++);
		if(d[0].type=='U' && d[1].type=='I')
			printf("P=%.2lfW", d[0].val*d[1].val);
		if(d[1].type=='U' && d[0].type=='I')
			printf("P=%.2lfW", d[0].val*d[1].val);
		
		if(d[0].type=='P' && d[1].type=='I')
			printf("U=%.2lfV", d[0].val/d[1].val);
		if(d[1].type=='P' && d[0].type=='I')
			printf("U=%.2lfV", d[1].val/d[0].val);

		if(d[0].type=='U' && d[1].type=='P')
			printf("I=%.2lfA", d[1].val/d[0].val);
		if(d[1].type=='U' && d[0].type=='P')
			printf("I=%.2lfA", d[0].val/d[1].val);
		printf("\n\n");
	}
}