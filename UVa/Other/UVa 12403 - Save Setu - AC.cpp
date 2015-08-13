#include<iostream>
#include<string>
using namespace std;

int main()
{
	string s;
	int k;
	int total = 0;
	int t;
	cin >> t;
	while(t--){
		cin >> s;
		if(s == "report"){
			cout << total << endl;
		}
		else{
			cin >> k;
			total += k;
		}
	}
	return 0;
}