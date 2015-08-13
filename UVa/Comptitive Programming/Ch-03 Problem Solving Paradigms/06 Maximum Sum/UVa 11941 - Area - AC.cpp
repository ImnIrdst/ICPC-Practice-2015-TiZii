#include <iostream>
#include <algorithm>

using namespace std;

const int Max = 100+10; int a[Max][Max];

int main(){
	int tc;
	int cs=1;
	cin >> tc;
	while( tc-- ){
		int n,m,cash; cin >> n >> m >> cash;
		for(int i=0 ; i<n ; i++)
			for(int j=0 ; j<m ; j++)
				cin >> a[i][j];//, a[i][j]*=-1;

		for(int i=0 ; i<n ; i++)//preprocess
			for(int j=1 ; j<m ; j++)
				a[i][j]+=a[i][j-1];

		int MaxTax=0, MaxArea=0;
		for(int l=0 ; l<m ; l++){//calc
			for(int r=l ; r<m ; r++){ 
				int sum=cash; int lastrow=-1;
				for(int row=0 ; row<n ; row++){
					if(l>0) sum -= a[row][r] - a[row][l-1];
					else    sum -= a[row][r];

					while(sum<0){
						lastrow++;
						if(l>0) sum += a[lastrow][r] - a[lastrow][l-1];
						else    sum += a[lastrow][r];
					}
					if(((row-lastrow)*(r-l+1) > MaxArea) ||
					   ((row-lastrow)*(r-l+1)== MaxArea && sum>MaxTax))
							MaxTax=sum, MaxArea=(row-lastrow)*(r-l+1);
				} 

			} 
		}
		cout << "Case #" << cs++ << ": " << MaxArea << " " << cash-MaxTax << endl;
	}
}