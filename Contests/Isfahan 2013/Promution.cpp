#include <iostream>
#include <string>

using namespace std;

string Result; // Jaigasht Nahaii

void promution(string s/*majmooe*/,int j/*raghame Jom Jaigasht*/){
    if(s.length()==0){//age Be Akhar Residim
        cout << Result << endl; return;
    }
    for(int i=0 ; i<s.length() ; i++){
        string temp=s;// temp Vase Ine ke Reshte Taghiir MiKoneh Yeja Nagehesh Darim
        Result+=s[i]; s.erase(i,1);//Khoneii Ro Ke Be Jaygasht Ezaf Mikonim Az Majmooe Hazfesh Mikonim
        promution(s,j+1);
        s=temp;
        Result.erase(Result.length()-1,1);//
    }

}

int main(){
    string s="123456789";
    promution(s,0);
}
