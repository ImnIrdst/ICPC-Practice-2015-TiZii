#include <iostream>
#include <string>
#include <cstring>
#include <sstream>

using namespace std;

string notes[] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B" };

bool possible[12][12]={0}, played[12]={0};

void init(){
	for (int i = 0; i < 12; ++i){
        possible[i][i] = 
        possible[i][(i +  2) % 12] = 
        possible[i][(i +  4) % 12] = 
        possible[i][(i +  5) % 12] = 
        possible[i][(i +  7) % 12] = 
        possible[i][(i +  9) % 12] = 
        possible[i][(i + 11) % 12] = true;
    }
}

int findNote(string note){
	int i=0; while(notes[i]!=note) i++; return i;
}

int valid(int id){
	for(int i=0 ; i<12 ; i++){
		if(played[i] && !possible[id][i]) return false;
	}
	return true;
}

int main(){
	string line, note, sep; init();
	while(getline(cin,line) && line!="END"){
		stringstream sstr(line); memset(played,0,sizeof played);
		while(sstr >> note) played[findNote(note)]=1;
		
		bool first=true;
		for(int i=0 ; i<12 ; i++){
			if(valid(i)){
				if(!first) cout << " "; 
				cout << notes[i]; first=false;
			}
		}
		cout << endl;
	}
}