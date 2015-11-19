#include <iostream>
#include <algorithm>

#define MAX 8000

using namespace std;

int main(){
	int tc; cin >> tc;
	while(tc--){
		int d[MAX],Max[MAX],a[MAX],n; cin >> n;
		for(int i=0 ; i<n ; i++) cin >> a[i];
		for(int i=0 ; i<n ; i++){
			int max1=a[i],point1=a[i],Min=a[i];
			for(int j=i-1 ; j>=0 ; j--)
				point1+=Min=min(Min,a[j]);

			int max2, point2=0;
			if(i==0){ Max[i]=a[i]; d[i]=a[i]; continue; }
			
			point2=d[i-1]+(a[i]>Max[i-1] ? a[i] : 0);
			max2=(a[i]>Max[i-1] ? a[i] : Max[i-1]);

			int point3=0,max3;
			for(int j=0 ; j<n ; j++){
				if(a[i]>=Max[j] && point3<=a[i]+d[j]){
					point3=a[i]+d[j];
					max3=a[i];
				}
			}

			if(point1>point2){point2=point1; max2=max1;}
			if(point3>point2){point2=point3; max2=max3;}
			
			d[i]=point2; Max[i]=max2;
		}
		cout << d[n-1] << endl;
	}
}


#include <iostream>
#include <algorithm>

#define MAX 8000

using namespace std;

int main(){
	int tc; cin >> tc;
	while(tc--){
		int d[MAX],Max[MAX],a[MAX],n; cin >> n;
		for(int i=0 ; i<n ; i++) cin >> a[i];
		for(int i=0 ; i<n ; i++){
			int max1=a[i],point1=a[i],Min=a[i];
			for(int j=i-1 ; j>=0 ; j--)
				point1+=Min=min(Min,a[j]);

			int max2, point2;
			if(i==0){ Max[i]=a[i]; d[i]=a[i]; continue; }
			point2=d[i-1]+(a[i]>Max[i-1] ? a[i] : 0);
			max2=(a[i]>Max[i-1] ? a[i] : Max[i-1]);
			if(point1>point2){point2=point1; max2=max1;}
			d[i]=point2; Max[i]=max2;
		}
		cout << d[n-1] << endl;
	}
}