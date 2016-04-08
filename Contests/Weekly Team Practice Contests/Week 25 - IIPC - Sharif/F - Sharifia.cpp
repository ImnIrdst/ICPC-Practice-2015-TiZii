/*                                            In The Name Of GOD                               */
// Name : Seyed Sobhan Miryoosfei
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <deque>
#include <set>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <fstream>
#include <sstream>

# define For(i, a, b) for(int i=a; _b = b; i<b; ++i)
# define n(x) (int)x.size()
# define all(x) x.begin(),x.end()
# define pb push_back


# define FF first
# define SS second
# define PB push_back

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,int> PII;
typedef long long LL;

const int max_n = 600;
vector<int> adj[max_n][2];
int nei[max_n][2];
bool mrk[max_n][max_n];
int n;
queue<pii> q;

void dfs() {
	while(!q.empty())
		q.pop();
	for(int i=0; i<n; i++){
		q.push(pii(i,i));
		mrk[i][i] = true;
	}
	while(!q.empty()){
		int a, b;
		a=q.front().FF;
		b=q.front().SS;
		q.pop();
		for(int k=0;k<2;k++)
			for(int i=0; i<adj[a][k].size(); i++)
				for(int j=0;j<adj[b][k].size();j++){
					pii u = pii(adj[a][k][i],adj[b][k][j]);
					if( !mrk[u.FF][u.SS] ){
						mrk[u.FF][u.SS]=true;
						q.push(pii(u.FF, u.SS));
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	int T;
	scanf("%d", &T);
	for(int tt=0; tt<T; tt++){
		scanf("%d", &n);
		for(int i=0;i<max_n;i++){
			adj[i][0].clear();
			adj[i][1].clear();
		}
		for(int k=0; k<2; k++)
			for(int i=0; i<n; i++){
				scanf("%d",&nei[i][k]);
				adj[nei[i][k]][k].PB(i);
			}
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++) {
				mrk[i][j] = false;
			}

		dfs();

		bool flag = false;
		for(int i=0; i<n && !flag; i++)
			for(int j=0; j<n && !flag; j++)
				if(!mrk[i][j]) {
					// cerr << i << " " << j << endl;
					cout << "NO" << endl;
					flag = true;
				}
		if( !flag )
			cout << "YES" << endl;

	}


	return 0;
}
