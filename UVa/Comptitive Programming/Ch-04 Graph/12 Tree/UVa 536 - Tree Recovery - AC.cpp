#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int i; string pre, in;

struct node{
	node(char c, node* l, node* r): c(c), left(l), right(r){}
	char c; node* left; node* right;
};

node * build(string s){
	char c = pre[i]; int f=s.find(c);
	if(f!=-1){ i++;
			node* Left  = build(s.substr(0, f));
			node* Right = build(s.substr(f+1));
			return new node(c,Left,Right);
	}
	return NULL;
}

void print_post(node* node){
	if(!node) return;
	print_post(node->left);
	print_post(node->right);
	cout << node->c;// << endl;
	delete node;
}

int main(){
	while(cin >> pre >> in){
		i=0;
		print_post(build(string(in))); cout << endl;
	}
}