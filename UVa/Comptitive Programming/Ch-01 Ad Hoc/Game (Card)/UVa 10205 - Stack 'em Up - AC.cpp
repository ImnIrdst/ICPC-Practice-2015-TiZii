#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>

using namespace std;

int n,k, p[100][52], cur[52],nxt[52];

string s1[] = {"2","3","4","5","6","7","8","9","10","Jack","Queen","King","Ace"};
string s2[] = {"Clubs","Diamonds","Hearts","Spades"};
int first = 0;
    

int main(){
	string line;
    int tc; cin >> tc; 
    while(tc--){
        cin >> n;
        for(int i = 0;i <n;i++){
            for(int j = 0;j < 52;j++){
                cin >> p[i][j];
                p[i][j]--;
            }
        }
        for(int i = 0;i < 52;i++) cur[i] = i;
        getline(cin,line);
        while(getline(cin,line)){
            if(line.empty()) break;
            istringstream is(line);
            is >> k;
            k--;
            for(int i = 0;i < 52;i++) nxt[i] = cur[p[k][i]];
            for(int i = 0;i < 52;i++) cur[i] = nxt[i];
        }
        if(first++) printf("\n");
        for(int i = 0 ; i < 52 ; i++)
			printf("%s of %s\n",s1[cur[i] % 13].c_str() ,s2[cur[i] / 13].c_str() );
    }
    
    return 0;
}