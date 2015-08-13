#include <algorithm>
#include <iostream>

using namespace std;

int a[10000+10];

//function: Binary Search : return index of i;
int bs(int lo, int hi, int key){
	int mid;
	while(lo<hi){
		//cout << a[lo] << "," << a[hi] << endl;
		mid = (lo+hi)/2;
		if(a[mid]  < key) lo=mid+1;
		if(a[mid] >= key) hi=mid;
	}
	if(a[hi]==key) return hi+1; return -1;
}

//Main function
int main(){
	//get input (n, q) terminate with 0 0
	int n, q, cs=1;//cs = case number
	while(cin >> n >> q && (n||q)){
		//get n number
		for(int i=0 ; i<n ; i++) cin >> a[i];
		sort(a,a+n);//sort numbers
		//get and process q queries and output
		cout << "CASE# "<< cs++ << ":" << endl;
		while(q--){
			int num; cin >> num;
			int idx = bs(0,n-1,num);//bsearch
			if(idx==-1) cout << num << " not found" << endl;
			if(idx!=-1) cout << num << " found at " << idx << endl;
		}		
	}
}
