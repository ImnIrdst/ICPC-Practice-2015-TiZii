#include <iostream>
#include <algorithm>
#define int64 long long
#define INF (int64)1e18

using namespace std;

struct pt{ int64 x, y, z; pt(){}
	pt(int64 x, int64 y, int64 z): x(x), y(y), z(z) {}
};

int n,d; 

int main(){
	while(cin >> n && n){
		pt a1, a2, b1=pt(-INF,-INF,-INF), b2=pt(INF,INF,INF);
		for(int i=0 ; i<n ; i++){
			cin >> a1.x >> a1.y >> a1.z >> d; 
			a2 = pt(a1.x+d,a1.y+d,a1.z+d);
			b1 = pt(max(a1.x,b1.x),max(a1.y,b1.y),max(a1.z,b1.z));
			b2 = pt(min(a2.x,b2.x),min(a2.y,b2.y),min(a2.z,b2.z));
		}
		cout << max(0ll,(b2.x-b1.x)*(b2.y-b1.y)*(b2.z-b1.z)) << endl;
	}
}