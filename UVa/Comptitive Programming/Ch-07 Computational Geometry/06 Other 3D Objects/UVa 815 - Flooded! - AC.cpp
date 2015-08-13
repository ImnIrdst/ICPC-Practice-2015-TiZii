#include <algorithm>
#include <iostream>
#include <cstdio>
#define MAX (30*30+10)
#define EPS (double)1e-9

using namespace std;

double h[MAX], v, percent; int n, m, i, t=1;

int main(){
	while(cin >> n >> m && (n||m)){
		n *= m; 
		for(i=0 ; i<n ; i++){
			cin >> h[i];
		}
		cin >> v;
		sort(h,h+n); double ans=0; v /= 100;
		for(i=0 ; i<n ; i++){
			//cout << "(" << v << " " ;
			if(i!=0) v *= i; v /= (i+1);
			//cout << h[i] << " " << v  << " " << h[i+1] << ") ";
			if(i==n-1 || h[i+1]+EPS>h[i]+v){
				//if(h[i+1]-h[i]-v<EPS) i--;
				ans = h[i] + v; percent = 100.*(i+1)/(double)(n); break;
			}
			v -= h[i+1]-h[i];
			//ans += (h[i+1]-h[i]+v[i])/i;
		}
		//if(i==n-1) ans = h[i] + v, percent = 100.*(i+1)/(double)(n);
		printf("Region %d\n", t++);  
        printf("Water level is %.2lf meters.\n", ans);  
        printf("%.2lf percent of the region is under water.\n\n", percent);  
	}
}