#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    int n; string str,ans;
    while( cin >> n >> str){
        map<string,int> mp; int Max=-1;
        for(int i=0 ; i<str.length() ; i++){
            mp[str.substr(i,n)]++;
            if( mp[str.substr(i,n)] > Max){
                ans=str.substr(i,n); Max=mp[str.substr(i,n)];
            }
        }
        //cout << Max << endl;
        cout << ans << endl;
    }
}
