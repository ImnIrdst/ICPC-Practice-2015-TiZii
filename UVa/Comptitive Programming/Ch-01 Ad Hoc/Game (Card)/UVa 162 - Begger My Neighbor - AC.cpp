#include <iostream>
#include <cstdio>
#include <list>
#include <string>

using namespace std;

char mp(char c){
	if(c == 'J') return 1; if(c == 'Q') return 2; 
	if(c == 'K') return 3; if(c == 'A') return 4;
	return 0;
}

int play(int cover, list<char>& player, list<char>& played){
	if(!cover) cover=1;
	while(cover--){
		if(player.empty()) return -1;
		int face = mp(player.front());
		played.push_back(player.front());
		player.pop_front(); 
		if(face) return face;
	}
	return 0;
}

int main(){
	string card; 
	while(cin >> card && card!="#"){
		list<char> player[2], played;

		player[0].push_front(card[1]);
		for(int i=1; i<52 ; i++){
			cin >> card; player[i%2].push_front(card[1]);
		}

		int prev=0;
		int face=0;
		int turn=0;
		while(true){
			face = play(prev, player[turn], played);
			if(face == -1) break;
			if(!face && prev) player[1-turn].splice(player[1-turn].end(), played);
			prev = face, turn = 1-turn;
		}
		turn = 1-turn;
		printf("%d%3d\n", 2-turn, int(player[turn].size()));
	}
}