#include <iostream>
#include <string>

using namespace std;

int main(){
	int cs;
	while(cin >> cs && cs!=-1){
		int sum=0;
		int occ[256]={0};
		string str1, str2; 
		cin >> str1 >> str2;
		for(int i=0 ; i<str1.length() ; i++){
			sum+=1-occ[str1[i]];
			occ[str1[i]]=true;
		}

		int hangman=7;
		for(int i=0 ; i<str2.length() && hangman && sum ; i++){
			if(occ[str2[i]]==0) hangman--, occ[str2[i]]=2;
			if(occ[str2[i]]==1) occ[str2[i]]=2, sum--;
		}

		cout << "Round " << cs << endl;
		if(hangman && !sum){
			cout << "You win." << endl;
		}
		if(hangman && sum){
			cout << "You chickened out." << endl;
		}
		if(!hangman){
			cout << "You lose." << endl;
		}
	}
}