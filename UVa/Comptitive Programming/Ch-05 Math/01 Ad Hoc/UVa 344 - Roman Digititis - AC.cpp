#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int n;
	while(cin >> n && n){
		int i, v, x, l, c;
		i = v = x = l = c = 0;
		for(int j=0 ; j<=n ; j++){
			switch (j%10)
			{
				case 1: i+=1;		break;
				case 2: i+=2;		break;
				case 3: i+=3;		break;
				case 4: i+=1, v++;	break;
				case 5: v+=1;		break;
				case 6: i+=1, v++;	break;
				case 7: i+=2, v++;	break;
				case 8: i+=3, v++;	break;
				case 9: i+=1, x++;	break;
			}
			switch (j/10)
			{
				case 1: x+=1;		break;
				case 2: x+=2;		break;
				case 3: x+=3;		break;
				case 4: x+=1, l++;	break;
				case 5: l+=1;		break;
				case 6: x+=1, l++;	break;
				case 7: x+=2, l++;	break;
				case 8: x+=3, l++;	break;
				case 9: x+=1, c++;	break;
			}
		}
		printf("%d: %d i, %d v, %d x, %d l, %d c\n", n, i, v, x, l, c);
	}
}