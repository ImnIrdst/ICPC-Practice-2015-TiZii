#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

map<string, string> mp;
set<string>::iterator itr;

set<string> forChild(string pa, string pb){
	string rha, rhb; set<string> Bloods;
	rha = pa[pa.size()-1]; rhb = pb[pb.size()-1];
	pa  = pa.substr(0,pa.size()-1); // A or B or O or AB
	pb  = pb.substr(0,pb.size()-1); // A or B or O or AB
	pa  = mp[pa]; pb = mp[pb];      // A or B or O or AB
	for(int i=0 ; i<2 ; i++){
		for(int j=0 ; j<2 ; j++){
			string mix = ""; mix+=pa[i]; mix+=pb[j];
			Bloods.insert(mp[mix]+"-");
			if(rha=="+" || rhb=="+") 
				Bloods.insert(mp[mix]+"+"); 
		}
	}
	return Bloods;
}

set<string> forParent(string p, string c){
	set<string> Bloods, tmp; string types[] = {"A", "B", "AB", "O"};
	for(int i=0 ; i<4 ; i++){
		tmp = forChild(p, types[i]+"+");
		if(tmp.count(c)) Bloods.insert(types[i]+"+");
		tmp = forChild(p, types[i]+"-");
		if(tmp.count(c)) Bloods.insert(types[i]+"-");
	}
	return Bloods;
}

void PrintBloods(const set<string>& b){
	if(b.empty()){ 
		cout << "IMPOSSIBLE"; return; }
	if(b.size() > 1) cout << "{";
	for(itr = b.begin() ; itr!=b.end() ; itr++){
		if(itr!=b.begin()) cout << ", "; cout << *itr;
	}
	if(b.size() > 1) cout << "}";
}

int main(){
	mp["AA"] = "A" , mp["AO"] = "A" ,
	mp["AB"] = "AB", mp["BA"] = "AB",
	mp["BO"] = "B" , mp["BB"] = "B" ,
    mp["OA"] = "A" , mp["OO"] = "O" ,
	mp["OB"] = "B" , mp["A"]  = "AO",
	mp["B"]  = "BO", mp["O"]  = "OO";
	string pa, pb, c; int cs=1;
	while(cin >> pa >> pb >> c && pa!="E"){
		cout << "Case " << cs++ << ": ";
		if(c == "?"){ // Child Missing.
			set<string> Bloods = forChild(pa, pb);
			cout << pa << " " << pb << " ";
			PrintBloods(Bloods); cout << endl;
		}
		if(pa== "?"){ // first parent missing
			set<string> Bloods = forParent(pb, c);
			PrintBloods(Bloods); cout << " " << pb << " " << c << endl;
		}
		if(pb== "?"){ // second parent missing
			set<string> Bloods = forParent(pa, c);
			cout << pa << " "; PrintBloods(Bloods); cout << " " << c << endl;
		}
	}

}