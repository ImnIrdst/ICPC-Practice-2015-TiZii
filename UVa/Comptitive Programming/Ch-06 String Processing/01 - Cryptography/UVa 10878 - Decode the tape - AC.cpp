#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string str; //cout << (int)'A' << endl;
    getline(cin,str);
    while(getline(cin,str)){
        if(str[0]!='|') continue;
        char ans=0;
        for(int i=0 ; i<str.length() ; i++){
            if(str[i]==' '){
                ans=ans*2+0;
            }else if(str[i]=='o'){
                ans=ans*2+1;
            }
        }
        //cout << (int)ans << endl;
        cout << ans;
    }
    //cout << endl;
}
