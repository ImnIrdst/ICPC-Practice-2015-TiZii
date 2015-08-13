#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <vector>

using namespace std;

typedef vector< int > vi;
typedef vector< vi  > vii;

vi par,rnk,cnt; int n;

void SetInit(int n){
    par.assign(n,-1); rnk.assign(n,0); cnt.assign(n,1); //par==parent
}

int Find(int a){
    int i=a,j=a,tmp;
    while(par[i]!=-1){ i=par[i]; }
    while(par[j]!=-1){ tmp=par[j]; par[j]=i; j=tmp; } //path compression
    return i;
}
int Uni(int a, int b){
    int A=Find(a),B=Find(b);
    if(A!=B){
        if(rnk[A]<rnk[B]) swap(A,B); // union using rank
        if(rnk[A]==rnk[B]) rnk[A]++;
        par[B]=A;
        cnt[A]+=cnt[B]; // if we wanna count each set size
    }
    return cnt[A]; // if we wanna count each set size
}

bool AreFriends(int a, int b){
	return Find(a)==Find(b);
}

bool AreEnemies(int a, int b){
	return (Find(a) == Find(b+n) || Find(a+n)==Find(b));
}

bool SetFriends(int a, int b){
	if(AreEnemies(a,b)) return 0;
	Uni(a,b); Uni(a+n,b+n); return 1;
}

bool SetEnemies(int a, int b){
	if(AreFriends(a,b)) return 0;
	Uni(a,b+n); Uni(a+n,b); return 1;
}
int main(){
    int n, cs=1;
    while(cin >> n && n){
        int a, b, cmd; SetInit(n*2+1);
        while(cin >> cmd >> a >> b && (cmd||a||b)){
        	if(cmd == 1) if(!SetFriends(a,b))   cout << -1 << endl;
        	if(cmd == 2) if(!SetEnemies(a,b))   cout << -1 << endl;
        	if(cmd == 3) cout << (AreFriends(a,b) ? 1 : 0) << endl;
        	if(cmd == 4) cout << (AreEnemies(a,b) ? 1 : 0) << endl;
        }
    }
}