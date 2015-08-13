#include <iostream>
#include <cmath>
#include <algorithm>
#include <sstream>

using namespace std;

string rom[4000] = {"0", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X"};

void init(){
    for(int i=11 ; i<4000 ; i++){
        int tmp=i;
        while(tmp){
            if(tmp>=900 && tmp<4000){
                if(tmp/100 == 9) rom[i]+="CM", tmp-=900;
                else rom[i]+="M", tmp-=1000;
            }
            if(tmp>=400 && tmp<900){
                if(tmp/100==4) rom[i]+="CD", tmp-=400;
                else rom[i]+="D", tmp-=500;
            }
            if(tmp>=90 && tmp<400){
                if(tmp/10==9) rom[i]+="XC", tmp-=90;
                else rom[i]+="C", tmp-=100;
            }
            if(tmp>=40 && tmp<90){
                if(tmp/10==4) rom[i]+="XL" , tmp-=40;
                else rom[i]+="L", tmp-=50;
            }
            if(tmp>=1 && tmp<40){
                for(int j=10 ; j>=1 ; j--){
                   if(tmp>=j){
                       rom[i]+=rom[j]; tmp-=j; break;
                   }
                }
            }
        }
    }
}

int main(){
    string str; init();
    while(cin >> str){
       //for(int i=0 ; i<12 ; i++) cout << rom[i] << " "; cout << endl;
       if(str[0]>='1' && str[0]<='9') {
           stringstream sstr(str); int i; sstr >> i;
           cout << rom[i] << endl;
       }
       else{
           cout << (int)(find(rom,rom+4000,str)-rom) << endl;
       }
    }
}

