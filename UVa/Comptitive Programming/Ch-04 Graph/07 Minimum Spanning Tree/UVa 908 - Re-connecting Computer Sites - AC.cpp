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
#include <queue>
//#define cin fin
#define mapsi map<string,int>
#define INF (int)1e9
#define MAX (int)1e6+10

using namespace std;

int set[MAX];
int parent(int i){return (i==set[i] ? i : parent(set[i]) );}
void uni(int i, int j){set[parent(i)]=parent(j);}

struct e{
	e(){}
	e(int x, int y, int z){a=x; b=y; c=z;}
	int a,b,c;
};

class cmp{
public:
	bool operator()(e& a, e& b){
		return a.c>b.c;
	}
};

int main(){
	//ifstream fin("in.txt");
	int n; int cnt=0;
	while(cin >> n){
		if(cnt++) cout << endl;
		int a1,a2,a3; int ans1=0, ans2=0;
		for(int i=0 ; i<n-1 ; i++){
			cin >> a1 >> a2 >> a3;
			ans1+=a3;
		}
		for(int i=0 ; i<MAX ; i++) set[i]=i;
		priority_queue<e,vector<e>,cmp> pq;
		cin >> n;
		for(int i=0 ; i< n ; i++){
			cin >> a1 >> a2 >> a3;
			pq.push(e(a1,a2,a3));
		}
		cin >> n;
		for(int i=0 ; i< n ; i++){
			cin >> a1 >> a2 >> a3;
			pq.push(e(a1,a2,a3));
		}
		while(!pq.empty()){
			e tmp=pq.top(); pq.pop();
			if(parent(tmp.a)!=parent(tmp.b)){
				ans2+=tmp.c;
				uni(tmp.a,tmp.b);
			}
		}
		cout << ans1 << endl << ans2 << endl;
	}
}
