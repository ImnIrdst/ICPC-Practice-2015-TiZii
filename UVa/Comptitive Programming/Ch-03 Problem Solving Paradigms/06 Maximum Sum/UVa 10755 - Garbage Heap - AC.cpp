#include <iostream>
#include <algorithm> 

using namespace std;

typedef long long int64;

const int Max = 20+10;

int64 p[Max][Max][Max],a , b, c;


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		cin >> a >> b >> c;
		for(int i=0 ; i<a ; i++)
			for(int j=0 ; j<b ; j++)
				for(int k=0 ; k<c ; k++){
					int64 tmp; cin >> tmp;
					if(i > 0) tmp+=p[i-1][j][k];
					if(j > 0) tmp+=p[i][j-1][k];
					if(k > 0) tmp+=p[i][j][k-1];
					if(i > 0 && j > 0) tmp-=p[i-1][j-1][k];
					if(k > 0 && j > 0) tmp-=p[i][j-1][k-1];
					if(i > 0 && k > 0) tmp-=p[i-1][j][k-1];
					if(i > 0 && j > 0 && k > 0) tmp+=p[i-1][j-1][k-1];
					p[i][j][k] = tmp;
				}
		int64 MaxSum = -1e18;
		for(int i1=0 ; i1<a ; i1++) for(int j1=0 ; j1<b ; j1++) for(int k1=0 ; k1<c ; k1++)
			for(int i2=i1 ; i2<a ; i2++) for(int j2=j1 ; j2<b ; j2++) for(int k2=k1 ; k2<c ; k2++){
				int64 Sum=p[i2][j2][k2];
				if(i1 > 0) Sum-=p[i1-1][j2][k2];
				if(j1 > 0) Sum-=p[i2][j1-1][k2];
				if(k1 > 0) Sum-=p[i2][j2][k1-1];
				if(i1 > 0 && j1 > 0) Sum+=p[i1-1][j1-1][k2];
				if(k1 > 0 && j1 > 0) Sum+=p[i2][j1-1][k1-1];
				if(i1 > 0 && k1 > 0) Sum+=p[i1-1][j2][k1-1];
				if(i1 > 0 && j1 > 0 && k1 > 0) Sum-=p[i1-1][j1-1][k1-1];
				MaxSum = max(MaxSum, Sum);
			}
		cout << MaxSum << endl; if(tc) cout << endl;
	}
}