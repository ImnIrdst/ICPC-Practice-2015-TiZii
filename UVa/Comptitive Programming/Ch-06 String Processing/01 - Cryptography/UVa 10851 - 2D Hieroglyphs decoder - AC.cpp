#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int tc; cin >> tc; string str;
    while(tc--){
        //cout << (int)'/' << endl;
        //cout << (int)'\\' << endl;
        cin >> str; cin .ignore();
        vector<int> ans; vector<string> vstr; bool first=true;
        while(getline(cin,str) && str!=""){
            vstr.push_back(str);
        }
        while(!vstr.empty()){
            str=vstr.back(); vstr.pop_back();
            for(int i=str.length()-2 ; i>0 ; i--){
                int bit=(str[i]=='/' ? 0 : 1);
                if(first) ans.push_back(bit);
                else ans[i-1]=ans[i-1]*2+bit;
            }
            first=false;
        }

        for(int i=0 ; i<ans.size() ; i++){
            cout << (char)ans[i];
        }
         cout << endl;
    }
}
