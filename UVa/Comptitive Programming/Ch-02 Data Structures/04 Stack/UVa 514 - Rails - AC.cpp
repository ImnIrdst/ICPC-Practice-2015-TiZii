#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <fstream>
#include <string>
#include <string.h>
#include <map>
#include <sstream>
#include <stack>
//#define cin fin
#define MAX (int)1e8

using namespace std;

int a[1010];

int main(){
	//ifstream fin("in.txt");
	int n; int flag=0;
	while(cin >> n && n!=0){		
		do{
			stack<int> s;
			for(int i=0 ; i<n ; i++){
				cin >> a[i];
				if(a[0]==0)
					break;
			}
			if(a[0]==0)
				break;
			int cnt=1;
			for(int i=0 ; i<n ; i++){
				if(!s.empty() && a[i]==s.top())
					s.pop();
				else{
					for(; cnt<=n && cnt!=a[i] ; cnt++)
						s.push(cnt);
					cnt++;
				}
			}
			cout << (s.empty() ? "Yes" : "No") << endl;

		}while(a[0]!=0);
		cout << endl;
	}
}