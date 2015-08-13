#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

double toDouble(string s){
    stringstream sstr(s);
    double ret; sstr >> ret;
    return ret;
}

int main(){
    int h,m,s; double km=-1,speed; char c; string tmp; int ph, pm, ps;
    while(cin >> h >> c >> m >> c >> s){ getline(cin, tmp);
        if(tmp!=""){
            if(km==-1)  km=0;
            else        km+=speed*((h-ph)*3600+(m-pm)*60+(s-ps));
            speed = toDouble(tmp)/3600; 

        }
        if(tmp==""){
            if(km==-1) km=0;
            km+=speed*((h-ph)*3600+(m-pm)*60+(s-ps));
            printf("%.2d:%.2d:%.2d %.2lf km\n",h,m,s,fabs(km));
        }
        ph=h, pm=m, ps=s;
    }
}