#include <iostream>
#include <cstring>
#include <string>
#include <map>

using namespace std;

const int Max = 1e3 + 10;

struct dpst{
	int sumVal, bridges;
	dpst(int s=0, int b=0): sumVal(s), bridges(b){}
	bool operator<(const dpst& a) const {
		return (sumVal == a.sumVal ? bridges>a.bridges : sumVal<a.sumVal);
	}
};

dpst dp[Max][Max];
int  os1[Max], os2[Max], val1[Max], val2[Max];

int main(){
	int tc;
	cin >> tc;
	while(tc--){ map<string, int> osmp;
		int n; cin >> n; int oscnt=0;
		for(int i=0 ; i<n ; i++){
			string tmp; cin >> tmp >> tmp;
			if(!osmp.count(tmp)) osmp[tmp] = oscnt++;
			cin >> val1[i]; os1[i] = osmp[tmp];
		}

		int m; cin >> m;
		for(int i=0 ; i<m ; i++){
			string tmp; cin >> tmp >> tmp;
			if(!osmp.count(tmp)) osmp[tmp] = oscnt++;
			cin >> val2[i]; os2[i] = osmp[tmp];
		}
		
		edpst ans;
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<m ; j++){
				dp[i][j] = dpst(0,0);
				if(i>0 && dp[i][j] < dp[i-1][j]) dp[i][j] = dp[i-1][j];
				if(j>0 && dp[i][j] < dp[i][j-1]) dp[i][j] = dp[i][j-1];

				if(os1[i] == os2[j]){
					int SumVal = val1[i] + val2[j], Bridges = 1;
					if( i > 0 && j > 0 )
						SumVal  += dp[i-1][j-1].sumVal,
						Bridges += dp[i-1][j-1].bridges;	
					if( dp[i][j] < dpst(SumVal, Bridges) )
						dp[i][j] = dpst(SumVal, Bridges);
				}
				if(ans < dp[i][j]) ans = dp[i][j];
			}
		}

		cout << ans.sumVal << " " << ans.bridges << endl;
	}
}
