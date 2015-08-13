#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int toInt(string str){
    stringstream sstr(str);
    int ret; sstr >> ret;
    return ret;
}

int main(){
    string str; int i,ans=0;
    while(getline(cin,str)){
        string a="";
        for(i=0 ; i<str.length() ; i++){
             if(str[i]=='+' || str[i]=='-') break;
             a+=str[i];
        }
        string b=""; b=str[i];
        for(i=i+1 ; i<str.length() ; i++){
            if(str[i]=='=') break;
            b+=str[i];
        }
        string c="";
        for(i=i+1 ; i<str.length() ; i++){
            c+=str[i];
        }
        if(c=="?" || toInt(a)+toInt(b)!=toInt(c)) continue;
        else ans++;
    }
    cout << ans << endl;
}
