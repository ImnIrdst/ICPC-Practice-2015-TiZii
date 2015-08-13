#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include<vector>
#include <fstream>
#include <map>
#include <sstream>
#include <bitset>
#include <set>
//#define cin fin
#define INF (int) 1e6

using namespace std;

int n, dfsLow[110], dfsNum[110],col[110],parent[110] , lev, dfsRoot,rootChilds,ans;
vector<int> vec[110]; set<int> ansSet;

void artPoint(int u){
	 dfsLow[u]=dfsNum[u]=lev++; col[u]=1;
	 for(int i=0 ; i<vec[u].size() ; i++){
		 int v=vec[u][i];
		 if(col[v]==0){
			 parent[v]=u;
			 if(u==dfsRoot) rootChilds++;
			 artPoint(v);
			 
			 if(dfsLow[v]>=dfsNum[u]){//artpoint 
				if(u==dfsRoot){
					if(rootChilds>=2){
						ansSet.insert(u);
					}
				}
				else{ 
					ansSet.insert(u);
				}
			 }
			 //if(dfsLow[i]>dfsNum[u])//u,i bridge 
				// ans++;
			 dfsLow[u]=min(dfsLow[u],dfsLow[v]);
		 }
		 else if(parent[u]!=v)
			 dfsLow[u]=min(dfsLow[u],dfsNum[v]);
	 }
	 col[u]=2;
}

int main(){
	//ifstream fin("in.txt");
	while(cin >> n && n){
		for(int i=0 ; i<110 ; i++){ vec[i].clear(); dfsLow[i]=dfsNum[i]=col[i]=parent[i]=0; }
		lev=0;
		string s; stringstream sin; cin.get();
		while(getline(cin,s) && s[0]!='0'){
			sin << s; int x,y; sin >> x;
			while(!sin.eof()){
				sin >> y;
				if(vec[x].end()==find(vec[x].begin(),vec[x].end(),y))
					vec[x].push_back(y); 
				if(vec[y].end()==find(vec[y].begin(),vec[y].end(),y))
					vec[y].push_back(x);
			}
			sin.clear();
		}
		ans=0;
		for(int i=1 ; i<=n ; i++){
			if(col[i]==0){
				dfsRoot=i; rootChilds=0;
				artPoint(i);
			}
		}
		cout << ansSet.size() << endl;
		ansSet.clear();
	}
	return 0;
}