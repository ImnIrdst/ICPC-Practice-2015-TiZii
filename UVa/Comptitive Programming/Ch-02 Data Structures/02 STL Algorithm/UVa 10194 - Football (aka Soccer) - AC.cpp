#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <fstream>
//#define cin fin
#define INF (int)1e9
#define int64 long long

using namespace std;

struct t{
	string name;
	int pts, gms, w,tie,l, gd, gs, ga;
	t(){pts=gms=w=tie=l=gd=gs=ga=0;}
	t(string Name, int  Pts, int Gms, int W, int Tie, int L, int Gd, int Gs, int Ga){
		name=Name; pts=Pts; gms=Gms; w=W; tie=Tie; l=L; gd=Gd; gs=Gs; ga=Ga;
	}
};

bool cmp(t a, t b){
	if(a.pts>b.pts) return 1;
	else if(a.pts<b.pts) return 0;

	if(a.w>b.w) return 1;
	else if(a.w<b.w) return 0;

	if(a.gd>b.gd) return 1;
	else if(a.gd<b.gd) return 0;

	if(a.gs>b.gs) return 1;
	else if(a.gs<b.gs) return 0;

	if(a.gms<b.gms) return 1;
	else if(a.gms>b.gms) return 0;
	string namea=a.name, nameb=b.name;
	transform(namea.begin(), namea.end(), namea.begin(), ::toupper);
	transform(nameb.begin(), nameb.end(), nameb.begin(), ::toupper);
	if(namea<nameb) return 1;
	else if(namea>nameb) return 0;
}

int main(){
	//ifstream fin("in.txt");
	char title[110], team1[50],team2[50]; int goals1, goals2; bool first=true;
	int tc,n; cin >> tc; cin.ignore();
	while(tc--){
		t teams[50]; map<string,int> mp;
		gets(title); cin >> n; cin.ignore(); int idx=0;
		for(int i=0 ; i<n ; i++){
			gets(team1);
			mp[string(team1)]=idx++;
			teams[idx-1].name=team1;
		}
		int m; cin >> m; cin.ignore();
		for(int i=0 ; i<m ; i++){
			scanf("%[^#]#%d@%d#%[^\n]",team1,&goals1,&goals2,team2); cin.ignore();
			int t1=mp[string(team1)], t2=mp[string(team2)];
			if(goals1>goals2){ teams[t1].pts+=3; teams[t1].w++; teams[t2].l++;}
			if(goals1<goals2){ teams[t2].pts+=3; teams[t2].w++; teams[t1].l++;}
			if(goals1==goals2){ teams[t1].pts+=1; teams[t2].pts+=1; teams[t1].tie++; teams[t2].tie++;}
			teams[t1].gms++; teams[t2].gms++;
			teams[t1].gd+=goals1-goals2; teams[t2].gd+=goals2-goals1;
			teams[t1].gs+=goals1; teams[t2].gs+=goals2;
			teams[t1].ga+=goals2; teams[t2].ga+=goals1;
		}
		sort(teams,teams+n,cmp);
		if(!first) cout << endl; first=false;
		cout << title << endl;
		for(int i=0 ; i<n ; i++){
			printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n", 
				i+1, teams[i].name.c_str(), teams[i].pts, teams[i].gms, 
					teams[i].w, teams[i].tie, teams[i].l, teams[i].gd, teams[i].gs, teams[i].ga);
		}
	}

	return 0;
}