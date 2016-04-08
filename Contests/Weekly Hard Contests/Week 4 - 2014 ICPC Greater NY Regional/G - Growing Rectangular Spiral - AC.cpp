#include <iostream>

using namespace std;

int main(){
	int tc;
	cin >> tc;
	while (tc--){
		int cs, x, y;
		cin >> cs >> x >> y;

		if (x < y){
			cout << cs << " 2 " << x << " " << y << endl;
		}
		else if(x >= y &&  y<4){
			cout << cs << " NO PATH" << endl;
		}
		else{
			cout << cs << " 6 1 2 3 " << x+3-y+2 << " " << x + 2 << " " << x + 3 << endl;
		}
	}
}