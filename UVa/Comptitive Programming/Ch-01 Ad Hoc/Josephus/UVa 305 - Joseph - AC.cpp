#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <sstream>
#define INF (int)1e9
#define int64 long long

using namespace std;

bool calc(int k, int m) {
  int size = 2 * k;
 
  int current = (m - 1) % size;
  int i = 0;
  for (i = 0; i < 2 * k; i++) {
    if (current < k) break;
    size--;
    current = (current + m - 1) % (size);
  }
 
  return i==k;
}
 
int main () {
  int k;
  //we can also use filling dp table, and present an solution in o(1)
  /*int ans[15] = {
    0, 2, 7, 5, 30, 169, 441, 1872, 7632, 1740,
    93313, 459901, 1358657, 2504881, 13482720
  };*/
  int ans[15];
  for (int i = 1; i <= 14; i++) {
    for (int j = 1;; j++) {
      if (calc(i,j)) {
        ans[i] = j; 
        break;
      }
    }
  }
  while(cin >> k && k){
	  cout << ans[k] << endl;
  }
}