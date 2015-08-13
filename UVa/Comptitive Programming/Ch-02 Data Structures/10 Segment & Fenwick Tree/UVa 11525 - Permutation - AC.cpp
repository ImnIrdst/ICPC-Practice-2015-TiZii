#include <cstdio>
#include <vector>

using namespace std;

int main(){
	int tc; scanf("%d", &tc);
		while(tc--){
			int n; scanf("%d", &n); vector<int> perm;
			for(int i=0 ; i<n ; i++) perm.push_back(i+1);
			
			int m;
			for(int i=0 ; i<n ; i++){
				scanf("%d", &m); if(i!=0) printf(" ");
				printf("%d", perm[m]); perm.erase(perm.begin()+m);
			}printf("\n");
		}
}