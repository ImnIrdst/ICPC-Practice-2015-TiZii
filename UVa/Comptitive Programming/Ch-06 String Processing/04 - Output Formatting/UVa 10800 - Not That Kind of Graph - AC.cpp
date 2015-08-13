#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int tc,t=1; cin >> tc; string str;
    while(tc--){
        cin >> str; int R=0,F=0, FirstF=0;
        for(int i=0,flag=1 ; i<str.length() ; i++){
            if(str[i]=='R') R++,flag=0;
            if(str[i]=='F') F++;
            if(str[i]=='F' && flag) FirstF++;
        }
        int H=abs(R+F)+1;
        char out[1000][1000]; memset(out,' ',sizeof out);
        for(int i=1 ; i<H+2 ; i++)
            out[i][0]='|';
        for(int i=1 ; i<str.length()+3 ; i++)
            out[0][i]='-';
        out[0][0]='+';
        int x=2,y=max((FirstF+1),F+1);
        for(int i=0; i<str.length() ; i++){
            if(str[i]=='R'){
                out[y][x]='/'; y++;
            }
            if(str[i]=='C'){
                out[y][x]='_';
            }
            if(str[i]=='F'){
                y--; out[y][x]='\\';
            }
            x++;
        }
        for(int i=H+1 ; i>=0 ; i--){
            bool flag=1;
            for(int j=str.length()+2 ; j>=0 ; j--){
                if(out[i][j]!=' ') flag=0;
                if(out[i][j]==' ' && flag) out[i][j]='a';
            }
            if(out[i][1]=='a') out[i][0]='a';
        }

        cout << "Case #" << t++ << ":" << endl;
        for(int i=H+1 ; i>=0 ; i--){
            for(int j=0 ; j<str.length()+3 ; j++){
                if(out[i][j]=='a') break;
                cout << out[i][j];
            }
            if(out[i][0]!='a') cout << endl;
        }
        cout << endl;
    }
}
//|             _
//|  _/\_/\    /
//| /      \__/
//+---------------
