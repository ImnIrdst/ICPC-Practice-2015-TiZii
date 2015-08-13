#include <iostream>
#include <math.h>
#include <algorithm>
#define eps 0.000001
using namespace std;

struct dev
{
	dev(int h, int w, int p){h=h; w=w; p=p;}
	dev(){}
	int h,w,p;
}; 


struct p
{
	p(){}
	p(int a, double b,int c){i=a; aspect=b; price=c;}
	int i, price;
	double aspect;
};

double aspect(int mvh, int mvw, int devh, int devw){
	return (mvh*mvw)/(double)(devh*devw);
}

bool cmp(p a, p b){
	double tmp=fabs(a.aspect - b.aspect);
	if(a.i==0 && b.i==3)
		a.i=a.i;
	if(a.i==3 && b.i==0)
		a.i=a.i;
	if(a.aspect - b.aspect>= eps)
		return 1;	
	else if( tmp < eps && a.price < b.price)
		return 1;
	return 0;
}

int main(){
	int h,w; cin >> h >> w;	
	p list[8];
	dev dev1[8];
	dev1[0]=dev(1024,768,319);
	dev1[1]=dev(1024,600,419);
	dev1[2]=dev(960,640,450);
	dev1[3]=dev(2048,1536,519);
	dev1[4]=dev(1136,640,599);
	dev1[5]=dev(1280,800,600);
	dev1[6]=dev(1080,1920,630);
	dev1[7]=dev(1136,640,719);


	while(h && w){
		for(int i=0 ; i<8 ; i++){
			double maxratio=0, debbug;
			double mvh, mvw,c;
			c=dev1[i].h/(double)h;
			if(aspect(floor(c*h), floor(c*w), dev1[i].h, dev1[i].w)>1)
				c=dev1[i].w/(double)w;
			if(maxratio < (debbug=aspect(floor(c*h), floor(c*w), dev1[i].h, dev1[i].w)))
				maxratio = aspect(floor(c*h), floor(c*w), dev1[i].h, dev1[i].w);
			
			c=dev1[i].w/(double)h;
			if(aspect(floor(c*h), floor(c*w), dev1[i].h, dev1[i].w)>1)
				c=dev1[i].h/(double)w;
			if(maxratio < (debbug=aspect(floor(c*h), floor(c*w), dev1[i].h, dev1[i].w)))
				maxratio = aspect(floor(c*h), floor(c*w), dev1[i].h, dev1[i].w);
			list[i]=p(i,maxratio,dev1[i].p);			
		}
		//sort(list, list+8, cmp );
		for(int i=0 ; i<8 ; i++){
			for(int j=0 ; j<8 ; j++){
				if(i==0 && j==3)
					i=i;
				if(cmp(list[i],list[j])){
					p tmp = list[i];
					list[i]=list[j];
					list[j]=tmp;
				}
			}
		}
		cout << dev1[list[0].i].p << endl;
		cin >> h >> w;	
	}
}