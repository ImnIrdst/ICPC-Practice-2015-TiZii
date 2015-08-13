#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

void PrintVars(string& vars){
    for(int i=0 ; i<vars.length() ; i++){
        if(i) cout << ',';
        cout << vars[i];
    }
}

void PrintIdent(int lev){
    while(lev--) cout << "  " ;
}

void PrintAns(int lev, string& vars){
    if(lev == vars.length()){
        PrintIdent(lev); 
        cout << "writeln("; PrintVars(vars); cout << ")" << endl;
        return;
    }
    string next = vars;
    for(int i=lev-1 ; i>=0 ; i--){
        PrintIdent(lev);
        if(i!=lev-1) cout << "else ";
        cout << "if " << next[i] << " < " << next[i+1]
             <<  " then" << endl;
        PrintAns(lev+1, next); swap(next[i],next[i+1]);
    }
    PrintIdent(lev); cout << "else" << endl; PrintAns(lev+1, next);
}

int main(){
    int tc; cin >> tc;
    while(tc--){
        int n; cin >> n; string vars="";
        for(int i=0 ; i<n ; i++) vars+=('a'+i);
        cout << "program sort(input,output);" << endl;
        cout << "var" << endl; PrintVars(vars); cout << " : integer;" << endl;
        cout << "begin" << endl
              << "  readln("; PrintVars(vars);  cout << ");" << endl;
        if(n == 1) cout << "  writeln(a)" << endl;
        else PrintAns(1, vars);
        cout << "end." << endl;
        if(tc) cout << endl;

    }
}
