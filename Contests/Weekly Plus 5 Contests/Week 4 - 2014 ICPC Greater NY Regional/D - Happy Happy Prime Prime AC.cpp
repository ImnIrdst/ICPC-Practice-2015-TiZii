#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>

using namespace std;

const int MAX2 = 1e3 + 10;

typedef long long int64;
const int64 MAX = 1e3 + 100;

bitset<MAX> isp;// isprime
vector<int64> primes;
void genprime(){
	isp.set(); isp[0] = isp[1] = 0;
	for (int64 i = 2; i<MAX; i++){
		if (isp[i]){
			primes.push_back(i);
			for (int64 j = i*i; j<MAX; j += i) isp[j] = 0;
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

int sumOfDigitsSquare(int n){
	if (n == 0) return n;
	int sum = 0;
	while (n){
		sum += (n % 10)*(n % 10);
		n /= 10;
	}
	return sum;
}

int main(){
	int tc;
	cin >> tc;
	genprime();
	while (tc--){
		int cs, n; cin >> cs >> n;
		vector<int> vis(MAX2, 0);
		int nn = n;
		if (!isprime(n)) n = 10;
		else while (n != 1 && !vis[n]){
			vis[n] = true;
			n = sumOfDigitsSquare(n);
		}
		

		if (n == 1) cout << cs << " " << nn << " YES" << endl;
		if (n != 1) cout << cs << " " << nn << " NO" << endl;
	}
}