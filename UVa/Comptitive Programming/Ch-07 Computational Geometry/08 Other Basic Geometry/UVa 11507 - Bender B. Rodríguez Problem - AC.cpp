#include <iostream>
#include <cstdio>

using namespace std;

bool SignChanged(char cur, char c1, char c2){
  if(cur == 'x' && c1 == '-') return true;
  if(cur == 'y' && c2 == 'y' && c1 == '+') return true;
  if(cur == 'z' && c2 == 'z' && c1 == '+') return true;
  return false;
}

int main(){
  int l; char s[3];
  while(scanf("%d", &l) && l){
    int sign=1; char axis='x';
    while(--l){
      scanf("%s",s); if(s[0]=='N') continue;
      if(SignChanged(axis,s[0],s[1])) sign = -sign;
      if(axis == 'x') axis = s[1];
      else if(axis == 'y' && s[1] == 'y') axis = 'x';
      else if(axis == 'z' && s[1] == 'z') axis = 'x';
    }
    cout << (sign>0?'+':'-') << axis << endl;
  }
}