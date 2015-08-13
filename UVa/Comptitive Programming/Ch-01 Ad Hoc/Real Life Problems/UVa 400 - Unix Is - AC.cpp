#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n;
	while(cin >> n){
		int maxSize=0; cin.ignore();
		vector<string> arr(n); 
		for(int i=0 ; i<n ; i++){
			getline(cin, arr[i]); maxSize = max(maxSize,(int)arr[i].size());
		}
		
		sort(arr.begin(), arr.end()); //maxSize+=2;
		for(int i=0 ; i<60 ; i++) cout << '-'; cout << endl;

		int Cols = 60/(maxSize+2); if(Cols==0) Cols++;
		int Rows = n/Cols + (n%Cols!=0);
		for(int i=0 ; i<Rows ; i++){
			for(int j=i ; j<n ; j+=Rows){
				while(arr[j].size()!=(maxSize+2)) arr[j]+=' ';
				cout << arr[j];// i++;
			} cout << endl;
		}
	}
}