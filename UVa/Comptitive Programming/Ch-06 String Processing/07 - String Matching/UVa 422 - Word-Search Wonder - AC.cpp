#include <iostream>
#include <cstring>
#include <cstdio>
#define MAX (100+10)

using namespace std;

char a[MAX][MAX], pat[MAX];

int dx[]={+1,+0,-1,+1,+1,+0,-1};
int dy[]={+1,+1,+1,+0,-1,-1,-1};

int main(){
    int n; cin >> n;
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
    }
    while(cin >> pat && pat[0]!='0'){
        int len=strlen(pat); bool found=0;
        for(int i=0 ; i<n && !found ; i++){
            for(int j=0 ; j<n && !found  ; j++){
                for(int dir=0 ; dir<7 && !found  ; dir++){
                    int x=i,y=j,l=0;
                    for(l=0 ; l<len ; l++){
                        if(a[x][y]!=pat[l]) break;
                        x+=dx[dir]; y+=dy[dir];
                    }
                    x-=dx[dir]; y-=dy[dir];
                    if(l==len){
                        printf("%d,%d %d,%d\n",i+1,j+1,x+1,y+1);found=true;
                    }
                }
            }
        }
        if(!found) printf("Not found\n");
    }
}
