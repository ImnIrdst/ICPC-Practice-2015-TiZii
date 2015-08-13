#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int LIS[2005], LDS[2005];

vector<int> sequence;

int lds(int i)
{
  if (LDS[i] != -1) return LDS[i];

  int local_max = 0;
  for(size_t j = i; j < sequence.size(); ++j)
    if (sequence[j] > sequence[i]) local_max = max(local_max, lds(j));

  return LDS[i] = local_max + 1;
}

int lis(int i)
{
  if (LIS[i] != -1) return LIS[i];

  int local_max = 0;
  for(size_t j = i; j < sequence.size(); ++j)
    if (sequence[j] < sequence[i]) local_max = max(local_max, lis(j));

  return LIS[i] = local_max + 1;
}

int main()
{
  int test_cases;
  cin >> test_cases;

  for(size_t i = 0; i < test_cases; ++i) {
    int lines; cin >> lines;

    sequence.clear();

    int tmp;
    for(size_t j = 0; j < lines; ++j) {
      cin >> tmp; sequence.push_back(tmp);
    }

    // reset DP tables
    memset(LIS, -1, sizeof LIS);
    memset(LDS, -1, sizeof LDS);
    LIS[sequence.size()] = 1;
    LDS[sequence.size()] = 1;

    int local_max = 0;
    for(size_t j = 0; j < sequence.size(); ++j)
      local_max = max(local_max, lis(j) + lds(j) - 1);

    cout << local_max << endl;
  }

  return 0;
}
// #include <stdio.h>
// #include <string.h>
// #define max(a,b) ((a)>(b)?(a):(b))

// const int N = 2005;
// int t, n, train[N], dp1[N], dp2[N];

// int solve() {
//   int ans = 0;
//   for (int i = n; i >= 1; i--) {
//     dp1[i] = dp2[i] = 1;
//     for (int j = n; j > i; j--) {
//       if (train[i] > train[j])
//         dp1[i] = max(dp1[i], dp1[j] + 1);
//       else
//         dp2[i] = max(dp2[i], dp2[j] + 1);
//     }
//     ans = max(ans, dp1[i] + dp2[i] - 1);
//   }
//   return ans;
// }

// int main() {
//   scanf("%d", &t);
//   while (t--) {
//     scanf("%d", &n);
//     for (int i = 1; i <= n ; i++)
//       scanf("%d", &train[i]);
//     printf("%d\n", solve());
//   }
//   return 0;
// }

//runtime
// #include <iostream>
// #include <math.h>
// #include <algorithm>
// #include <fstream>
// #include <string>
// #include <map>
// #include <set>
// #include <functional>
// #define int8 long long
// //#define cin fin
// #define INF (double)1e9

// using namespace std;

// set<int> LIS; 
// set<int, greater<int> > LDS; 
// int n;
// int a[1010];

// int main(){
// 	//ifstream fin("in.txt");
// 	int tc; cin >> tc;
// 	while(tc--){
// 		cin >> n;
// 		if(n==0){ cout << 0 << endl; continue;}
// 		int tmp;
// 		for(int i=0 ; i<n ; i++)
// 			cin >> a[i];
// 		LIS.clear(); LDS.clear();
// 		set<int>::iterator itrlis;
// 		set<int, greater<int> >::iterator itrlds;

// 		int ans=0;
// 		for(int i=n-1 ; i>=0 ; i--){
// 			tmp=a[i];
// 			LIS.insert(tmp); itrlis=LIS.find(tmp); itrlis++;
// 			if(itrlis!=LIS.end()){
// 				LIS.erase(itrlis); itrlis=LIS.find(tmp); itrlis++; }

// 			LDS.insert(tmp); itrlds=LDS.find(tmp); itrlds++;
// 			if(itrlds!=LDS.end()){
// 				LDS.erase(itrlds); itrlds=LDS.find(tmp); itrlds++; }
// 			int lis=0; while(itrlis!=LIS.begin()){ 
// 				lis++; itrlis--; }
// 			int lds=0; while(itrlds!=LDS.begin()){ 
// 				lds++; itrlds--; }
// 			ans=max(ans,lis+lds-1);
// 		}

// 		cout << ans << endl;
// 	}
// 	return 0;
// }
