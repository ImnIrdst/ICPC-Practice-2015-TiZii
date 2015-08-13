#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef vector<int> vi;
typedef vector<vi > vvi;

int CountZeros(const vi& bmi, int js, int je){
	int cnt=0;
	for(int j=js ; j<je ; j++){
		if(bmi[j]==0) cnt++;
	} return cnt;
}
// is => istart, ie => iend, im => imid;
void BtoD(const vvi& bm, int is, int ie, int js, int je, int& printed){
	if(is==ie || js==je) return;

	int zeros = 0;
	for(int i=is ; i<ie ; i++){
		zeros += CountZeros(bm[i], js, je);
	}
	if(printed>0 && printed%50 == 0) cout << endl; printed++;
	if(zeros == (ie-is)*(je-js)) cout << 0;
	else if(zeros == 0) cout << 1;
	else{
		cout << 'D';
		int im = (is+ie+1)/2, jm=(js+je+1)/2;
		BtoD(bm, is, im, js, jm, printed);
		BtoD(bm, is, im, jm, je, printed);
		BtoD(bm, im, ie, js, jm, printed);
		BtoD(bm, im, ie, jm, je, printed);
	}
}

void DtoB(vvi& bm, int is, int ie, int js, int je){
	if(is==ie || js==je) return;
	int ch = cin.get();
	if( ch == '0' || ch == '1'){
		for(int i=is ; i<ie ; i++){
			for(int j=js ; j<je ; j++){
				bm[i][j] = ch - '0';
			}
		}
		return;
	}
	else{
		int im = (is+ie+1)/2, jm=(js+je+1)/2;
		DtoB(bm, is, im, js, jm);
		DtoB(bm, is, im, jm, je);
		DtoB(bm, im, ie, js, jm);
		DtoB(bm, im, ie, jm, je);
	}
}

int main(){
	char c;
	while(cin >> c && c!='#'){
		int n, m; cin >> n >> m; cin.ignore();
		printf("%c%4d%4d\n", (c == 'B' ? 'D' : 'B'), n, m);

		vvi bm(n, vi(m));
		if( c == 'B'){
			string s, tmp;
			while(s.size() < n*m){
				cin >> tmp; s+=tmp;
			}
			for(int i=0 ; i<n ; i++){
				for(int j=0 ; j<m ; j++){
					bm[i][j]=s[i*m+j]-'0';
				}
			}
			int printed=0;
			BtoD(bm, 0, n, 0, m, printed); cout << endl;
		}
		if( c == 'D' ){
			DtoB(bm, 0, n, 0, m);
			for(int i=0 ; i<n ; i++){
				for(int j=0 ; j<m ; j++){
					if(i+j>0 && (i*m+j)%50==0) cout << endl;
					cout << bm[i][j];
				}
			}
			cout << endl;
		}
	}
}
