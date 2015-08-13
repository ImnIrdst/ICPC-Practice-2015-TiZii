#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <sstream>
#include <map>
#define int64 long long int

using namespace std;

string sq; int n;

int f(int n){
    stringstream sstr; sstr << n*n;  sstr >> sq;
    for(int i=sq.length() ; i<8 ; i++ ){
        sq = "0" + sq;
    }
    sstr.clear(); sstr << sq.substr(2,4); sstr >> n;
    return n;
}


int main(){
    int num;
    while(cin >> num && num){
        map<int,int> mp;
        int x = num; int i=0;
        while(true){
            mp[x] = i++; x = f(x);
            if(mp.count(x)>0) break;
        }
        cout << i << endl;
    }
    return 0;
}

