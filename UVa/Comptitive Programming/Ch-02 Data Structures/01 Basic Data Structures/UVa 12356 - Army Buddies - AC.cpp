#include <cstdio>

using namespace std;

const int Max = 1e5+10;

int left[Max], right[Max], dead[Max];

int main(){
	int b, s;
	while(scanf("%d %d", &s, &b) && (b||s)){
		for(int i=0 ; i<=s+1 ; i++)
			left[i]=i-1, right[i]=i+1, dead[i]=false;

		left[1]=-1; right[s]=-1; 
		for(int i=0 ; i<b ; i++){
			int l, r; scanf("%d %d", &l, &r);
			left[right[r]] = left[l];
			if(left[l]!=-1) printf("%d ", left[l]);
			if(left[l]==-1) printf("* ");

			right[left[l]] = right[r];
			if(right[r]!=-1) printf("%d\n", right[r]);
			if(right[r]==-1) printf("*\n");
		}
		printf("-\n");
	}
}