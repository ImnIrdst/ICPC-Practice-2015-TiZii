#include <iostream>
#include <string>
#include <set>

using namespace std;

set<string> SET;
string in;

int bfs(int index, int left,int numOfb,int level, string pass){
	if(index<0 || level==0) return 0;
	if(in[index]!='b') pass+=in[index];
	if(left==0 && (index==0 || in[index-1]=='b')){
		SET.insert(pass);
		return 1;
	}
	if(left==0)
			return 0;
	
	int x=0;
	if(in[index]!='b'){
		x+=bfs(index, left-1, 0,level-1,pass);
		if(index!=0 && in[index-1]=='b') left+=1;
		x+=bfs(index-1, left-1, 0,level-1,pass);
	}else{
		if(index-numOfb-1<0)
			return 0;
		x+=bfs(index, left, numOfb+1,level-1,pass);
		x+=bfs(index-numOfb-1, left-1,0,level-1,pass);
	}
	return x;
}

int main(){
	int n, tmp; cin >> n;
	while(n){
		string tmpstr="";
		for(int i=0 ; i<n ; i++){
			cin >> tmp;
			if(tmp==99)
				tmpstr+='b';
			else tmpstr+=tmp+'0';
		}
		in=tmpstr;
		int left=(in[in.length()]=='b' ? 4 : 3);
		bfs(in.length()-1,4,0,15,"");
		cout << SET.size() << endl;
		SET.clear();
		cin >> n;
	}
}