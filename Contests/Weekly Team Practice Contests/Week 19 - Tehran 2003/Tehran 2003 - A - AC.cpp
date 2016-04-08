#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

const int N = 1e4;

vector<int> nums, hist;

int str2int(const string& str){
	stringstream sstr(str);
	int n; sstr >> n;
	return n;
}

void updateHist(int n){
	if (n == 0){
		hist[0]++; return;
	}
	while (n){
		hist[n % 10]++; n /= 10;
	}
}

int main(){
	string line;
	getline(cin, line);
	int tc = str2int(line);
	while (tc--){
		nums.assign(N,  0);
		hist.assign(10, 0);
		string name;
		getline(cin, name);
		getline(cin, line);
		int n = str2int(line);
		for (int i = 0; i < n; i++){
			getline(cin, line);
			stringstream sstr(line);
			char c; sstr >> c;
			if (c == '-'){
				int a,b,c;
				sstr >> a >> b >> c;
				for (int aa = a; aa <= b; aa += c){
					nums[aa] -= 1e5;
				}					
			}
			
			else if (c == '+'){
				int a, b, c;
				stringstream sstr(line.substr(1));
				sstr >> a >> b >> c;
				for (int aa = a; aa <= b; aa += c){
					nums[aa] += 1;
				}
			}

			else {
				stringstream sstr(line);
				int aa = str2int(line);
				nums[aa]++;
			}
		}

		int adresses = 0, digs = 0;
		for (int i = 0; i < N; i++){
			if (nums[i]>0) updateHist(i) , adresses++;
		}
		cout << name << endl;
		if (adresses != 1) cout << adresses << " addresses" << endl;
		if (adresses == 1) cout << adresses << " address" << endl;
		for (int i = 0; i < 10; i++){
			cout << "Make " << hist[i] << " digit " << i << endl;
			digs += hist[i];
		}
		if (digs != 1) cout << "In total " << digs << " digits" << endl;
		if (digs == 1) cout << "In total " << digs << " digit" << endl;
	}
}