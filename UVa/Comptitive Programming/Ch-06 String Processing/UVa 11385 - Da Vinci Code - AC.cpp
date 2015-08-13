#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <map>
#define int64 long long
#define MAX (100+10)

using namespace std;

int nums[MAX],n; char first[MAX], sec[MAX];

int main(){
    map<int64,int> mp; int64 a=1,b=2,c,bound=1; bound<<=36;
    for(int i=0 ; b<bound ; i++){
        mp[a]=i;
        c=a+b; a=b; b=c;
    }


    int tc; cin >> tc;
    while(tc--){
        cin >> n; memset(sec,' ',sizeof sec);
        for(int i=0 ; i<n ; i++) cin >> nums[i];
        cin.ignore(); gets(first); int MaxIdx=-1;
        for(int i=0,j=0 ; i<strlen(first) && j<n ; i++){
            if(first[i]>='A' && first[i]<='Z'){
                sec[mp[nums[j]]]=first[i];
                if(MaxIdx<mp[nums[j]]) MaxIdx=mp[nums[j]];
                j++;
            }
        }
        sec[MaxIdx+1]='\0';
        cout << sec << endl;
    }
}
