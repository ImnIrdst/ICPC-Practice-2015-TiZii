#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>
#include <string>
#include <sstream>
#include <algorithm>
#define value first
#define isAna second

using namespace std;


typedef long long int64;
typedef pair<int64, bool> pib;
const int64 MAX = 1e3 + 10;

bitset<MAX> isp;// isprime
vector<int64> primes,Anans ;

void genprime(){
    isp.set(); isp[0]=isp[1]=0;
    for(int64 i=2 ; i<MAX; i++){
        if(isp[i]){primes.push_back(i);
            for(int64 j=i*i ; j<MAX ; j+=i) 
				isp[j]=0;
        }
    }
}

bool isprime(int n){
    if(n<MAX) return isp[n];
	for(int i=0 ; i<primes.size() ; i++){
        if(n%primes[i]==0) return 0;
    }
    return 1;
}

int strToint(string str){
	stringstream sstr(str);
	int x; sstr >> x;
	return x;
}

string intToStr(int n){
	stringstream sstr; sstr << n;
	string str; sstr >> str;
	return str;
}

int isAnangram(int n){
	string num = intToStr(n);
	sort(num.begin(), num.end());
	do{
		if(!isprime(strToint(num))) return 0;
	}while(next_permutation(num.begin(),num.end()));
	return 1;
}


int main(){
	int n; genprime();
	for(int i=0 ; i<primes.size() ; i++)
		if(isAnangram(primes[i])) Anans.push_back(primes[i]);
	while(cin >> n && n){
		int ans = 0;
		if(n <= MAX-10){
			for(int i=0 ; i<Anans.size() ; i++){
				if(Anans[i]>n){
					ans = Anans[i]; break;
				}
			}
			if(intToStr(ans).size()!=intToStr(n).size()) ans = 0;
		}
		cout << ans << endl;
	}
}