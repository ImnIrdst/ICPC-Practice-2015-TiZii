#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAX = 1e7+10;

bool vis[MAX];

int main(){
	int step, mod;
	while(cin >> step >> mod){
		memset(vis, 0, sizeof vis);
		int seed = 0, i;
		for(i=0 ; i<mod ; i++){
			if(vis[seed]) break;
			vis[seed]=1; seed = (seed + step) % mod;
		}

		if(i==mod) printf("%10d%10d    Good Choice\n\n", step, mod);
		if(i!=mod) printf("%10d%10d    Bad Choice\n\n", step, mod);
	}
}