#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <math.h>
#include<vector>
#include <fstream>
//#define cin fin
#define INF (int) 1e9

using namespace std;

int n, k, w[12][12][30], d[12][1010], per[12][12], sen=1;

int calc(int cit,int day){
	if(cit==n-1 && day==k) return 0;
	if(cit!=n && day==k) return INF;
	if(d[cit][day]!=-1) return d[cit][day];
	int Min=INF;
	for(int i=0 ; i<n ; i++){
		if(i!=cit){
			Min=min(Min,calc(i,day+1)+w[cit][i][day%per[cit][i]]);
		}
	}
	return d[cit][day]=Min;
}

int main(){
	//ifstream fin("in.txt");
	
	while(cin >> n >> k && n && k){
		//init
		for(int i=0 ; i<n ; i++){
			for(int j=0 ; j<n ; j++){
				if(j!=i){
					cin >> per[i][j];
					for(int k=0 ; k<per[i][j] ; k++){
						cin >> w[i][j][k];
						if(w[i][j][k]==0)
							w[i][j][k]=INF;
					}
				}
			}
		}
		//dp init
		for(int i=0 ; i<12; i++)
			for(int j=0 ; j<1010 ; j++)
				d[i][j]=-1;
		//calc
		cout << "Scenario #" << sen++ << endl;
		int ans=calc(0,0);
		if(ans!=INF)
			cout << "The best flight costs " << ans << "." << endl;
		else
			cout << "No flight possible." << endl;
		cout << endl;
	}
	return 0;
}