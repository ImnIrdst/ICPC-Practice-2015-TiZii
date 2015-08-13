#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>

using namespace std;

const int MAX = 32 + 10;

struct pt{int x, y;}; struct rect{pt TL, BR;};// top left, bottom right

bool p[MAX][MAX];

void paint(rect R){
	for(int i=R.BR.y ; i<R.TL.y ; i++){
		for(int j=R.TL.x ; j<R.BR.x ; j++){
			p[i][j]=1;
		}
	}
//	for(int i=0 ; i<32 ; i++){
//		for(int j=0 ; j<32 ; j++){
//			cout << p[i][j] << " " ;
//		}
//		cout << endl;
//	}cout << endl;
}

string str;

void trave(rect R){
	rect R2; str.erase(str.begin());
	//top left child
	R2.TL.x = (R.TL.x+R.BR.x)/2;	R2.TL.y = (R.TL.y);
	R2.BR.x = (R.BR.x);				R2.BR.y = (R.TL.y+R.BR.y)/2;
	if(str[0]=='p') trave(R2) ;
	else if(str[0]=='f') str.erase(str.begin()), paint(R2) ;
	else if(str[0]=='e') str.erase(str.begin());

	//top right child
	R2.TL.x = (R.TL.x);				R2.TL.y = (R.TL.y);
	R2.BR.x = (R.TL.x+R.BR.x)/2;	R2.BR.y = (R.TL.y+R.BR.y)/2;
	if(str[0]=='p') trave(R2) ;
	else if(str[0]=='f') str.erase(str.begin()), paint(R2) ;
	else if(str[0]=='e') str.erase(str.begin());
	//bottom right child

	R2.TL.x = (R.TL.x);				R2.TL.y = (R.TL.y+R.BR.y)/2;
	R2.BR.x = (R.TL.x+R.BR.x)/2;	R2.BR.y = (R.BR.y);
	if(str[0]=='p') trave(R2) ;
	else if(str[0]=='f') str.erase(str.begin()), paint(R2) ;
	else if(str[0]=='e') str.erase(str.begin());
	
	//bottom left child
	R2.TL.x = (R.TL.x+R.BR.x)/2;	R2.TL.y = (R.TL.y+R.BR.y)/2;
	R2.BR.x = (R.BR.x);				R2.BR.y = (R.BR.y);
	if(str[0]=='p') trave(R2) ;
	else if(str[0]=='f') str.erase(str.begin()), paint(R2) ;
	else if(str[0]=='e') str.erase(str.begin());
}

int main(){
	int tc; cin >> tc;
	while(tc--){
		cin >> str; memset(p,0,sizeof p);
		rect R; R.TL.x=0; R.TL.y=32; R.BR.x=32; R.BR.y=0; 
		if(str[0]=='p') trave(R) ;
		if(str[0]=='f') str.erase(str.begin()), paint(R) ;
		if(str[0]=='e') str.erase(str.begin());

		cin >> str;
		if(str[0]=='p') trave(R) ;
		if(str[0]=='f') str.erase(str.begin()), paint(R) ;
		if(str[0]=='e') str.erase(str.begin());

		int ans=0;
		for(int i=0 ; i<32 ; i++){
			for(int j=0 ; j<32 ; j++){
				ans += p[i][j];
			}
		}
		printf ("There are %d black pixels.\n", ans);
	}
}