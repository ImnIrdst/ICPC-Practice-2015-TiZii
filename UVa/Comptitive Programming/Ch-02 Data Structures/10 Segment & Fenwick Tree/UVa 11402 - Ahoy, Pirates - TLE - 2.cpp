#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <vector>
#define INF (int)1e9
#define CLR 0
#define ONE 1
#define ZER 2
#define INV 3

using namespace std;

vector<int> st, a,laz;//st == segment tree, a == array
int arrlen;


void printtree2(){int l=1;
	for(int i=1 ; i<st.size() ; i++){
		if((i)== 1 << l) l++,cout << endl;
		cout << laz[i] << " ";
	}cout << endl;
}


int Log2(int n){ int cnt=0; while(n/=2) cnt++; return cnt; }

void buildSegT(int node, int L, int R){
	if(L>R) return;
	if(L==R){st[node]=a[L]; return;}
	buildSegT(node*2,L,(L+R)/2);
	buildSegT(node*2+1,(L+R)/2+1,R);
	st[node]=st[node*2]+st[node*2+1];
}

void initSegT(int n){
	//if n is power of 2 then arrlen=n else arrlen=first power of 2 that greater than n
	arrlen=(((n!=0) && !(n&(n-1)))? n : 1<<(Log2(n)+1)); //calc length of array
	int stlen=2*arrlen;
	st.assign(stlen,0);// length of segment tree
	laz.assign(2*stlen,CLR);
	buildSegT(1,0,arrlen-1);
}

int inv(int x){
	if(x==ONE) return ZER;
	if(x==ZER) return ONE;
	if(x==INV) return CLR;
	if(x==CLR) return INV;
}

void LazyUpdate(int node, int L, int R){
	if(laz[node]==CLR) return;
	if(laz[node]==ONE) st[node]=R-L+1;
	if(laz[node]==ZER) st[node]=0;
	if(laz[node]==INV) st[node]=(R-L+1)-st[node];
	if(L!=R){
		if(laz[node]==ONE || laz[node]==ZER)
			laz[node*2]=laz[node*2+1]=laz[node];
		else{
			laz[node*2]=inv(laz[node*2]);
			laz[node*2+1]=inv(laz[node*2+1]);
		}
	}
	laz[node]=CLR;
}

void updateSegT(int node, int L, int R, int i, int j, char state){
	if(laz[node]!=CLR) LazyUpdate(node,L,R);
	//printtree2();
	if(L>j || R<i) return;
	if(L>=i && R<=j){
		if(state=='F'){
			st[node]=R-L+1;
			laz[node*2]=laz[node*2+1]=ONE; return;
		}
		if(state=='E'){
			st[node]=0;
			laz[node*2]=laz[node*2+1]=ZER; return;
		}
		if(state=='I'){
			st[node]=(R-L+1)-st[node];
			laz[node*2]=inv(laz[node*2]);
			laz[node*2+1]=inv(laz[node*2+1]); return;
		}
	}
	//printtree2();
	updateSegT(node*2,L,(L+R)/2,i,j,state);
	updateSegT(node*2+1,(L+R)/2+1,R,i,j,state);
	st[node]=st[node*2]+st[node*2+1];
}

int Query(int node, int L, int R, int i, int j){
	if(laz[node]!=CLR) LazyUpdate(node,L,R);
	//printtree2();
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
	int tc,tcc=1,n,t,idx=0; cin >> tc; char tmp0[60];
	while(tc--){
		scanf("%d",&n); int idx=0; a.assign(1024010,0);
		for(int i=0 ; i<n ; i++){
			//cin >> t; cin >> tmp0;
			scanf("%d %s", &t, tmp0); int tmp0len=strlen(tmp0);
			while(t--){
				for(int i=0 ; i<tmp0len ; i++){
					a[idx++]=tmp0[i]-'0';
				}
			}
		}
		initSegT(idx);
		int q,qn=1; scanf("%d",&q);//cin >> q;
		printf("Case %d:\n",tcc++);
		char tmp[3];
		while(q--){
			//printtree();
			int i,j; scanf("%s %d %d",tmp,&i, &j);//cin >> state >> i >> j;
	
			if(tmp[0]=='S') printf("Q%d: %d\n",qn++,Query(1,0,arrlen-1,i,j));
			else updateSegT(1,0,arrlen-1,i,j,tmp[0]);
		}
	}
	return 0;
}
