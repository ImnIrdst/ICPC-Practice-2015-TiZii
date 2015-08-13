#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const int MAX = 20 + 10;

int absVal(string& str){
    int ret = 1e9;
    for(int i=0 ; i<str.length()-1 ; i++){
        ret = min(ret, abs(str[i] - str[i+1]));
    }
    return ret;
}

int main(){
    string str, permut[MAX];
    while(cin >> str){
        permut[11]=str;
        for(int i=10 ; i>=0 ; i--){
            prev_permutation(str.begin(), str.end());
            permut[i] = str; 
        }
        str = permut[11];
        for(int i=12 ; i<22 ; i++){
            next_permutation(str.begin(), str.end());
            permut[i] = str;
        }
        int Max = 0, idx=1;//, ans;
        for(int i=1 ; i<22 ; i++){
            //cout << permut[i] << " " << absVal(permut[i]) << endl;
            if(absVal(permut[i]) > Max){
                Max = absVal(permut[i]); idx = i; 
            }
        }
        cout << permut[idx] << Max << endl;
    }
}

