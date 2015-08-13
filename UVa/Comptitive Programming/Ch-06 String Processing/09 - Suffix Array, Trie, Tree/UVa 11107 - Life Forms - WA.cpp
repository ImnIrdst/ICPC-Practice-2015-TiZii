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
		while(str[i+L]==str[Phi[i]+L] && L<n)
            L++;
		PLCP[i]=L; L=max(L-1,0);
	}
	for(int i=0 ; i<n ; i++) LCP[i] = PLCP[SA[i]];
}

set<string> st;

bool check(int idx,int Max){//if Consecutive idxes Blongs to two difrent Strings
	string s="";
	for(int j=0 ; j<Max ; j++) s+=str[SA[idx]+j];
	if(st.count(s)) return 0;

	set<int> st2;
	for(int i=idx, cnt=0 ; i>=0 ; i--){
		if(!st2.count(par[SA[i]]) && LCP[i]==LCP[idx] && (str+SA[idx])[0]==(str+SA[i])[0]){
			cnt++; st2.insert(par[SA[i]]);
			if(cnt>N/2) return 1;
		}
	}
	return 0;
}

int main(){
	int ii=0; bool first=true; string tmpstr;

	while(cin >> N && N){
		int n0=-1; gets(str);
		memset(str,0,sizeof str);
		for(int k=0 ; k<N ; k++){
			gets(str+n0+1);
			for(int i=n0+1 ; i<strlen(str) ; i++) par[i]=k;
			n0=strlen(str); str[n0]='.';
		}
		n=strlen(str);
		int Max=0; SA_Calc(); LCP_Calc(); st.clear();
		for(int i=0 ; i<n ; i++){
			//cout << LCP[i] << " " << str+SA[i]  << " " << Max<< endl;
			if(check(i,1)) Max=max(Max,LCP[i]);
		}

		if(!first) cout << endl; first=false;
		if(Max==0) cout << "?" << endl;
		else for(int i=0 ; i<n ; i++){
			//
			if(LCP[i]==Max && check(i,Max)){
				tmpstr="";
				for(int j=0 ; j<Max ; j++)
					cout << str[SA[i]+j],tmpstr+=str[SA[i]+j];
				cout << endl; st.insert(tmpstr);
			}
		}
	}
}

