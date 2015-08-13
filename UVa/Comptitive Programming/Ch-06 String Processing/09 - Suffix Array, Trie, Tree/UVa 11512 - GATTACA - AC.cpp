#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <set>

#define MAX (100000+1000)
using namespace std;

int SA[MAX], tmpSA[MAX];
int RA[MAX], tmpRA[MAX];
int  sep[MAX], par[MAX];//sep->seperator, par->parent string
int  cnt[MAX], n, n0, N;
char str[MAX];

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

int Phi[MAX], PLCP[MAX], LCP[MAX];

void LCP_Calc(){
	int i, L; Phi[SA[0]]=-1;
	for(int i=1 ; i<n ; i++) Phi[SA[i]]=SA[i-1];
	for(int i=L=0 ; i<n ; i++){
		if(Phi[i]==-1){ PLCP[i]=0; continue; }
		while(str[i+L]==str[Phi[i]+L] && L<n && str[i+L]!='\0' && str[Phi[i]+L]!='\0')
            L++;
        //cout << str+i << " " << L << endl;
		PLCP[i]=min(L,(int)strlen(str+Phi[i])); L=max(PLCP[i]-1,0);
	}
	for(int i=0 ; i<n ; i++) LCP[i] = PLCP[SA[i]];
}
char pat[MAX]; 
int count(int idx,int m){
	memset(pat,0,sizeof pat);
	for(int i=0 ; i<m ; i++) pat[i]=str[SA[idx]+i]; pat[m]='\0';
	int L=0, R=n-1, mid;
	while(L<R){
		mid=(L+R)/2;
		if(strncmp(str+SA[mid],pat,m)>=0) R=mid;
		else L=mid+1;
	}
	if(strncmp(str+SA[L],pat,m)!=0) return 0;
	int first=L;

	L=0, R=n-1;
	while(L<R){
		mid=(L+R)/2;
		if(strncmp(str+SA[mid],pat,m)>0) R=mid;
		else L=mid+1;
	}
	if(strncmp(str+SA[R],pat,m)!=0) R--;
	int second=R;
	//cout << LCP[idx] << " " << str+SA[idx] << " " <<  pat << " " << second-first+1 << endl;
	return second-first+1;
}

int main(){
	int tc=0; cin >> tc; cin.ignore();
	
	while(tc--){
		memset(str,0,sizeof str); gets(str); n=strlen(str); str[n++]='.'; 
		int MaxLen=0, MaxRep=0, MaxIdx; SA_Calc(); LCP_Calc(); //st.clear();
		for(int i=0 ; i<n ; i++){
			
			int Reps=count(i,LCP[i]); 
			//cout << LCP[i] << " " << MaxLen << " " << Reps << " " << MaxRep << endl; 
			if(LCP[i]>MaxLen){
				MaxLen=LCP[i]; MaxRep=Reps;//count(i,LCP[i]); 
				MaxIdx=i;
			}
		}

		if(MaxLen==0) cout << "No repetitions found!" << endl;
		else{ 
			for(int j=0 ; j<MaxLen ; j++)
				cout << str[SA[MaxIdx]+j];
			cout << " " << MaxRep << endl;
		}
	}
}

