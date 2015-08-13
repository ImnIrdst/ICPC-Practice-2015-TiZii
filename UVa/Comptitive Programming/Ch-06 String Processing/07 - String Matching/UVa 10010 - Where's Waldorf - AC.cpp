#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#define MAX (50+10)

using namespace std;

string a[MAX], pat[MAX];

int dx[]={+1,+0,-1,+1,-1,+1,+0,-1};
int dy[]={+1,+1,+1,+0,+0,-1,-1,-1};
int n,m;

bool inRange(int x,int y){return (x>=0 && y>=0 && x<n && y<m);}

void locate(string pat){
    transform(pat.begin(),pat.end(),pat.begin(),::toupper);
    int len=pat.length(); bool found=0;
    for(int i=0 ; i<n && !found ; i++){
        for(int j=0 ; j<m && !found  ; j++){
            for(int dir=0 ; dir<8 && !found  ; dir++){
                int x=i,y=j,l=0;
                for(l=0 ; l<len && inRange(x,y) ; l++){
                    if(a[x][y]!=pat[l]) break;
                    x+=dx[dir]; y+=dy[dir];
                }
                x-=dx[dir]; y-=dy[dir];
                if(l==len){
                   cout << i+1 << " " << j+1 << endl; found=true;
                }
            }
        }
    }
}

int main(){
    int tc; cin >> tc;
    while(tc--){
        cin >> n >> m;
        for(int i=0 ; i<n ; i++){
            cin >> a[i]; transform(a[i].begin(),a[i].end(),a[i].begin(),::toupper);
        }
        int q; cin >> q;
        while(q--){
            string pat; cin >> pat;
            locate(pat);
        }
        if(tc) cout << endl;
    }
}
