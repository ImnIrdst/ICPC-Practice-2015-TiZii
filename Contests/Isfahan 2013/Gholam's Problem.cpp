#include <iostream>

using namespace std;

int main(){
	int tc; cin >> tc;
	while(tc--){
		int start,n,m,tot=0,jahat; cin >> m >> n;
		char a[100];
		for(int i=0 ; i<m ; i++){
			int c; cin >> c;
			if(c) a[i]='w';
			if(!c) a[i]='y';
			if(c==2){ start=i; jahat=1;}
			if(c==3){ start=i; jahat=-1;}
		}
		for(int i=0  ; i<n; i++){
			if(start==m-1) jahat=-1;
			if(start==0) jahat=1;
			start+=jahat;
			if('y'==a[start]) tot++;
		}
		cout << tot << endl;
	}
}