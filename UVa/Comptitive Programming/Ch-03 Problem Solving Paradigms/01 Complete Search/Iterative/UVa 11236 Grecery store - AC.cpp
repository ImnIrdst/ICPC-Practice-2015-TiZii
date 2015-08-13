#include <cstdio>
#include <cmath>

using namespace std;

typedef long long int64;

int main(){
	int64 n=2000;
	for(int64 a=1 ; a<200 ; a+=1){
		for(int64 b=a ; a+b<=n ; b+=1){
			for(int64 c=b ; a+b+c<=n ; c+=1)
			{ 
				//a=50, b=100, c=250;//, d=16;
				int64 d=((a+b+c)*1e6)/(a*b*c-1e6); 
				if(a*b*c <= 1e6 ) continue;
				if(a+b+c+d>2000 || d<c) continue;
				if(fabs((a+b+c+d)/1e2 - (a*b*c*d)/1e8)<1e-9){
					printf("%.2lf %.2lf %.2lf %.2lf\n", 
								a/100.0, b/100.0, c/100.0 , d/100.0);
				}
			}
		}
	}
}