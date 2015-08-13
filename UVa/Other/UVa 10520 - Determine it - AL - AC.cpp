#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;

typedef long long int64;

int64 dp_table[21][21];
int n;

int64 dp(int i , int j)
{
	if(i < 0 || j < 0 || i > n || j > n) return 0;
	if(dp_table[i][j] != -1) return dp_table[i][j];
	if(i >= j){
		int64 first_part , second_part;
		int64 max_val;
		if(i == n){first_part = 0;}
		else{
			max_val = 0;
			for(int k = i + 1 ; k <= n ; ++k)
				max_val = max(max_val , dp(k,1) + dp(k,j));
			first_part = max_val;
		}
		if(j == 0){second_part = 0;}
		else{
			max_val = 0;
			for(int k = 1 ; k < j ; ++k){
				max_val = max(max_val , dp(i,k) + dp(n,k));
			}
			second_part = max_val;
		}
		dp_table[i][j] = first_part + second_part;
	}
	else{
		int64 max_val = 0;
		for(int k = i ; k < j ; ++k){
			max_val = max(max_val , dp(i,k) + dp(k+1,j));
		}
		dp_table[i][j] = max_val;
	}
	return dp_table[i][j];
}

void InitTable(){
	for(int i = 0 ; i <= n ; ++i){

		for(int j = 0 ; j <= n ; ++j){
			dp_table[i][j] = -1;
		}
	}
}

int main()
{
	int a;
	while(true){
		cin >> n;
		if(cin.eof()) break;
		cin >> a;
		InitTable();
		dp_table[n][1] = a;
		cout << dp(1,n) << endl;
	}
	return 0;
}