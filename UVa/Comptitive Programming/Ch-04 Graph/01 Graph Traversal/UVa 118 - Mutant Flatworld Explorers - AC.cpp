#include <iostream>
#include <cstring>
#include <string>

using namespace std;

enum dir{ N, W, S, E };
//                  N         W          S          E
int Move[4][2] = { { 0, +1 }, { -1, 0 }, { 0, -1 }, { +1, 0 } };
int x, y, n, m, face, isOff[50 + 10][50 + 10] = { 0 }; char cmd[100 + 10];
bool isLost;

bool inRange(int x, int y){
	return (x <= n && y <= m && x >= 0 && y >= 0);
}

void F(){
	x += Move[face][0];
	y += Move[face][1];
	if (!inRange(x, y)){
		x -= Move[face][0];
		y -= Move[face][1];
		if (!isOff[x][y]) isLost = true, isOff[x][y] = 1;
	}
}

void L(){
	face = (face + 1) % 4;
}

void R(){
	face = (face - 1 + 4) % 4; 
}

int charToFace(char c){
	if (c == 'N') return 0;
	if (c == 'W') return 1;
	if (c == 'S') return 2;
	if (c == 'E') return 3;
}

char faceToChar(int face){
	char c[] = "NWSE";
	return c[face];
}

int main(){
	cin >> n >> m; char c;
	while (cin >> x >> y >> c){
		cin >> cmd; isLost = false;
		face = charToFace(c);
		int len = strlen(cmd);
		for (int i = 0; i < len && !isLost; i++){
			if (cmd[i] == 'F') F();
			if (cmd[i] == 'L') L();
			if (cmd[i] == 'R') R();
		}

		cout << x << " " << y << " " << faceToChar(face);
		if (isLost) cout << " LOST";
		cout << endl;
	}
}