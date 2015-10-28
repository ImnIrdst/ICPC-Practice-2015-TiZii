#include <iostream>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

int n, m, w, h;
char ans[25][25];
string nstr, mstr;

string int2str(int num){
	stringstream sstr; sstr << num;
	string ret; sstr >> ret; return ret;
}


void init(){
	memset(ans, ' ', sizeof ans);
	nstr = int2str(n); mstr = int2str(m);
	w = 4 * nstr.length() + 5; h = 4 * mstr.length() + 5;
}

void print(){
	// printing corners
	ans[0][0] = ans[h - 1][w - 1] = '+';
	ans[h - 1][0] = ans[0][w - 1] = '+';

	// printing outter corners
	for (int y = 1; y < h - 1; y++) {
		ans[y][0] = '|'; ans[y][w - 1] = '|';
	}
	for (int x = 1; x < w - 1; x++) {
		ans[0][x] = '-'; ans[h - 1][x] = '-';
	}

	// printing n, m
	for (int i = 0, x = 4; i < nstr.length(); i++, x += 4){
		ans[1][x] = nstr[i];
	}
	for (int i = 0, y = 4; i < mstr.length(); i++, y += 4){
		ans[y][w-2] = mstr[i];
	}

	// print inner borders
	for (int x = 2; x < w-2; x+=4){
		ans[2][x] = '+';
		for (int y = 3, j=0; y < h - 2; y++, j++) {
			if (j == 3) j = -1, ans[y][x] = '+';
			else ans[y][x] = '|';
		}
	}
	for (int y = 2; y < h-2; y += 4){
		ans[y][2] = '+';
		for (int x = 3, j = 0; x < w - 2; x++, j++) {
			if (j == 3) j = -1, ans[y][x] = '+';
			else ans[y][x] = '-';
		}
	}
	//print in squares
	for (int y = 3, i=0; y < h - 2; y += 4, i++){
		for (int x = 3, j=0; x < w - 2; x += 4, j++){
			string mul = int2str((nstr[j] - '0')*(mstr[i] - '0'));
			if (mul.size() == 1) mul = "0" + mul;
			ans[y][x] = mul[0]; ans[y + 2][x + 2] = mul[1];
			ans[y][x + 2] = '/'; ans[y + 1][x + 1] = '/'; ans[y + 2][x] = '/';
		}
	}

	// print result
	string mul = int2str(n*m);
	while (mul.size() != nstr.length() + mstr.length()) mul = "0" + mul;
	
	int d =0 , flag = false;
	for (int y = 5; y < h - 2; y+=4){
		if (mul[d] != '0' || flag){
			ans[y][1] = mul[d];
			ans[y + 2][1] = '/';
			flag = true;
		}
		d++;
	}
	for (int x = 3; x < w - 2; x += 4){
		if (mul[d] != '0' || flag){
			ans[h-2][x] = mul[d];
			if(d!=mul.length()-1) ans[h-2][x+2] = '/';
			flag = true;
		}
		d++;
	}

}


int main(){
	while (cin >> n >> m && (n || m)){
		init(); print();

		//print answer
		for (int y = 0; y < h; y++){
			for (int x = 0; x < w; x++){
				cout << ans[y][x];
			} cout << endl;
		}
	}
}