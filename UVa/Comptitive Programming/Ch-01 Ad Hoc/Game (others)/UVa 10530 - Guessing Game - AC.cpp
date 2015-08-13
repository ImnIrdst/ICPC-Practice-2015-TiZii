#include <iostream>
#include <string>

using namespace std;

int main(){
	int n; string status;
	while(cin >> n && n){
		int lo=0, hi=11, valid=true;
		while(cin >> status >> status && status!="on"){
			if(status=="high"){
				if(n <  hi) hi=n;
				if(n <= lo) valid = false;
			}
			if(status=="low"){
				if(n >  lo) lo=n;
				if(n >= hi) valid = false;
			}
			cin >> n;
		}
		if(lo < n && n < hi && valid){
			cout << "Stan may be honest" << endl;
		}
		else{
			cout << "Stan is dishonest" << endl;
		}
	}
}