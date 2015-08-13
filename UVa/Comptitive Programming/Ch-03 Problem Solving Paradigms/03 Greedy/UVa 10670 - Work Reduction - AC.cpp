#include <iostream>
#include <math.h>
#include <algorithm>
#include <fstream>
#include <functional>
#include <string>
#include <bitset>
#include <vector>
#include <sstream>
#include <set>
#define int8 long long
//#define cin fin
//#define cout fout
#define INF (int)1e9

using namespace std;

struct aj{
	string name;
	int wlin,wlog,cost;
	aj(){}
	void calc(int m, int n){
		int num=m; cost=0;
		while(num!=n){
			if((num/2>=n) && (num/2)*wlin>=wlog){
				 num/=2; cost+=wlog;}
			else{ num--; cost+=wlin;}
		}
	}
}a[110];
int m,n,l;

int cmp(aj a, aj b){
	if(a.cost<b.cost)
		return 1;
	if(a.cost==b.cost && a.name<b.name)
		return 1;
	return 0;
}

int main(){
	//ifstream fin("in.txt");
	int tc; scanf("%d",&tc); int t=1;
	while(tc--){
		cin >> m  >> n >> l;
		for(int k=0 ; k<l ; k++){
			string tmp="",name="",wlin="",wlog=""; stringstream sin;
			cin >> tmp;
			int i=0; name+=tmp[0];
			while(tmp[++i]!=':') name+=tmp[i]; a[k].name=name;
			while(tmp[++i]!=',') wlin+=tmp[i]; sin << wlin; sin >> a[k].wlin; sin.clear();
			while(tmp[++i]!='\0') wlog+=tmp[i]; sin << wlog; sin >> a[k].wlog; sin.clear();
			a[k].calc(m,n);
		}
		sort(a,a+l,cmp);
		cout << "Case " << t++ << endl;
		for(int i=0 ; i<l ; i++){
			cout << a[i].name << " " << a[i].cost << endl;
		}
	}
	return 0;
}
