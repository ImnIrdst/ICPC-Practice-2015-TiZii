#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <bitset>
#include <vector>
#define INF (int)1e9
#define MAX 1000

using namespace std;

vector<char> adj[MAX+10]; int candle[MAX+10],d;
void bfs(char t, char m, int cnt){
	if((++cnt)%d==0) candle[m]=1;
	for(int i=0 ; i<adj[m].size() ; i++){
		char v=adj[m][i];
		if(!candle[v] && v!=t){
			if(candle[m]) cout << m << " ";
			bfs(m,v,cnt);
			return;
		}
	}
	cout << "/" << m << endl;
}

int main(){
	char c;
	while(c=getchar()){
		for(int i=0 ; i<MAX+10 ; i++) adj[i].clear(), candle[i]=0;
		if(c=='#') return 0;
		while(c!='.'){
			char u=c; c=getchar(); c=getchar(); 
			while(c!=';' && c!='.'){
				adj[u].push_back(c);
				c=getchar(); 
			}
			if(c=='.') break;
			c=getchar(); 
		}
		char t, m; // t = theseus first pos, m = Minotaur first pos, d = distance for candies
		scanf(" %c %c %d", &m, &t, &d); 
		bfs(t,m,0);
		c=getchar();
	}
	return 0;
}