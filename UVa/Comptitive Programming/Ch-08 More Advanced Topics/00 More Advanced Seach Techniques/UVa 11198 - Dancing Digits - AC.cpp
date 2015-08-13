#include <iostream>
#include <string>
#include <queue>
#include <cmath>
#include <map>

using namespace std;

int Hash(string str){
	int ret=0;
	for(int i=0 ; i<str.length() ; i++){
		ret = ret*8+(str[i]-'0');
	}
	return ret;
}

int ismale[8], cs=1; //8!
int isprime[15+1]={0};

string dance(const string& str, int ii, int jj){
	string ret="";
	for(int i=0 ; i<str.length() ; i++){
		if(i==jj) continue;
		ret+=str[i];
		if(i==ii){ ret+=str[jj];
			if(str[ii]>str[jj]) swap(ret[ret.length()-1],ret[ret.length()-2]);
		}
	}
	return ret;
}

int main(){
	isprime[2]=isprime[3]=isprime[11]=1;
	isprime[5]=isprime[7]=isprime[13]=1;
	int tmp, f=Hash("01234567");
	while(cin >> tmp && tmp){
		string s=""; int sign;
		for(int i=0 ; i<8 ; i++){
			if(i!=0) cin >> tmp; 
			sign=tmp/abs(tmp); tmp=abs(tmp)-1;
			if(sign>0) ismale[tmp]=true;
			if(sign<0) ismale[tmp]=false;
			s+=char('0'+tmp);
		}
		map<int,int> dist; int hs=Hash(s);
		queue<string> q; q.push(s); dist[Hash(s)]=0;
		
		while(!q.empty()){
			string cur = q.front(); q.pop(); int curh=Hash(cur);
			if(curh == f) break;
			for(int i=0 ; i<cur.length() ; i++){
				if(!ismale[cur[i]-'0']) continue;
				for(int j=0 ; j<cur.length() ; j++){
					if(ismale[cur[j]-'0']) continue;
					if(!isprime[int(cur[i]-'0')+int(cur[j]-'0')+2]) continue;
					string str1 = dance(cur, i, j); int h1 = Hash(str1);
					string str2 = dance(cur, j, i); int h2 = Hash(str2);
					if(!dist.count(h1)) q.push(str1), dist[h1]=dist[curh]+1;
					if(!dist.count(h2)) q.push(str2), dist[h2]=dist[curh]+1;
				}
			}
		}
		cout << "Case " << cs++  << ": ";
		if(!dist.count(f)) cout << -1 << endl;
		if( dist.count(f)) cout << dist[f] << endl;
		
	}
}