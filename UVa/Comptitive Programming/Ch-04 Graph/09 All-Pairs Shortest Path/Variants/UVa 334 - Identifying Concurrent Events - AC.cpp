#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <map>
#define INF (int)1e9
#define MAX 200

using namespace std;

int adj[MAX+10][MAX+10]; string name[MAX+10]; map<string,int> mp;

int main(){
	int m,t=1,d; string str1, str2;
	while(cin >> m && m){
		int n=0; mp.clear();
		for(int i=0 ; i<MAX ; i++){
			for(int j=0 ; j<MAX ; j++){
				adj[i][j]=0;
			}
		}
		for(int i=0 ; i<m ; i++){
			cin >> d; 
			if(d){ cin >> str1,d--; if(!mp.count(str1)) mp[str1]=n, name[n++]=str1;}
			while(d--){
				cin >> str2;
				if(!mp.count(str1)) mp[str1]=n, name[n++]=str1;
				if(!mp.count(str2)) mp[str2]=n, name[n++]=str2;
				adj[mp[str1]][mp[str2]]=1;
				str1=str2;
			}
		}
		cin >> m;
		while(m--){
			cin >> str1 >> str2;
			if(!mp.count(str1)) mp[str1]=n, name[n++]=str1;
			if(!mp.count(str2)) mp[str2]=n, name[n++]=str2;
			adj[mp[str1]][mp[str2]]=1;
		}
		
		
		for(int k=0 ; k<n ; k++){
			for(int i=0 ; i<n ; i++){
				for(int j=0 ; j<n ; j++){
					adj[i][j]|=(adj[i][k] & adj[k][j]);
				}
			}
		}
		int ans=0;
		for(int i=0 ; i<n ; i++){
			for(int j=i+1 ; j<n ; j++){
				if(!adj[i][j] && !adj[j][i]){
					ans++;
				}
			}
		}
		if(ans==0) 
			printf("Case %d, no concurrent events.\n", t++);
		else{
			printf("Case %d, %d concurrent events:\n", t++, ans);
			int cnt=0;
			for(int i=0 ; i<n && cnt<2; i++){
				for(int j=i+1 ; j<n && cnt<2 ; j++){
					if(!adj[i][j] && !adj[j][i]){
						printf("(%s,%s) ", name[i].c_str(), name[j].c_str());
						cnt++;
					}
				}
			}
			printf("\n");
		}
	}
	return 0;
}
