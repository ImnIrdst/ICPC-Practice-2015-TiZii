#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#define psi pair<string,int>
#define vpsi vector<psi>

using namespace std;

bool cmp(psi a, psi b){
	if(a.second>b.second) return 0;
	if(a.second<b.second) return 1;
	transform(a.first.begin(),a.first.end(),a.first.begin(),::toupper);
	transform(b.first.begin(),b.first.end(),b.first.begin(),::toupper);
	return a.first<b.first;
}

int main(){
	int n; char str[1000];
	while(cin >> n){
		int x,y,z,t; vpsi v;
		for(int i=0 ; i<n ; i++){
			scanf("%s : %d min %d sec %d ms", str, &x, &y, &z);
			v.push_back(psi(str,x*60*1000+y*1000+z));
			//transform(v[i].begin(),v[i].end(),v[i].begin(),::toupper);
		}
		sort(v.begin(),v.end(),cmp);
		for(int i=0 ; i<(n+1)/2 ; i++){
			printf("Row %d\n",i+1);
			for(int j=0 ; j<2 && i*2+j<n ; j++){
				printf("%s\n",v[i*2+j].first.c_str());
			}
		}
		printf("\n");
	}
}

/*

3
Schumacher : 1 min 23 sec 172 ms
Barrichello : 2 min 12 sec 999 ms
Senna : 0 min 55 sec 582 ms
 
4
Schumacher : 1 min 23 sec 172 ms
Barrichello : 2 min 12 sec 999 ms
Senna : 0 min 55 sec 582 ms
Fangio : 1 min 03 sec 000 ms
 
2
BadPilot : 59 min 59 sec 999 ms
ABadPilot : 59 min 59 sec 999 ms

*/