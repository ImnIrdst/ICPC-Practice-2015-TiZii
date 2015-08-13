#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define MAXN (024+10)
#define MAXX (150+10)

using namespace std;

typedef long long int int64;

int main(){
    double ncows, ncars, nshow;
    while(cin >> ncows >> ncars >> nshow){
        // (Pick a cow * pick a car from remain)
        double pick1 = (ncows/(ncows+ncars)) * (ncars/(ncows-nshow-1+ncars));
        // (Pick a car * pick a car from remain)
        double pick2 = (ncars/(ncows+ncars)) * ((ncars-1)/(ncows-nshow+ncars-1));
        printf("%.5f\n", pick1+pick2);
    }
    return 0;
}
/*


2 1 1
5 3 2
2000 2700 900

*/
