#include <queue>
#include <iostream>
#include <cstdio>
#include <vector>


using namespace std;

int main(){
	int n, k;
	while (cin >> n >> k && (n || k)){
		queue<int> q, qi; vector<int> seq(n,0);
		for (int i = 0; i < n; i++)  q.push(40), qi.push(i);
		
		int leave = 0;
		int output = 1;
		int coins = 1;
		while (leave < n){
			int top = q.front(); q.pop();
			int topi = qi.front(); qi.pop();
			
			if (top > output){
				top -= output; output = 0;
				q.push(top); qi.push(topi);
			}
			else{
				seq[leave++] = topi+1;
				output -= top;
			}
			if (output == 0){
				coins = coins % k + 1;  output = coins;
			}
		}

		for (int i = 0; i < n; i++){
			printf("%3d", seq[i]);
		}printf("\n");
	}
}