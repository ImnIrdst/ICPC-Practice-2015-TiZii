// Not Completed
#include <iostream>
#include <queue>
#include <map>

using namespace std;

const int Max = 100;

struct state{
	int pos, fleas, sides;// pos == die pos, fleas => pos of fleas, sides => is flea on side
	state(int a=0, int dp=0, int dm=0):pos(a), fleas(dp), sides(dm){}
	bool operator<(const state& a) const {
		if(pos == a.pos && fleas == a.fleas) return sides < a.sides;
		if(pos == a.pos) return fleas < a.fleas;
		return pos < a.pos;
	}
};

bool inRange(int i, int j){
	return (i<4 && i>=0 && j>=0 && j<4);
}
char str[10]; map<state, int> dist;
//  4      //  3      //  1      //  2      
//2 0 3 5  //4 0 1 5  //3 0 2 5  //1 0 4 5 
//  1	   //  2      //  4      //  3	  

//  0      //  3      //  1      //  2      
//2 1 3 4  //4 0 1 5  //3 0 2 5  //1 0 4 5 
//  5	   //  2      //  4      //  3	  

//  1      //  3      //  1      //  2      
//2 5 3 0  //4 0 1 5  //3 0 2 5  //1 0 4 5 
//  4	   //  2      //  4      //  3	  
  
int dface[4][6][4] = {
{{4,3,1,2},{0,3,2,5},{4,0,1,5},{4,5,1,0},{1,3,2,0},{4,2,1,3}},
{{4,3,1,2},{0,3,2,5},{4,0,1,5},{4,5,1,0},{1,3,2,0},{4,2,1,3}},
{{4,3,1,2},{0,3,2,5},{4,0,1,5},{4,5,1,0},{1,3,2,0},{4,2,1,3}},
{{4,3,1,2},{0,3,2,5},{4,0,1,5},{4,5,1,0},{1,3,2,0},{4,2,1,3}}};
int di[] = {-1,0,1,0};
int dj[] = {0,1,0,-1};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		state s; int pos=0;
		for(int i=0 ; i<4 ; i++){
			cin >> str; dist.clear();
			for(int j=0 ; j<4 ; j++){
				if(str[j]=='X') s.fleas |= (1<<pos);
				if(str[j]=='D') s.pos = pos;
				pos++;
			}

			queue<state> q; q.push(s); dist[s]=0;
			
			while(!q.empty()){
				state u = q.front(); q.pop();
				if(u.fleas==0) break;
				int ui = u.pos / 4;
				int uj = u.pos % 4;
				for(int dir=0 ; dir<4 ; dir++){
					int vi = ui + di[dir];
					int vj = uj + dj[dir];
					if(!inRange(vi, vj)) continue;
					int vdpos = vi*4 + vj;
					int vside = u.sides;
					

				}
			}
		}
	}
}