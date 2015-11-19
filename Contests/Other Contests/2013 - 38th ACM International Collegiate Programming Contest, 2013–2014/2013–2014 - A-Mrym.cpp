#include <iostream>
#include <math.h>
#include <algorithm>
#define eps 0.000001
#define P pair< int , double>
#define price first 
#define usage second

using namespace std;

struct dev
{
	dev(int h, int w, int p){this->h=h; this->w=w; this->p=p;}
	dev(){}
	int h,w,p;
}; 

int main(){
	int h,w; 	
	dev dev1[8];
	dev1[0]=dev(1024,768,319);
	dev1[1]=dev(1024,600,419);
	dev1[2]=dev(960,640,450);
	dev1[3]=dev(2048,1536,519);
	dev1[4]=dev(1136,640,599);
	dev1[5]=dev(1280,800,600);
	dev1[6]=dev(1080,1920,630);
	dev1[7]=dev(1136,640,719);


	while(cin >> h >> w && h && w){
		P MAX=P((int)1e9,0);
		for(int i=0 ; i<8 ; i++){
			double maxratio=0;
			double mvh, mvw;

			int devh = max( dev1[i].h , dev1[i].w );
			int devw = min( dev1[i].h , dev1[i].w );
			int movh = max( h , w );
			int movw = min( h , w );

			double c = min( (double) devh/movh , (double ) devw/movw );
			int used = (int)( c*movh+1e-9 )*(int)(c*movw+1e-9 );
			double usedRatio = (double)used/(devh*devw);

			if( (fabs(usedRatio - MAX.usage ) <= 1e-9 && MAX.price > dev1[i].p) || ( usedRatio > MAX.usage ) )
				MAX = P( dev1[i].p , usedRatio );
			
		}
		cout << MAX.price << endl;
	}
}