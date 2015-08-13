#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <vector>
#define INF (int)1e9

using namespace std;

vector<int> st, a;//st == segment tree, a == array

int Log2(int n){ int cnt=0; while(n/=2) cnt++; return cnt; }

void initSegT(int n){
	//if n is power of 2 then arrlen=n else arrlen=first power of 2 that greater than n
	int arrlen=(((n!=0) && !(n&(n-1)))? n : 1<<(Log2(n)+1)); //calc length of array
	int stlen=2*arrlen; 
	a.clear(); 
	a.assign(arrlen,0);
	st.assign(stlen,0);// length of segment tree
}

void updateSegT(int node, int diff){
	if(node==0) return; 
	st[node]=st[node]-diff;	
	updateSegT(node/2,diff);
}

void updateArr(int idx, int val){
	if(a[idx]==val) return;
	int diff=a[idx]-val;
	a[idx]=val; 
	updateSegT(st.size()/2+idx,diff);
//int diff=a[idx]-val; 	a[idx]=val;	updateSegT(st.size()/2+idx,diff);
}

int Query(int node, int L, int R, int i, int j){
	if(i>R || L>j) return 0; //return 0; // for range sum query
	if(i<=L && R<=j) return st[node];
	return Query(2*node,L,(L+R)/2,i,j)+Query(2*node+1,(L+R)/2+1,R,i,j);
}
void printtree(){int l=1;
	for(int i=1 ; i<st.size() ; i++){
		if((i)== 1 << l) l++,cout << endl;
		cout << st[i] << " ";
	}cout << endl;
}

int main(){
	int tc,tcc=1,n,t; cin >> tc; char tmp0[60];
	while(tc--){
		string str="";//,tmp;
		scanf("%d",&n); int idx=0;
		for(int i=0 ; i<n ; i++){
			//cin >> t; cin >> tmp;
			scanf("%d %s", &t, tmp0);
			while(t--){
				str.append(tmp0);
			}
		}
		initSegT(str.size());
		for(int i=0 ; i<str.size() ; i++){
			updateArr(i,str[i]-'0');
		}
		int q,qn=1; scanf("%d",&q);//cin >> q;
		printf("Case %d:\n",tcc++);
		string state; char tmp[3];
		while(q--){
			//printtree();
			 int i,j; scanf("%s %d %d",tmp,&i, &j);//cin >> state >> i >> j;
			state=tmp;
			if(state=="F") for(int k=i ; k<=j ; k++) updateArr(k,1);
			if(state=="E") for(int k=i ; k<=j ; k++) updateArr(k,0);
			if(state=="I") 
				for(int k=i ; k<=j ; k++) updateArr(k,1-a[k]);
			if(state=="S") printf("Q%d: %d\n",qn++,Query(1,0,a.size()-1,i,j));
		}
	}
	return 0;
}
