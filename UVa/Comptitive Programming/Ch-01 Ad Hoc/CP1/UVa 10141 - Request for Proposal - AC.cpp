#include <iostream>
#include <string>

using namespace std;

int main(){
    int n, p, cs=1;
    while(cin >> n >> p && (n||p)){
        string str; cin.ignore();
        for(int i=0 ; i<n ; i++){
            getline(cin,str);
        }
        string name, ans; 
        double d; int r, MaxReq=0;
        double bestComp=0, bestCost=1e100;
        for(int i=0 ; i<p ; i++){
            getline(cin,name); cin >> d >> r; cin.ignore();
            for(int i=0 ; i<r ; i++){
                getline(cin, str);
            }
            if(r > MaxReq || (r==MaxReq && d<bestCost)){
                MaxReq = r; bestCost = d; ans = name;
            }
        }
        if(cs>1) cout << endl;
        cout << "RFP #" << cs++ << endl;
        cout << ans << endl; 
    }
}