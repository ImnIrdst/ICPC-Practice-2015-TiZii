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
#include <set>
//#define e pair<int, int>
//#define a1 first
//#define a2 second
//#define cin fin
#define mapii map<int,int>
#define INF (int)1e9
#define MAX (int)1e6+10

using namespace std;

int lis[200005]={0}, path[200005]={0};
struct e{
	e(){}
	e(int a, int b){a1=a; a2=b;}
	bool operator==(const e& a) const {return a.a1==a1 && a.a1==a1;}
	bool operator>(const e& a) const {
		if(a.a1<a1) 
			return 1;
		else if(a.a1==a1 && a.a2>a2) 
			return 1;
		return 0;
	}
	bool operator<(const e& a) const{
		if(a.a1>a1) 
			return 1;
		else if(a.a1==a1 && a.a2<a2) 
			return 1;
		return 0;
	}
	int a1,a2;
}a[200005];

void print(int i){
	if(i==0 || i==path[i]){
		cout << a[i].a1 << endl; return;}
	print(path[i]);
	cout << a[i].a1 << endl;
}



//class cmp{
//public:
//	bool operator()(e a, e b){
//		if(a.a1==b.a1)
//			return 0;
//		if(a.a1>b.a1) 
//			return 1;
//		else if(a.a2>b.a2) 
//			return 1;
//		return 0;
//	}
//};


int main(){
	//ifstream fin("in.txt");
	int n,tmp;
	mapii mp;
	for(n=0 ; cin >> tmp ; n++){
		path[n]=n;
		a[n]=e(tmp,n);
	}
	set<e> st;
	set<e>::iterator it;
	st.clear();
	for(int i=0; i<n; i++) {
	  st.insert(a[i]); 
	  it=st.find(a[i]); 
	  if(it!=st.begin()){
		  it--;  path[i]=(it->a2); it++; }
	  it++; 
	  if(it!=st.end()){
		  st.erase(it);
	  }
	  i=i;
	}
	it=st.end(); it--;
	cout<< st.size() <<endl << "-" << endl;
	print(it->a2);
	/*for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<i ; j++){
			if(a[i]>a[j] && lis[i]<lis[j]+1){
				lis[i]=lis[j]+1;
				path[i]=j;
				i=i;
			}
		}
	}
	int Max=0;
	for(int i=0 ; i<n ; i++){
		if(lis[i]>=lis[Max]){
			Max=i;
		}
	}
	cout << lis[Max] << endl << "-" << endl;
	print(Max);*/

}
