#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int n;
    while(cin >> n && n){
        string str; cin >> str;
        reverse(str.begin(), str.end());
        for(int i =0 ; i<(int)str.length() ; i++){
            if(str[i] == '_') str[i] = '[';
            if(str[i] == '.') str[i] = '\\';
            str[i] = (str[i] + n - 'A')%28  + 'A';
        }
        for(int i =0 ; i<(int)str.length() ; i++){
            if(str[i] == '[') str[i] = '_';
            if(str[i] == '\\') str[i] = '.';
        }
        cout << str << endl;
    }
}
