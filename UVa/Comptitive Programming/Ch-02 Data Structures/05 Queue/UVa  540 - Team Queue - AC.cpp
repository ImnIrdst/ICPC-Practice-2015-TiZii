#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef queue< int > que;
typedef vector< que > vque;

const int MAX = 1000000+10;

int membTeam[MAX]={0};

int main(){
    int n, m, cs=1;
    while( cin >> n && n ){
        int memb, teamNum=0; memset(membTeam,0,sizeof membTeam);
        for(int i=0 ; i<n ; i++){ cin >> m;
            for(int i=0 ; i<m ; i++){ 
                cin >> memb; membTeam[memb] = teamNum; 
            } teamNum++;
        }
        
        //cin >> m; for(int i=0 ; i<m ; i++){ cin >> memb; membTeam[memb] = teamNum; }
        que teams; vque vteams(n); char cmd[20];
        cout << "Scenario #" << cs++ << endl;
        while(cin >> cmd && cmd[0]!='S'){ 
            if(cmd[0]=='E'){cin >> memb;
                if(vteams[membTeam[memb]].empty()){
                    teams.push(membTeam[memb]);
                }
                vteams[membTeam[memb]].push(memb);
            }
            if(cmd[0]=='D'){
                int top;
                while(1){
                    top = teams.front();
                    if(vteams[top].empty()) teams.pop(); else break;
                }
                cout << vteams[top].front() << endl; vteams[top].pop();
                if(vteams[top].empty()) teams.pop();
            }
        }
        cout << endl;
    }
}
