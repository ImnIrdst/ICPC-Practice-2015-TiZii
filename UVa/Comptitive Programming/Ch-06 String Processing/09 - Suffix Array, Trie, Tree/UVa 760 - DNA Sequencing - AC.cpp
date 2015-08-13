#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <set>

#define MAX (600+10)
using namespace std;

int SA[MAX], tmpSA[MAX];
int RA[MAX], tmpRA[MAX];
int  cnt[MAX], n, n0;
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
		while(str[i+L]==str[Phi[i]+L]) L++;
		PLCP[i]=L; L=max(L-1,0);
	}
	for(int i=0 ; i<n ; i++) LCP[i] = PLCP[SA[i]];
}

set<string> st;

bool check(int idx,int Max){//if Consecutive idxes Blongs to two difrent Strings
	string s="";
	for(int j=0 ; j<Max ; j++) s+=str[SA[idx]+j]; 
	if(st.count(s)) return 0;
	return (n0-SA[idx])*(n0-SA[idx-1])<0;
}

int main(){
	bool first=true; string tmpstr;
	while(gets(str)){
		n0=strlen(str); str[n0]='.'; 
		gets(str+n0+1); n=strlen(str);
		

		int Max=0; SA_Calc(); LCP_Calc(); st.clear();
		for(int i=0 ; i<n ; i++) if(check(i,1)) Max=max(Max,LCP[i]);

		if(!first) cout << endl; first=false;
		if(Max==0) cout << "No common sequence." << endl;
		else for(int i=0 ; i<n ; i++){
			//cout << LCP[i] << " " << str+SA[i]  << " " << Max<< endl;
			if(LCP[i]==Max && check(i,Max)){ 
				tmpstr="";
				for(int j=0 ; j<Max ; j++) 
					cout << str[SA[i]+j],tmpstr+=str[SA[i]+j]; 
				cout << endl; st.insert(tmpstr);
				//cout << st.count(string(str+SA[i])) << endl;
			}
		}
		gets(str);
	}
}

