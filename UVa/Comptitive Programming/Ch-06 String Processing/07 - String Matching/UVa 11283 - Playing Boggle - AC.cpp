#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <set>
#define MAX (4+1)
#define pii pair<int,int>
using namespace std;

char a[MAX][MAX], pat[MAX*MAX];// string pat;

int dx[]={+1,+0,-1,+1,-1,+1,+0,-1};
int dy[]={+1,+1,+1,+0,+0,-1,-1,-1};
int n=4,m=4,ans,found;
int point[17]={0,0,0,1,1,2,3,5,11,11,11,11,11,11,11,11,11};

bool inRange(int x,int y){return (x>=0 && y>=0 && x<n && y<m);}

void backtrack(set<pii> vis, int x, int y){
    
    if(found || !inRange(x,y)) return;
    if(vis.size()==strlen(pat)){
        ans+=point[strlen(pat)];
        found=1; return;
    }
    if(a[x][y]!=pat[vis.size()]) return;
    if(vis.count(pii(x,y))) return; 
    vis.insert(pii(x,y));
    //cout << x << " " << y << endl;
    for(int dir=0 ; dir<8 ; dir++){
        backtrack(vis,x+dx[dir],y+dy[dir]);
    }

}

int main(){
    int tc,t=1; cin >> tc;
    
    while(tc--){
        ans=0;
        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                cin >> a[i][j];
            }
        }
        int q; cin >> q;
        while(q--){
            cin >> pat; found=false; 
            for(int i=0 ; i<n && !found ; i++){
                for(int j=0 ; j<m && !found ; j++){
                    //cout << "*****" << endl;
                    backtrack(set<pii>(),i,j);
                }
            }
        }
        printf("Score for Boggle game #%d: %d\n", t++, ans);
    }
}
