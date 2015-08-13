#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<string>
#include<functional>
#include<cstring>
using namespace std;

typedef long long int64;
typedef pair<int,int> PII;
typedef pair<PII,char> PIIC;

const int max_N = 35;
PII start,finish;
int n;
set<pair<PII,char> > blocked;

int64 dp_table[max_N][max_N];

int main()
{
	int tc;
	cin >> tc;
	while(tc--){
		cin >> n 
			>> start.first >> start.second >> finish.first >> finish.second;
		int m;
		cin >> m;
		blocked.clear();
		while(m--){
			int x,y;
			char c;
			cin >> x >> y >> c;
			blocked.insert(pair<PII,char>(PII(x,y),c));
		}
		memset(dp_table , 0, sizeof dp_table);
		dp_table[start.first][start.second] = 1;
		for(int i = start.first ; i <= finish.first ; ++i){
			for(int j = start.second ; j <= finish.second ; ++j){
				if(!blocked.count(PIIC(PII(i-1,j),'E')) && !blocked.count(PIIC(PII(i,j),'W'))){
					dp_table[i][j] += dp_table[i-1][j];
				}
				if(!blocked.count(PIIC(PII(i,j-1),'N')) && !blocked.count(PIIC(PII(i,j),'S'))){
					dp_table[i][j] += dp_table[i][j-1];
				}
				i=i;
				//dp_table[i][j] = dp_table[i-1][j] + dp_table[i][j-1];
			}
		}
		cout << dp_table[finish.first][finish.second] << endl;
	}
	return 0;
}
