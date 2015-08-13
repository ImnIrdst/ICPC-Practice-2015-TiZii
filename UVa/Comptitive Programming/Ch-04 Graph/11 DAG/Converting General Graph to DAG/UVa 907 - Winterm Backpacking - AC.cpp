#include <iostream>

using namespace std;

typedef long long int64;

int dist[600+10], n, k;//, sum[600+10];

int CanGo(int d){
	int tk=k, td=d, i;
	for(i=1 ; i<n+2 && tk>=0 ;){
		if(dist[i]>td) tk--, td=d;
		else td-=dist[i], i++;
	}
	return tk>0 || (tk==0 && i==n+2);
}

int main(){
	while(cin >> n >> k){
		int sum=0;
		for(int i=1 ; i<n+2 ; i++){
			cin >> dist[i]; sum+=dist[i];
		}

		int lo=0, hi=sum;//, mid;
		while(lo<hi){
			int mid = (lo+hi)/2;
			if(CanGo(mid)) hi=mid; else lo=mid+1;
		}
		cout << hi << endl;
	}
}