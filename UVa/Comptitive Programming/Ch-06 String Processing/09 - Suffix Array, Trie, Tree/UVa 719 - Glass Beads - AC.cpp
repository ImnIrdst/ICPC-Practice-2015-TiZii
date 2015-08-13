#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <set>

#define MAX (2*10000+1000)
using namespace std;

int SA[MAX], tmpSA[MAX];
int RA[MAX], tmpRA[MAX];
int  cnt[MAX], n, n0, N;
char str[MAX], tmp[MAX], pat[MAX];

void CntSort(int k){
	int i, sum, maxi = max(256+10,n); //256 ASCII Characters
	memset(cnt,0,sizeof cnt);
	for(int i=0 ; i<n ; i++) cnt[(i+k<n ? RA[i+k] : 0)]++;
	for(int i=sum=0 ; i<maxi ; i++){
		int tmp=cnt[i]; cnt[i]=sum; sum+=tmp;
	}
	for(int i=0 ; i<n ; i++) tmpSA[cnt[(SA[i]+k<n ? RA[SA[i]+k] : 0)]++] = SA[i];
	for(int i=0 ; i<n ; i++) SA[i]=tmpSA[i];
}

void SA_Calc(){
	int i,k,r;
	for(int i=0 ; i<n ; i++) RA[i]=str[i]-'.';
	for(int i=0 ; i<n ; i++) SA[i]=i;
	for(int k=1 ; k<n ; k*=2){
		CntSort(k); CntSort(0);
		tmpRA[SA[0]]=r=0;
		for(int i=1 ; i<n ; i++){
			if(RA[SA[i]]==RA[SA[i-1]]
				&& RA[SA[i]+k]==RA[SA[i-1]+k]) tmpRA[SA[i]]=r;
			else tmpRA[SA[i]]=++r;
		}
		for(int i=0 ; i<n ; i++) RA[i]=tmpRA[i];
	}

}


int main(){
	int tc=0; cin >> tc; cin.ignore();
	
	while(tc--){
		memset(str,0,sizeof str); scanf("%s",str); memcpy(tmp,str,sizeof str);
		strcat(str,tmp); //cout << str << endl; 
		n=strlen(str); str[n++]='.'; 
		int MaxLen=0, MaxRep=0, MaxIdx; SA_Calc();
		for(int i=0 ; i<n ; i++){
			//cout << str+SA[i] << endl;
			if(SA[i]<n/2){
				strncpy(pat,str+SA[i],n/2); //cout << "*" << pat << endl;
				int L=0, R=n-1, mid;
				while(L<R){
					mid=(L+R)/2; //cout << str+SA[mid] << endl;
					if(strncmp(str+SA[mid],pat,n/2)>0) R=mid;
					else L=mid+1;
				}
				if(strncmp(str+SA[R],pat,n/2)!=0) R--;

				cout << SA[R]+1 << endl; break;
			}
		}

	}
}

