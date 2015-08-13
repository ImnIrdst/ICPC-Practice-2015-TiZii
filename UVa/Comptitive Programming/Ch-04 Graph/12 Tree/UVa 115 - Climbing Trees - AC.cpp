#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <cstdlib>

using namespace std;

const int MAX = 300+10;

int par[MAX], n=1; map<string, int> mp;

int insert_name(string& name){
	if(mp.count(name)) return mp[name];
	else mp[name]=n++; return mp[name];
}

int get_id(string& name){
	if(mp.count(name)) return mp[name];
	else return 0;
}

int is_parent(int pid, int qid){
	for(int k=0 ; par[qid] ; k++, qid=par[qid])
		if(par[qid]==pid) return k;
	return -1;
}

bool are_cousins(int pid, int qid, int& k, int& j) {
  for (int kp = 0; par[pid]; kp++, pid = par[pid]) {
    int ri = qid;
    for (int kq = 0 ; par[ri]; kq++, ri = par[ri])
      if (par[pid] == par[ri]) {
        k = min(kp, kq); j = abs(kp - kq); return true;
      }
  }
  return false;
}

int main(){
	string p,q; 
	while(cin >> p >> q && p!="no.child"){
		int pid=insert_name(p), qid=insert_name(q); par[pid]=qid;
	}
	while(cin >> p >> q){
		int pid=get_id(p), qid=get_id(q), k,j;
		if(!pid || !qid) cout << "no relation" << endl;
		else if((k=is_parent(pid,qid))!=-1){
			while(k--) cout << (k ?"great ":"grand ");
			cout << "parent" << endl;
		}
		else if((k=is_parent(qid,pid))!=-1){
			while(k--) cout << (k ?"great ":"grand ");
			cout << "child" << endl;
		}
		else if(par[pid] && par[pid]==par[qid]) cout << "sibling" << endl; 
		else if(are_cousins(pid,qid,k,j)){
			cout << k << " cousin";
			if(j) cout << " removed " << j;
			cout << endl;
		}
		else cout << "no relation" << endl;
	}
}