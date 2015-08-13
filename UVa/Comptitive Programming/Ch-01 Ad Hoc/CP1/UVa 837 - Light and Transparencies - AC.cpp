#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <sstream>

using namespace std;

struct pt{
    int x; bool endl; double c;
    bool operator < (const pt p) const {return x < p.x;}
};

int toInt(string str){
    stringstream sstr(str);
    int ret; sstr >> ret;
    return ret;
}

const int MAX = 1e4;

int n; pt p[MAX];

int main(){
    int tc; cin >> tc;
    while(tc--){
        cin >> n; string tmp;
        for(int i=0 ; i<n ; i++){
            double x1, x2, c;
            cin >> x1; cin.ignore();
            cin >> x2 >> x2;    
        }
    }
}