#include <iostream>
#include <math.h>
#include <algorithm>
#include <fstream>
#include <string>
#include <map>
#define int8 long long
//#define cin fin
#define INF (int)1e9

using namespace std;

int d[2010], a[2010][2010],H, T, f;

int solve(int t, int h){
	for(int i=0 ; i<t ; i++){
		d[h]=max(d[h],a[i][h]);
	}
	for(int i=0 ; i<h ; i++){
		d[i]=0;
	}
	for(int j=h-1 ; j>=0 ; j--){
		for(int i=0 ; i<t ; i++){
			a[i][j]+=max(a[i][j+1],(j+f<=h ? d[j+f] : 0));
			d[j]=max(d[j],a[i][j]);
		}
	}
	return d[0];
}

int main(){
	//ifstream fin("in.txt");
	int tc; cin >> tc;
	while(tc--){
		scanf("%d %d %d",&T,&H, &f);
		for(int i=0 ; i<2010 ; i++){
			for(int j=0 ; j<2010 ; j++){
				a[i][j]=0;
				d[i]=0;
			}
		}
		int tmp, tmp2;
		for(int i=0 ; i<T ; i++){
			scanf("%d", &tmp);
			for(int j=0 ; j<tmp ; j++){
				scanf("%d",&tmp2);
				a[i][tmp2]++;
			}
		}
		printf("%d\n",solve(T,H));
	}
	//scanf("%d",&T);
	return 0;
}