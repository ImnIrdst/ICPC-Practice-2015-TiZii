#include <stdio.h>
#include <iostream>
#include <climits>
#include <string>
#define MAX (48+2)
#define int64 unsigned long long

using namespace std;

int m,n,x,y;

int main()
{
   int tc; cin >> tc;
   while(tc--){
       cin >> m >> n >> x >> y;
       if((m-x-1)^(n-y-1)^x^y) cout << "Gretel" << endl;
       else cout << "Hansel" << endl;
   }
   return 0;
}
