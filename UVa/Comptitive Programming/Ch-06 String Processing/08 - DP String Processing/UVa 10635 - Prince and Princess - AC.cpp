#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>
#define MAX (250*250+10)

using namespace std;

int a1[MAX],a2[MAX],idx[MAX],idx2[MAX],n,p,q;

int LIS(int arr[]){
	set<int> st; set<int>::iterator itr;
	for(int i=0 ; i<MAX ; i++){
		st.insert(arr[i]); 
		itr=st.find(arr[i]); itr++;
		if(itr!=st.end()){
			st.erase(itr);
		}
	}
	return st.size()-1;
}

int main(){
	int tc,t=1; cin >> tc;
	while(tc--){
		cin >> n >> p >> q; 
		for(int i=0 ; i<MAX ; i++){
			idx[i]=idx2[i]=MAX+10;
		}
		for(int i=1 ; i<=p+1 ; i++){
			cin >> a1[i]; idx[a1[i]]=i;
		}
		for(int i=1 ; i<=q+1 ; i++){
			cin >> a2[i]; idx2[i]=idx[a2[i]];
		}
		printf("Case %d: %d\n", t++, LIS(idx2));
	}
}