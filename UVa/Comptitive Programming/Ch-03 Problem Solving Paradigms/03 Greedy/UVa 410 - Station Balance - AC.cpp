#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <math.h>
#include<vector>
#include <fstream>
#include <map>
//#define cin fin
#define x first
#define y second
#define pairii pair<int, int>
#define mappi map< pairii , int>
#define INF (int) 1e6

using namespace std;

int n, c, tc=1; pairii a[20], b[20]; mappi mp; vector<pairii> v[20];

bool cmp(pairii a, pairii b){
	if(a.x>b.x)
		return 1;
	else if(a.x==b.x && a.y<b.y)
		return 1;
	return 0;
}

bool cmp2(vector<pairii> a, vector<pairii> b){
	if(a.size() && b.size() && a[a.size()-1].y<b[b.size()-1].y)
		return 1;
	return 0;
}

int main(){
	//ifstream fin("in.txt");
	
	while(cin >> c >> n){
		int sum=0;
		for(int i=0 ; i<n ; i++){
			cin >> a[i].x; a[i].y=i;
			b[i]=a[i];
			sum+=a[i].x;
		}
		double avg=sum/(double)c;
		sort(b,b+n,cmp);
		int flag=1,i=-1,j=0;
		while(flag){
			while(j<c && flag){
				if(++i>=n){flag=0; break;}
				mp[b[i]]=j;
				j++;
			}
			j--;
			while(j>=0 && flag){
				if(++i>=n){flag=0; break;}
				mp[b[i]]=j;
				j--;
			}
			j++;
		}
		for(int i=0 ; i<n ; i++)
			v[mp[a[i]]].push_back(a[i]);
		sort(v,v+c,cmp2);
		double imb=0;
		printf("Set #%d\n", tc++);
		for(int i=0 ; i<c ; i++){
			printf("%2d:",i); double mc=0;
			for(int j=0 ; j<v[i].size() ; j++){
				printf(" %d",v[i][j].x);
				mc+=v[i][j].x;
			}
			printf("\n");
			imb+=fabs(avg-mc);
		}
		printf("IMBALANCE = %.5lf\n\n", imb);
		for(int i=0 ; i<20 ; i++)
			v[i].clear();
		mp.clear();
	}
	return 0;
}