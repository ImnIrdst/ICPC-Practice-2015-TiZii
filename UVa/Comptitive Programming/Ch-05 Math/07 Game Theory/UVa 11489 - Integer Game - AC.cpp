#include <stdio.h>
#include <iostream>
#include <climits>
#include <string>
#define int64 unsigned long long

using namespace std;

int main()
{
    int tc,t=1; cin >> tc; string num;
    while(tc--){
        cin >> num;
        int freq[10]={0}, sum=0;
        for(int i=0 ; i<num.length() ; i++){
            freq[num[i]-'0']++; sum+=num[i]-'0';
        }
        int moves = freq[3]+freq[6]+freq[9];
        bool win = true;
        if(sum%3==0){
            if(moves%2==0) win=false;
        }
        else if(sum%3==1){
            if(freq[1] || freq[4] || freq[7]){
                if(moves%2) win=false;
            }else win=false;
        }
        else {
            if(freq[2] || freq[5] || freq[8]){
                if(moves%2) win=false;
            } else win=false;
        }
        cout << "Case " << t++;
        if(win) cout << ": S" << endl;
        else    cout << ": T" << endl;

    }
    return 0;
}
