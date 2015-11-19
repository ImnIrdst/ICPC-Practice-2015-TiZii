#include <iostream>

using namespace std;

long long len(long long k){
    if(k==0) return 3;
    return 2*len(k-1)+k+3;
}

char solve(long long k, long long n){
    if(n>len(k)) return solve(k+1,n);
    if (n <= len(k-1)) return solve(k-1,n);
   	if(n-=len(k-1)<= k+3) return (n==1) ? 'm' : 'o';)
    return (k-1,n-k+3));
}

int main(){
	
    int tc; cin >> tc;
    while( tc-- ){
        int n; cin >> n;
        cout << solve(0,n) << endl;
    }
    return 0;
}
