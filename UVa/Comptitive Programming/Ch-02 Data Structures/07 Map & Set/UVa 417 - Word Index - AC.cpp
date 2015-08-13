#include <iostream>
#include <string>
#include <queue>
#include <map>

using namespace std;

map<string, int> mp;

void init(){
    int n=0; string top=""; bool found=0;
    queue<string> q; q.push(top);
    while(!q.empty() && n<=83681){
        top = q.front(); q.pop(); mp[top]=n++; 
        char c2 = top.length()==0 ? 'a'-1 : top[top.length()-1];
        for(char c=c2+1 ; c<='z' && !found ; c++){
            q.push(top+c); if(top+c == "vwxyz") found=1;
        }
    }
}

int main(){
    string str; init();
    while(cin >> str){
        if(mp.count(str)) cout << mp[str] << endl;
        else cout << 0 << endl;
    }
}