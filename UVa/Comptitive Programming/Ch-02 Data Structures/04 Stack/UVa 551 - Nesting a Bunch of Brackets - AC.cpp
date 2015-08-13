#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(){
    string str;
    while(getline(cin, str)){
        stack<string> st; int error=0, n = str.length();
        for(int i=0, j=1 ; i<str.length() && !error ; i++, j++){
            //cout << str.substr(i,1) << " " << str.substr(i,2) << endl;
            if(i<n-1 && str.substr(i,2)=="(*") st.push("(*"), i++;
            else if(str.substr(i,1)=="(")  st.push("(");
            else if(str.substr(i,1)=="[")  st.push("[");
            else if(str.substr(i,1)=="{")  st.push("{");
            else if(str.substr(i,1)=="<")  st.push("<");
            
            else if(i<n-1 && str.substr(i,2)=="*)") if(!st.empty() && st.top()=="(*") st.pop(), i++; else error=j;
            else if(str.substr(i,1)==")")  if(!st.empty() && st.top()=="(")  st.pop(); else error=j;
            else if(str.substr(i,1)=="]")  if(!st.empty() && st.top()=="[")  st.pop(); else error=j;
            else if(str.substr(i,1)=="}")  if(!st.empty() && st.top()=="{")  st.pop(); else error=j;
            else if(str.substr(i,1)==">")  if(!st.empty() && st.top()=="<")  st.pop(); else error=j;
        }
        if(error)            cout << "NO " << error << endl;
        else if(!st.empty()) cout << "NO " << str.size()+1 << endl;
        else                 cout << "YES" << endl;
    }
}