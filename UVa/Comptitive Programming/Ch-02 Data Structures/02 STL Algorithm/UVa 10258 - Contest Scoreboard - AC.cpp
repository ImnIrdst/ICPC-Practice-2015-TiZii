#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <sstream>
#define INF (int)1e9
#define int64 long long

using namespace std;

class contestant{
public:
	int p[15];
	int solved, Time, mark, name;
	contestant(){
		memset(p,0,sizeof p); mark=Time=solved=0;
	}
} ;



bool cmp(contestant& a, contestant& b){
	if(a.solved>b.solved) return 1;
	if(a.solved==b.solved && a.Time<b.Time) return 1;
	if(a.solved==b.solved && a.Time==b.Time && a.name<b.name) return 1;
	return 0;
}

int main(){
	string str; int tc; cin >> tc; getline(cin,str); getline(cin,str);
	int first=true;
	while(tc--){
		int n=1; contestant team[110]; stringstream sstr;
		while(n++){
			getline(cin,str); sstr << str;
			if(str.empty()) break;
			int Team, p, Time; char stat;
			sstr >> Team >> p >> Time >> stat;
			team[Team].mark=1; team[Team].name=Team;
			if(stat=='C' && team[Team].p[p]!=-1){
				team[Team].solved++;
				team[Team].Time+=20*team[Team].p[p]+Time;
				team[Team].p[p]=-1;
			}else if(stat=='I' && team[Team].p[p]!=-1){
				team[Team].p[p]++;
			}
			sstr.clear();
		}
		sort(team,team+110,cmp);
		if(!first) cout << endl; first=false;
		for(int i=0 ; i<110 ; i++){
			if(team[i].mark){
				printf("%d %d %d\n", team[i].name, team[i].solved, team[i].Time);
			}
		}
	}
	return 0;
}