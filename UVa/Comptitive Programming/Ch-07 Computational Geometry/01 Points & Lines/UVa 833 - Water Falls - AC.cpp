#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int inRange(int x, int b1 , int b2){
	return (b1 <= x && x <= b2) || (b2 <= x && x <= b1);
}

struct pt{ int x, y; };

struct seg{ pt a, b; };

int main(){
	int tc; cin >> tc;
	while( tc-- ){
		int n; cin >> n;
		vector<seg> vseg(n);
		for(int i=0 ; i<n ; i++){
			cin >> vseg[i].a.x >> vseg[i].a.y;
			cin >> vseg[i].b.x >> vseg[i].b.y;
		}
		int q; cin >> q;
		while( q-- ){
			pt p; cin >> p.x >> p.y;
			while( true ){
				int j=-1;
				double Max = -1, y;
				for(int i=0 ; i<n ; i++){
					if(inRange(p.x, vseg[i].a.x, vseg[i].b.x)){
						y = vseg[i].b.y + (double)(vseg[i].a.y-vseg[i].b.y)*(p.x-vseg[i].b.x)/(vseg[i].a.x-vseg[i].b.x);
						if( y < p.y && y > Max){
							Max = y, j = i;
						}
					}
				}
				if(j == -1) break;
				if((double)(vseg[j].a.y-vseg[j].b.y)/(vseg[j].a.x - vseg[j].b.x) < 0)
					p.x = max(vseg[j].a.x, vseg[j].b.x);			
				else 
					p.x = min(vseg[j].a.x, vseg[j].b.x);	
				p.y = min(vseg[j].a.y, vseg[j].b.y);
			}
			cout << p.x << endl;
		}
		if(tc) cout << endl ;
	}
}
