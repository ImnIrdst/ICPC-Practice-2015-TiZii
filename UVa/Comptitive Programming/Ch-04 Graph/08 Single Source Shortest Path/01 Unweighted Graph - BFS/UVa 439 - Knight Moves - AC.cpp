#include <iostream>
#include <cstdio>
#include <queue>
#include <map>

using namespace std;

#define pii pair<int,int> 
#define ii  first 
#define jj  second 

int n=8;
int di[] = {-2,+2,-2,+2,-1,-1,+1,+1};
int dj[] = {-1,-1,+1,+1,-2,+2,-2,+2};

int inRange(int i, int j){
	return (i>=0 && i<n && j>=0 && j<n);	
}

int main(){
	char p1[3] ,p2[3];
	while(cin >> p1 >> p2){
		pii s(p1[0]-'a', p1[1]-'1');
		pii g(p2[0]-'a', p2[1]-'1');
		queue<pii> q; q.push(s);
		map<pii,int> vis; vis[s]=0;
		while(!q.empty()){
			pii top = q.front(); q.pop();
			if(top == g) break;
			for(int d=0 ; d<8 ; d++){
				int i = top.ii+di[d];
				int j = top.jj+dj[d];
				if(inRange(i,j) && !vis.count(pii(i,j))){
					q.push(pii(i,j)); vis[pii(i,j)]=vis[top]+1;
				}
			}
		}
		printf("To get from %s to %s takes %d knight moves.\n", p1, p2, vis[g]);
	}
}