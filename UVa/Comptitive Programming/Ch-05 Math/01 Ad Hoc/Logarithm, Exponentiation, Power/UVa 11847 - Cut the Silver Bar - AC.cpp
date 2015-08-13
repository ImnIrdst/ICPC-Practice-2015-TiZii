#include <iostream>
#include <stdio.h>
#include <cmath>
#define log2(n) (log(n)/double(log(2)))

using namespace std;

int main(){
	int n;
	while(cin >> n && n){
		cout << floor(log2(n)) << endl;
	}
}
