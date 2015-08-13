#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

bool check(string str){
    int i=0,j=0,cnt[3]={0};
    while(i<str.length()){
        if(str[i]=='?') cnt[j]++;
        else{
            if(j==0 && str[i] != 'M') return false;
            if(j==1 && str[i] != 'E') return false;
            if(j==2) return false;
            j++;
        }
        i++;
    }
    if(!cnt[1] || !cnt[0]) return false;
    return (cnt[2] - cnt[0] == cnt[1]);
}

int main(){
    int tc; cin >> tc;
    while(tc--){
        string str; cin >> str;
        if(check(str)) cout << ("theorem") << endl;
        else        cout << ("no-theorem") << endl;
    }
}
