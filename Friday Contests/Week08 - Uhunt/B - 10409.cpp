#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int t;
	while(cin >> t && t){
		string c;
		int cur_pos[] = {1,2,6,5,3,4};
		while(t--){
			cin >> c;
			int tmp;
			if(c == "north"){
				tmp = cur_pos[0];
				cur_pos[0] = cur_pos[3];
				cur_pos[3] = cur_pos[2];
				cur_pos[2] = cur_pos[1];
				cur_pos[1] = tmp;
			}
			else if(c == "south"){
				tmp = cur_pos[3];
				cur_pos[3] = cur_pos[0];
				cur_pos[0] = cur_pos[1];
				cur_pos[1] = cur_pos[2];
				cur_pos[2] = tmp;
			}
			else if(c == "east"){
				tmp = cur_pos[5];
				cur_pos[5] = cur_pos[0];
				cur_pos[0] = cur_pos[4];
				cur_pos[4] = cur_pos[2];
				cur_pos[2] = tmp;
			}
			else{
				tmp = cur_pos[4];
				cur_pos[4] = cur_pos[0];
				cur_pos[0] = cur_pos[5];
				cur_pos[5] = cur_pos[2];
				cur_pos[2] = tmp;
			}
		}
		cout << cur_pos[0] << endl;
	}
	return 0;
}