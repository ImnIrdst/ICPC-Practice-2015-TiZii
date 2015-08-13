#include <iostream>

using namespace std;

const int MAX = 1000+10;

int main(){
    int n, a[MAX];
    while(cin >> n){
        for(int i=0 ; i<n ; i++) 
            cin >> a[i];
        int ans=0;
        for(int i=0 ; i<n ; i++){
            for(int j=i+1 ; j<n ; j++){
                if(a[i]>a[j]) ans++;
            }
        }
        cout << "Minimum exchange operations : " << ans << endl;
    }
}