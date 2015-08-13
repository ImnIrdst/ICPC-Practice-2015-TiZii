#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	int h, m, s, c;
	while(scanf("%2d%2d%2d%2d",&h,&m,&s,&c)!=EOF){
		int newtime= h*60*60*100 + m*60*100 + s*100 + c;
		printf("%.7d\n", (newtime*125) / 108);
	}
}