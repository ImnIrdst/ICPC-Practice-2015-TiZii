#include<iostream>
#include<algorithm>
using namespace std;

#define		MAX_LINE		8
#define		FR(i,s,e)		for(int i = (s) ; i <= (e) ; ++i)

char table[MAX_LINE][MAX_LINE + 1];

bool Valid(char c)
{
	switch(c){
	case 'I':
	case 'E':
	case 'H':
	case 'O':
	case 'V':
	case 'A':
	case '#':
		return true;
	default:
		return false;
	}
	return false;
}

int main()
{
	int tc;
	cin >> tc;
	while(tc--){
		int m,n;
		cin >> m >> n;
		FR(i,0,m-1) cin >> table[i];
		int start = 0;
		FR(i,0,n-1){
			if(table[m-1][i] == '@'){
				start = i;
				break;
			}
		}
		int level = m - 1;
		int parent = -1;
		bool first = true;
		while(table[level][start] != '#'){
			if(!first){
				cout << " ";
			}
			first = false;
			if(Valid(table[level - 1][start])){
				cout << "forth";
				level--;
				parent = -1;
			}
			else if(parent != 1 && start - 1 >= 0 && Valid(table[level][start - 1])){
				cout << "left";
				start--;
				parent = 0;
			}
			else if(parent != 0 && start + 1 < n && Valid(table[level][start + 1])){
				cout << "right";
				start++;
				parent = 1;
			}
		}
		cout << endl;
	}
	return 0;
}