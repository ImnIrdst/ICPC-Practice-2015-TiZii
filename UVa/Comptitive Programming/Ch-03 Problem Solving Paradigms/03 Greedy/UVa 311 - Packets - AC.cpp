#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int box1, box2, box3, box4, box5, box6;
	while (cin >> box1 >> box2 >> box3 >> box4 >> box5 >> box6,
		box1 + box2 + box3 + box4 + box5 + box6 > 0)
	{
		int parcels = 0;
		// we need 1 parcel for each 6x6 box
		parcels += box6;
		
		// we need 1 parcel for each 5x5 box & fill the parcel with 1x1 boxes
		parcels += box5;
		box1 -= box5 * 11;
		
		// calculate parcels for 4x4 & 3x3 like 5x5 boxes
		parcels += box4;
		box2 -= box4 * 5;

		parcels += (box3 + 3) / 4;
		if (box3 % 4 == 1){
			box2 -= 5;
			box1 -= 7;
		}
		else if (box3 % 4 == 2)
		{
			box2 -= 3;
			box1 -= 6;
		}
		else if (box3 % 4 == 3){
			box2 -= 1;
			box1 -= 5;
		}
		
		// Remaining box2 and box1
		if (box2 > 0){
			parcels += (box2 + 8) / 9;
			box2 -= 9 * ((box2 + 8) / 9);
		}
		if (box2 < 0) box1 += box2 * 4;
		if (box1 > 0) parcels += (box1 + 35) / 36;

		cout << parcels << endl;
	}
	return 0;
}