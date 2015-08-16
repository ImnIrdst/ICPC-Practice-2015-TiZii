#include <iostream>
#include <cstdio>
#include <sstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>

using namespace std;

struct PT{double lat, lon; PT() {}
  PT(double lat, double lon) : lat(lat), lon(lon) {}
  PT operator * (double c  ) const { return PT(lat*c, lon *c); }
}pts[1000+10];

const double eps = 1e-6;
const double PI = 3.141592653589793;
const double R = 6378.00 ; // radius of earth 

double GCDist(PT p1, PT p2) {
	   p1 = p1*(PI/180.); p2 = p2*(PI/180.);
       double dlon = p2.lon - p1.lon;
       double dlat = p2.lat - p1.lat;
       double a = pow((sin(dlat/2)),2) + cos(p1.lat) * cos(p2.lat) * pow(sin(dlon/2), 2);
       double c = 2 * atan2(sqrt(a), sqrt(1-a));
       double d = R * c;
       return d+eps;
}

int main(){
	int n;
	while(cin >> n){
		for(int i=0 ; i<n ; i++){
			cin >> pts[i].lat >> pts[i].lon;
		}

		double Min = 1e100; PT ans;
		for(int i=0 ; i<n ; i++){
			double Max = -1e100;
			for(int j=0 ; j<n ; j++){
				Max = max(Max, GCDist(pts[i], pts[j]));
			}
			if(Max-eps <= Min) Min = Max, ans = pts[i];
		}

		printf("%.2lf %.2lf\n", ans.lat, ans.lon);
	}
}