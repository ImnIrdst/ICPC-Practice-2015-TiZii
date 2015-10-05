#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <cctype>
#include <vector>
#include <cstdio>

using namespace std;


struct Cell{
	int val; 
	bool calced; 
	string exp; Cell(){}
	Cell(const string& e){
		exp = e; stringstream sstr(e);
		if (e[0] != '=') calced = true, sstr >> val; 
		if (e[0] == '=') calced = false, val = -1;
	}
}cell[1000 + 10][18278 + 10];

void calcIdx(const string& str, int& i, int& j){
	string letters = "", digits = "";
	for (int ii = 0; ii < str.length(); ii++){
		if (isdigit(str[ii])) digits += str[ii];
		if (isalpha(str[ii])) letters += str[ii];
	}
	j = 0;
	for(int ii = 0; ii<letters.length(); ii++)
		j*=26, j += (letters[ii] - 'A' + 1);
	stringstream sstr(digits); sstr >> i;
}

int calcCell(int i, int j){
	if (cell[i][j].calced == true)
		return cell[i][j].val;
	
	string tmp = ""; 
	vector<string> toks;
	string& exp = cell[i][j].exp;
	for (int iii = 1; iii < exp.length(); iii++){
		if (exp[iii] == '+') toks.push_back(tmp), tmp = "";
		else tmp += exp[iii];
	} toks.push_back(tmp);

	cell[i][j].val = 0;
	cell[i][j].calced = true;
	for (int iii = 0; iii < toks.size(); iii++){
		int ii, jj; calcIdx(toks[iii], ii, jj);
		cell[i][j].val += calcCell(ii - 1 , jj - 1);
	}
	return cell[i][j].val;
}

int main(){
	int tc;
	cin >> tc;
	while (tc--){
		int n, m; cin >> n >> m;

		char tmp[100];
		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				scanf("%s", tmp);
				cell[i][j] = Cell(tmp);
			}
		}

		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				if (j != 0) cout << " ";
				printf("%d", calcCell(i, j));
			} printf("\n");
		}

	}
}