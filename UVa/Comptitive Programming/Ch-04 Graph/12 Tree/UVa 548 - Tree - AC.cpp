#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct tree{
	int node; tree *right, *left;
	tree(){ right = left = NULL;  node = 1e8; }
	tree(int node, tree * right, tree* left) :
		node(node), left(left), right(right){}
};

const int SIZE = 10000+10;
int inord[SIZE], posord[SIZE], n;

tree* buildTree(int *in, int * pos, int len){
	if (len == 0) return NULL;
	int i = len - 1;
	while (pos[len - 1] != in[i]) i--;
	tree * newTree = new tree(
		pos[len - 1],
		buildTree(in, pos, i),
		buildTree(in + i + 1, pos + i, len - i - 1)
		);
	return newTree;
}


int ans, Min;

void dfs(tree *u, int sum){
	if (!u->right && !u->left){
		if (Min > sum + u->node){
			Min = sum + u->node; ans = u->node; delete u; return;
		}
		
	}
	if (u->left) dfs(u->left, sum + u->node);
	if (u->right) dfs(u->right, sum + u->node);
	delete u;
}

int main(){
	string line1, line2;
	while (getline(cin, line1) && getline(cin, line2)){
		stringstream sstr1(line1), sstr2(line2);
		int i = 0; while (sstr1 >> inord[i]) i++;
		int j = 0; while (sstr2 >> posord[j]) j++;
		tree * root = buildTree(inord, posord, j);
		ans = -1; Min = 1e9; dfs(root, 0); cout << ans << endl;
	}
}