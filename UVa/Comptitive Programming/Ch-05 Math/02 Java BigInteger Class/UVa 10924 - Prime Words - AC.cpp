#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>

using namespace std;

typedef long long int64;
const int64 MAX = 1e6 + 100;

bitset<MAX> isp;// isprime
vector<int64> primes, pfs, pws; //pfs = prime factors, pws = prime powers

void genprime(){
	isp.set(); isp[0] = isp[1] = 1;
	for (int64 i = 2; i<MAX; i++){
		if (isp[i]){
			primes.push_back(i);
			for (int64 j = i*i; j<MAX; j += i)
				isp[j] = 0;
		}
	}
}

bool isprime(int n){
	if (n<MAX) return isp[n];
	for (int i = 0; i<primes.size() && primes[i] * primes[i] <= n; i++){
		if (n%primes[i] == 0) return 0;
	}
	return 1;
}

int S2I(const string& str){
	int ret = 0;
	for (int i = 0; i<str.length(); i++) {
		if (str[i] >= 'a') {
			ret += str[i] - 'a' + 1;
		}
		else {
			ret += str[i] - 'A' + 27;
		}
	}
	return ret;
}

int main(){
	string str; genprime();
	while (cin >> str){
		int num = S2I(str);
		//cout << s << endl;
		if (isprime(num)){
			cout << "It is a prime word." << endl;
		}
		else{
			cout << "It is not a prime word." << endl;
		}
	}
}

