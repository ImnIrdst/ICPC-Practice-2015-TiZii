#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main(){
	map<char, int> mpw;
    mpw['A'] = 0; mpw['G'] = 1; mpw['N'] = 2;
    mpw['P'] = 3; mpw['S'] = 4;
    while(true){
 		string str;
 		vector<string> city;
    	while(true){
    		cin >> str; string tmp="12345";
    		if(str[0]=='e') break;
    		if(str[0]=='#') return 0;
    		for(int j=0 ; j<str.length() ; j+=4){
    			tmp[mpw[str[j+2]]]=str[j];
    		}
    		city.push_back(tmp);
    	}
    	int Min=1e9, ans=0;
    	for(int i=0 ; i<city.size() ; i++){
    		int dif=0;
    		for(int j=0 ; j<city.size() ; j++){
    			if(i==j) continue;
    			for(int k=0 ; k<5 ; k++){
    				if(city[i][k]!=city[j][k]) dif++;
    			}
    		}
    		if(dif < Min) Min = dif, ans = i;
    	}
    	cout << ans + 1 << endl;
    }
}