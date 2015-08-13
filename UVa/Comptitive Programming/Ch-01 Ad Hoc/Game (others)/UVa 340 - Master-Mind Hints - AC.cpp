#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int Max = 1000+10; int s[Max], g[Max], mrks[Max], mrkg[Max];

int main(){
	int n,cs=1;
	while(cin >> n && n){
		for(int i=0 ; i<n ; i++) 
			cin >> s[i];
		cout << "Game " << cs++ << ":" << endl;
		while(true){
			int sum=0;
			int week=0, strong=0;
			memset(mrks,0,sizeof mrks);
			memset(mrkg,0,sizeof mrkg);
			for(int i=0 ; i<n ; i++){
				cin >> g[i], sum+=g[i];
				if(g[i]==s[i]) mrks[i]=1, mrkg[i]=1, strong++;
			}
			if(sum==0) break;
			for(int i=0 ; i<n ; i++){
				if(!mrks[i]){
					for(int k=0 ; k<n ; k++){
						if(!mrkg[k] && s[k]==g[i]){
							mrkg[k]=1, week++; break;
						}
					}
				}
			}
			cout << "    (" << strong << "," << week << ")" << endl;
		}
	}
}