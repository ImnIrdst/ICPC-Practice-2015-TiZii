#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string str1, str2;
    while(getline(cin,str1) && getline(cin,str2)){
        int freq1[30]={0},freq2[30]={0};
        for(int i=0 ; i<str1.length() ; i++) freq1[str1[i]-'a']++;
        for(int i=0 ; i<str2.length() ; i++) freq2[str2[i]-'a']++;
        for(int i=0 ; i<30 ; i++){
            while(freq1[i] && freq2[i]){
                cout << char('a'+i) ;
                freq1[i]--, freq2[i]--;
            }
        }
        //cout << "XXX";
        cout << endl;
    }
}
