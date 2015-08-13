#include <iostream>
#include <string>

using namespace std;

string org, goal;

void bfs(string tmp, string path, string stack, int i, int o){
    //cout << tmp << "\t\t" << stack << "\t\t" << path << "\t\t" << i << "\t\t"  << o << endl;
    if(i+o == goal.size()*2){
        if(goal==tmp && i==o) cout << path.substr(1) << endl; return;
    }
    if(o>i || i>org.length()) return;
    
    if(i<org.length()){
        bfs(tmp, path+" i", stack+org[i], i+1, o);
    }
    if(stack.size()>0){
        char top = stack[stack.length()-1]; 
        if(top==goal[tmp.size()]) bfs(tmp+top, path+" o", stack.substr(0,stack.size()-1), i, o+1); 
    }
}

int main(){
    while(cin >> org >> goal){
        cout << "[" << endl;
            bfs("","","",0,0);
        cout << "]" << endl;
    }
}