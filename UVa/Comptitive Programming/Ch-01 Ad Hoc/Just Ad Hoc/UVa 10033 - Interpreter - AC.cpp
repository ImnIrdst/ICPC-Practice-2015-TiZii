#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

string inttoStr(int n){
	string str="";
	str += char('0'+n/100);
	str += char('0'+(n/10)%10);
	str += char('0'+n%10) ;
	return str;
}

int StrToInt(string& s){
	return (s[2]-'0')+(s[1]-'0')*10+(s[0]-'0')*100;
}

int main(){
	int tc;
	cin >> tc; 
	cin.ignore();
	cin.ignore();
	while( tc-- ){
		int i=0, ans=0;
		int reg[10]={0}, n=0;
		int ram[1000]={0}; string cmd; 
		while(getline(cin,cmd) && cmd!="")
			ram[n++]=StrToInt(cmd);
		
		while(true){
			cmd = inttoStr(ram[i]);
			if(cmd == "100" ) break;
			if(cmd[0] == '2') reg[cmd[1]-'0'] = cmd[2]-'0', reg[cmd[1]-'0']%=1000;
			if(cmd[0] == '3') reg[cmd[1]-'0']+= cmd[2]-'0', reg[cmd[1]-'0']%=1000;
			if(cmd[0] == '4') reg[cmd[1]-'0']*= cmd[2]-'0', reg[cmd[1]-'0']%=1000;
			if(cmd[0] == '5') reg[cmd[1]-'0'] = reg[cmd[2]-'0'], reg[cmd[1]-'0']%=1000;
			if(cmd[0] == '6') reg[cmd[1]-'0']+= reg[cmd[2]-'0'], reg[cmd[1]-'0']%=1000;
			if(cmd[0] == '7') reg[cmd[1]-'0']*= reg[cmd[2]-'0'], reg[cmd[1]-'0']%=1000;
			if(cmd[0] == '8') reg[cmd[1]-'0'] = ram[reg[cmd[2]-'0']];
			if(cmd[0] == '9') ram[reg[cmd[2]-'0']] = reg[cmd[1]-'0'];
			if(cmd[0] == '0' && reg[cmd[2]-'0']!=0) i=reg[cmd[1]-'0']-1;
			i++; ans++;
		}
		cout << ans+1 << endl; if(tc) cout << endl;
	}
}