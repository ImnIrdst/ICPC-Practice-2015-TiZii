#include <iostream>
#include <queue>
#include <map>
#include <vector>

using namespace std;

struct p{
	p(int X, int Y, int V){x=X; y=Y; level=V;}
	p(){};
	int x,y,level;
};

int valid(p tmp, int bfs[][100] , char a[][100], int m, int n){
	if(bfs[tmp.x][tmp.y]==0 
		&& tmp.x<n && tmp.x>=0 
		&& tmp.y<m && tmp.y>=0
		&& a[tmp.x][tmp.y]!='#' 
		&& a[tmp.x][tmp.y]!='F'
		&& a[tmp.x][tmp.y]!='*')
		return 1;
	return 0;
}

int main(){
	int n,m; cin >> n >> m;

	while(n && m){
		char a[100][100];
		int bfs[100][100]={0};
		p exit;

		queue<p> qp;
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<m ; j++){
				cin >> a[i][j];
				if(a[i][j]=='*'){
					exit.x=i;
					exit.y=j;
					exit.level=0;
				}
			}
		}
		qp.push(exit); int level=0, Maxlev;
		while(!qp.empty()){
			p tmp;
			tmp=qp.front(); qp.pop();
			Maxlev=bfs[tmp.x][tmp.y]=tmp.level;
			if(valid(p(tmp.x+1,tmp.y,0), bfs, a, m, n ))
				qp.push(p(tmp.x+1,tmp.y,tmp.level+1));
			if(valid(p(tmp.x-1,tmp.y,0), bfs, a, m, n ))
				qp.push(p(tmp.x-1,tmp.y,tmp.level+1));
			if(valid(p(tmp.x,tmp.y+1,0), bfs, a, m, n ))
				qp.push(p(tmp.x,tmp.y+1,tmp.level+1));
			if(valid(p(tmp.x,tmp.y-1,0), bfs, a, m, n))
				qp.push(p(tmp.x,tmp.y-1,tmp.level+1));
		}
		int cnt=0;
		for(int i=0 ; i<n; i++){
			for(int j=0 ; j<m ; j++){
				if(a[i][j]=='P') cnt++;
			}
		}
		cout << max(Maxlev,cnt) << endl;
		cin >> n >> m;
	}
}