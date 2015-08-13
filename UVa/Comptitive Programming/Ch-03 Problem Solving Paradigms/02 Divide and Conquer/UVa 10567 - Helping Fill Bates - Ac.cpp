#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef vector<int> vi;
typedef vector<vi > vvi;

const int MaxS=1e6+10, MaxSS=1e2+10;

char S[MaxS], SS[MaxSS];

int main(){
	scanf("%s", S);
	vi::iterator it;
	vvi ids(256,vi());
	int LenS=strlen(S);
	for(int i=0 ; i<LenS ; i++){
		ids[S[i]].push_back(i);
	}

	int q; 
	scanf("%d", &q);
	while( q-- ){
		scanf("%s", SS);
		int anslo;
		int anshi;
		int Match=true;
		if(ids[SS[0]].size()){
			anslo=ids[SS[0]][0];
			anshi=ids[SS[0]][0];
			int LenSS=strlen(SS);
			for(int i=1 ; i<LenSS ; i++){
				it = lower_bound(ids[SS[i]].begin(), ids[SS[i]].end(), anshi+1);
				if( it == ids[SS[i]].end()){
					Match=false; break;
				}
				else anshi = *it;
			}
		} else Match=false;
		if(Match==0) printf("Not matched\n");
		if(Match==1) printf("Matched %d %d\n", anslo, anshi); 
	}
	return 0;
}