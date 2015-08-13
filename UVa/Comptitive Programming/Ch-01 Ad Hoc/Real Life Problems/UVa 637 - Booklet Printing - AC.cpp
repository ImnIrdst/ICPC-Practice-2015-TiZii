#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <sstream>
#include <set>
#include <vector>
#define INF (int)1e9
#define int64 long long
#define p pair<int,int>

using namespace std;

vector<p> ans;

int main(){
	int n;
	while(cin >> n && n){
		int l,r; int mo4=4; while(mo4<n) mo4+=4; //mo4 = Multiple of 4
		if(1<=n) r=1; else r=-1;
		if(mo4<=n) l=mo4; else l=-1;
		ans.push_back(p(l,r));
		for(int i=2 ; i<=mo4/2 ; i++){
			if(i%2==0){
				if(i<=n) l=i; else l=-1;
				if(mo4-i+1<=n) r=mo4-i+1; else r=-1;
				ans.push_back(p(l,r));
			}else{
				if(i<=n) r=i; else r=-1;
				if(mo4-i+1<=n) l=mo4-i+1; else l=-1;
				ans.push_back(p(l,r));
			}
		}
		printf("Printing order for %d pages:\n",n);
		for(int i=0 ; i<ans.size() ;i++){
			if(!(ans[i].first==-1 && ans[i].second==-1)){
				printf("Sheet %d, ",(i/2)+1);
				if(i%2) printf("back :"); else printf("front:");
				if(ans[i].first!=-1 && ans[i].second!=-1){
					printf(" %d, %d\n",ans[i].first,ans[i].second);
				}
				else if(ans[i].first!=-1){
					printf(" %d, Blank\n",ans[i].first);
				}else{
					printf(" Blank, %d\n",ans[i].second);
				}
			}
		}
		ans.clear();
	}
	return 0;
}