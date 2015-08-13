#include <iostream>
#include <cstdio>

using namespace std;

enum{LEFTB, RIGHTB, NUM, YES, NO, EMPTY};

static int num;
int get_tok(){
	int c = getchar();
	while(c==' ' || c=='\n') c = getchar();
	
	num=0;
	if(c == '(') return LEFTB;
	if(c == ')') return RIGHTB;
	if('0' <= c && c<='9' || c=='-'){
		int sign = 1; if(c=='-') sign=-1, c=getchar();
		for(; c>='0' && c<='9' ; c=getchar()) num = num*10 + (c-'0');
		num *= sign; ungetc(c,stdin); return NUM;
	}
	return 0;
}

int trav(int sum, int goal){
	get_tok();
	int tok = get_tok();
	if(tok == RIGHTB) return EMPTY;
	else sum += num;
	int left   = trav(sum, goal);
	int right  = trav(sum, goal);
	get_tok();
	if(left==EMPTY && right==EMPTY)
		if(sum == goal) return YES;

	if(left==YES || right==YES) return YES;
	else return NO;
}

int main(){
	int goal;
	while(cin >> goal){
		if(trav(0,goal)==YES) cout << "yes" << endl;
		else				   cout << "no"  << endl;
	}
}