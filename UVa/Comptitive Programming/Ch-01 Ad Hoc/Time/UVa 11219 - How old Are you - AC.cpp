#include <iostream>

using namespace std;

int main(){
	char c;
	int d1, m1, y1;
	int d2, m2, y2;
	int tc, cs=1; cin >> tc;
	while(tc--){
		cin >> d2 >> c >> m2>> c >> y2;
		cin >> d1 >> c >> m1 >> c >> y1;

		int age = y2-y1;
		if( m2<m1 || (m1==m2 && d2<d1)) age--;

		cout << "Case #" << cs++ << ": ";// << endl;

		if( age < 0 )
			cout << "Invalid birth date" << endl;
		else if( age > 130 )
			cout << "Check birth date" << endl;
		else
			cout << age << endl;
	}
}