#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <vector>
#include <stack>
#define INF (int)1e9
#define int64 long long

using namespace std;

int main(){
	int n, t=0;
	while(!t++){
		cin >> n;
		vector<int> v[30];
		stack<int> st;
		
		for(int i=0 ; i<30 ; i++){v[i].clear(); v[i].push_back(i);}
		while(1){
			string str; cin >> str;
			if(str=="move"){
				int a,b; cin >> a >> str >> b;
				if(str=="onto"){
					for(int i=0 ; i<n ; i++){
						if(find(v[i].begin(),v[i].end(),a)!=v[i].end() && find(v[i].begin(),v[i].end(),b)==v[i].end()){
							for(int j=v[i].size()-1 ; v[i][j]!=a ; j--){
								v[v[i][j]].push_back(v[i][j]);
								v[i].pop_back();
							}
							v[i].pop_back();
						}
					}
					for(int i=0 ; i<n ; i++){
						if(find(v[i].begin(),v[i].end(),b)!=v[i].end() && find(v[i].begin(),v[i].end(),a)==v[i].end()){
							for(int j=v[i].size()-1 ; v[i][j]!=b ; j--){
								v[v[i][j]].push_back(v[i][j]);
								v[i].pop_back();
							}
							v[i].push_back(a);
						}
					}
				}
				else if(str=="over"){
					for(int i =0 ; i<n ; i++){
						if(find(v[i].begin(),v[i].end(),a)!=v[i].end() && find(v[i].begin(),v[i].end(),b)==v[i].end()){
							for(int j=v[i].size()-1 ; v[i][j]!=a ; j--){
								v[v[i][j]].push_back(v[i][j]);
								v[i].pop_back();
							}
							v[i].pop_back();
						}
					}
					for(int i=0 ; i<n ; i++){
						if(find(v[i].begin(),v[i].end(),b)!=v[i].end() && find(v[i].begin(),v[i].end(),a)==v[i].end()){
							v[i].push_back(a);
						}
					}
				}
			}
			else if(str=="pile"){
				int a,b; cin >> a >> str >> b;
				if(str=="onto"){
					for(int i=0 ; i<n ; i++){
						if(find(v[i].begin(),v[i].end(),a)!=v[i].end() && find(v[i].begin(),v[i].end(),b)==v[i].end()){
							for(int j=v[i].size()-1 ; v[i][j]!=a ; j--){
								st.push(v[i][j]);
								v[i].pop_back();
							}
							st.push(a);
							v[i].pop_back();
						}
					}
					for(int i=0 ; i<n ; i++){
						if(find(v[i].begin(),v[i].end(),b)!=v[i].end() && find(v[i].begin(),v[i].end(),a)==v[i].end()){
							for(int j=v[i].size()-1 ; v[i][j]!=b ; j--){
								v[v[i][j]].push_back(v[i][j]);
								v[i].pop_back();
							}
							while(!st.empty()){v[i].push_back(st.top()); st.pop();}
						}
					}
				}
				else if(str=="over"){
					for(int i=0 ; i<n ; i++){
						if(find(v[i].begin(),v[i].end(),a)!=v[i].end() && find(v[i].begin(),v[i].end(),b)==v[i].end()){
							for(int j=v[i].size()-1 ; v[i][j]!=a ; j--){
								st.push(v[i][j]);
								v[i].pop_back();
							}
							st.push(a);
							v[i].pop_back();
						}
					}
					for(int i=0 ; i<n ; i++){
						if(find(v[i].begin(),v[i].end(),b)!=v[i].end() && find(v[i].begin(),v[i].end(),a)==v[i].end()){
							while(!st.empty()){v[i].push_back(st.top()); st.pop();}
						}
					}
				}
			}
			else if(str=="quit") break;
		}
		for(int i=0 ; i<n ; i++){
			cout << i << ":";
			for(int j=0 ; j<v[i].size() ; j++){
				cout << " "  <<  v[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}