#include <iostream>

using namespace std;

int main(){
    int tc; cin >> tc; cin.ignore();
    while(tc--){
        int amp, freq; cin >> amp >> freq;
        while(freq--){
            for(int i=1 ; i<amp ; i++){
                for(int j=0 ; j<i; j++){
                    cout << i ;
                }
                cout << endl;
            }
            for(int i=amp ; i>0 ; i--){
                for(int j=0 ; j<i; j++){
                    cout << i ;
                }
                cout << endl;
            }
            if(freq || tc) cout << endl;
        }

    }
}
