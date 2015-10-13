#include <iostream>
#include <cstring>
#include <string>

using namespace std;

const int MAX = 26+10;

int adj[MAX][MAX], indeg[MAX];

int main(){
    string str;
    while(cin >> str){
        memset(adj, 50, sizeof adj);
        memset(indeg, 0, sizeof indeg);

        int ans = 0;
        while(str!="deadend"){
            int u = str[0] - 'a';
            int v = str[str.length()-1  ] - 'a';
            adj[u][v] = str.length();
            adj[v][u] = str.length();
            indeg[u]++; indeg[v]++;
            ans+=str.length();
            cin >> str;
        }
        int n = MAX;
        for(int k=0 ; k<n ; k++){
            for(int i=0 ; i<n ; i++){
                for(int j=0 ; j<n ; j++){
                    adj[i][j] = min(adj[i][j], adj[i][k]+adj[k][j]);
                }
            }
        }

        int odd1 = -1, odd2 = -1;
        for(int i=0 ; i<MAX;  i++){
            if(indeg[i] % 2 == 1) odd1 = i;
        }
        for(int i=0 ; i<MAX;  i++){
            if(indeg[i] % 2 == 1 && i != odd1) odd2 = i;
        }
        if(odd1 != -1 && odd2 != -1){
            ans += adj[odd1][odd2];
        }
        cout << ans << endl;
    }
}
