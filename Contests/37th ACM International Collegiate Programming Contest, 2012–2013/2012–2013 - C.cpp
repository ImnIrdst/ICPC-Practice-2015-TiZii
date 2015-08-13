#include <iostream>
#include <fstream>

//#define cin fin
//#define cout fout

#define INF 99999999

using namespace std;

int main(){
	ifstream fin("in.txt");
	ofstream fout("out.txt");
	
	int n; cin >> n;

	while(n){
		int b[10002], ans=1; b[0] = INF; b[n+1]=INF;
		
		
		for(int i=1 ; i<=n ; i++){
			if(i%100==0) 
				i=i;
			cin >> b[i];
		}
		int key;
		cin >> key;
		for(int i=key+1 ; i<=n+1 ; i++){
			if(b[i]> b[key]){
				break;
			}
			ans+=b[key]-b[i]+1;
		}

		int flag=1;
		for(int i=key-1 ; i>=0 ; i--){
			if(b[i]> b[key]){
				b[key] = b[i];
				key = i;
				flag=0;
				i--;
				continue;
			}
			ans+=b[key]-b[i]+flag;
		}
		cout << ans << endl;
		cin >> n;
	}
}