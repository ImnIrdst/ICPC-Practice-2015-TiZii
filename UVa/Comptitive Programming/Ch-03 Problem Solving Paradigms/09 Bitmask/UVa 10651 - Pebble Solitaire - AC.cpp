#include <iostream>
#include <math.h>
#include <algorithm>
#include <fstream>
#include <functional>
#include <string>
#include <bitset>
#define int8 long long
#define p pair<int, int>

#define cost first
#define time second
//#define cin fin
//#define cout fout
#define INF (int)1e9

using namespace std;

int d[1 << 13], mark[1 << 13]; 

int solve(int bit){
	//string stmp; bitset<12> tmp; 
	//tmp=bit; stmp=tmp.to_string(); //for Debug
	int ans=0;
	if(d[bit]!=-1) return d[bit];
	if(mark[bit]) return INF;
	mark[bit]=1;
	for(int i=0 ; i<12 ; i++){
		if(bit&(1<<i))
			ans++;
	}
	int btmp; bool flag;
	for(int i=0 ; i<11 ; i++){
		if((bit&(1<<i))  &&  (bit&(1<<(i+1)))){
			flag=(bit&(1<<(i-1)));
			if(i>0  && flag==0){
				btmp=bit;
				btmp^=(1<<(i-1)); btmp^=(1<<i); btmp^=(1<<(i+1));
				ans=min(ans,solve(btmp));
			}
			flag=(bit&(1<<(i+2)));
			if(i+1<11 && flag==0){
				btmp=bit;
				btmp^=(1<<(i+2)); btmp^=(1<<i); btmp^=(1<<(i+1));
				ans=min(ans,solve(btmp));
			}
		}
	}
	return d[bit]=ans;
}

int main(){
	//ifstream fin("in.txt");
	int tc=1; cin >> tc;
	while(tc--){
		string str; int bit=0;
		cin >> str;
		for(int i=0 ; i<(1<<13) ; i++)
			d[i]=-1, mark[i]=0;

		for(int i=0 ; i<12 ; i++){
			if(str[i]=='o'){
				bit=bit|(1<<i);
			}
		}
		cout << solve(bit) << endl;
	}
	return 0;
}
