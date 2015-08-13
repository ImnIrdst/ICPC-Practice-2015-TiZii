#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <map>
#include <vector>
#define INF (int)1e9

using namespace std;

map<int,int> cnt,beg;// cnt = count frequncies, beg = begin of each frequency
vector<int> st,a,tmpArr;//st = segment tree, a = orginal array;
int len;

int Log2(int n){int cnt=0; while(n/=2) cnt++; return cnt;}

void initSegT(int n){
	//if n is power of 2 then arrlen=n else arrlen=first power of 2 that greater than n
	int arrlen=(((n!=0) && !(n&(n-1)))? n : 1<<(Log2(n)+1)); //calc length of array
	int stlen=2*arrlen; 
	a.clear(); tmpArr.clear();
	a.assign(arrlen,0); tmpArr.assign(arrlen,0);
	st.assign(stlen,0);// lenght of segment tree
}

void updateSegT(int node,int idx){
	if(node==0) return;
	st[node]=(cnt[a[idx]]>st[node]) ? st[node]=cnt[a[idx]] : st[node];
	updateSegT(node/2,idx);
}

void updateArr(int idx, int val){
	a[idx]=val; // update doesnt needed, we use this to build the tree
	// if realy we want to update, we must do some other work here
	updateSegT(st.size()/2+idx,idx); 
}

int Query(int node, int L, int R, int i , int j){
	if(i>R || L>j) return -1;
	if(i<=L && R<=j) return st[node];
	int p1=Query(2*node,L,(L+R)/2,i,j);
	int p2=Query(2*node+1,(L+R)/2+1,R,i,j);
	if(p1==-1) return p2; if(p2==-1) return p1;
	return max(p1,p2);
}

void printtree(){
	int l=1;
	for(int i=1 ; i<st.size() ; i++){
		if((i)== 1 << l) l++,cout << endl;
		cout << st[i] << " ";
	}
}

int main(){
	int n,q,tmp;
	while(cin >> n && n){
		st.clear(); cnt.clear(); beg.clear(); 
		cin >> q;  initSegT(n);
		for(int i=0 ; i<n ; i++){
			cin >> tmpArr[i];
			cnt[tmpArr[i]]++;
			if(cnt[tmpArr[i]]==1) beg[tmpArr[i]]=i;
		}
		for(int i=0 ; i<n ; i++){
			updateArr(i,tmpArr[i]);
		}
		int i,j;
		//printtree(); cout << endl; // for debug
		while(q--){
			cin >> i >> j; 
			i--; j--;
			if(a[i]==a[j]) cout << j-i+1 << endl;
			else{
				int begK=cnt[a[i]]+beg[a[i]];
				int endK=beg[a[j]]-1;
				int ans1=begK-i; int ans2=j-endK;
				int ans3=Query(1,0,a.size()-1,begK,endK);
				cout << max(ans1,max(ans2,ans3)) << endl;
			}
		}
	}
	return 0;
}