#include <iostream>
#include <map>

using namespace std;

int main(){
	int n; map<int,int> inp, freq;
	for(int i=0 ; cin >> n ; i++){
		if(!freq.count(n)){
			freq[n]=1; inp[i]=n;
		}else freq[n]++;
	}
	map<int,int>::iterator it1;//
	for(it1=inp.begin() ; it1!=inp.end() ; it1++){
		cout << it1->second << " " << freq[it1->second] << endl;
	}
}