#include <iostream>
#include <cstdio>
#include <sstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <map>
#define MAX (100+10)
#define int64 long long
using namespace std;

struct PT{double lat, lon; PT() {}
  PT(double lat, double lon) : lat(lat), lon(lon) {}
  PT operator * (double c  ) const { return PT(lat*c, lon *c); }
};

struct PTSP{double x, y, z; PTSP() {}
  PTSP(double x, double y, double z) : x(x), y(y), z(z) {}
};

const double EPS = 1e-9;
const double INF = 1e100;
const double PI = 3.141592653589793;
const double R = 6371009.00 ; // radius of earth 

double Angle3D(PT p1, PT p2) {
	p1 = p1*(PI/180.); p2 = p2*(PI/180.);
	double dlat = p2.lat - p1.lat;
	double dlon = p2.lon - p1.lon;
	double a = pow((sin(dlat/2.)),2.) + cos(p1.lat) * cos(p2.lat) * pow(sin(dlon/2.), 2.);
	return 2. * atan2(sqrt(a), sqrt(1-a));
}

int main(){
	int64 tc; cin >> tc;
	while(tc--){
		PT p1, p2;
		cin >> p1.lat >> p1.lon >> p2.lat >> p2.lon;
		double GCDist = Angle3D(p1,p2)*R;
		double SPDist = sqrt(2.*R*R *(1-cos(Angle3D(p1,p2))));
		cout << (int64)(round(GCDist-SPDist+EPS)+0.5) << endl;
	}
}