#include <stdio.h>
#include <iostream>

using namespace std;

char bf[1005];

int main() {
    int tc;
    cin >> tc;
    while(tc--) {
        cin >> bf;
        int i, j, yes = 0;
        for(i = 0; bf[i]; i++) {
            if(bf[i] == '(') {
                int flag[26] = {};
                while(bf[i] != ')') {
                    if(bf[i] >= 'a' && bf[i] <= 'z') {
                        if(i >= 0 && bf[i-1] == '~')
                            flag[bf[i]-'a'] |= 2;
                        else
                            flag[bf[i]-'a'] |= 1;
                       }
                       i++;
                   }
                for(j = 0; j < 26; j++)
                    if(flag[j] == 3) break;
                if(j == 26) yes = 1;
            }
        }
        cout << (yes ? "YES" : "NO") << endl;
    }
    return 0;
}