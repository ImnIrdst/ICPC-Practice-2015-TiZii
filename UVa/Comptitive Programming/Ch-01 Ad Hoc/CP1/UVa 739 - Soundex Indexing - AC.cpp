#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int getCode(char c){
    string tmp;
    tmp = "AEIOUYWH";   if(tmp.find(c)!=-1) return -1;
    tmp = "BPFV";       if(tmp.find(c)!=-1) return  1;
    tmp = "CSKGJQXZ";   if(tmp.find(c)!=-1) return  2;
    tmp = "DT";         if(tmp.find(c)!=-1) return  3;
    tmp = "L";          if(tmp.find(c)!=-1) return  4;
    tmp = "MN";         if(tmp.find(c)!=-1) return  5;
    tmp = "R";          if(tmp.find(c)!=-1) return  6;
}

void gotoCol(int n, int cur){
    for(int i=cur ; i<n ; i++) printf(" ");
}

int main(){
    gotoCol(10,1); printf("NAME"); gotoCol(35,10+4); printf("SOUNDEX CODE\n");
    string str, code;
    while(cin >> str){
        code = str[0]; code += "000"; int num = getCode(str[0]), id=1;
        for(int i=1 ; i<str.length() ; i++){
            int tmp  = getCode(str[i]);
            if( tmp != num && tmp != -1){
                code[id++] = tmp+'0';
            }
            num = tmp;
        }
        gotoCol(10,1);                  printf("%s", str.c_str());
        gotoCol(35,10+str.length());    printf("%s\n", code.substr(0,4).c_str());
    }
    gotoCol(20,1); printf("END OF OUTPUT\n");
}