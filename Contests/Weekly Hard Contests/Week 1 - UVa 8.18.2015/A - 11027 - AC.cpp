#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

string perm;
string odd_char;

typedef long long int64;

int64 fact_table[16];

bool Posssible(string& str)
{
	vector<int> hist(26);
	for(int i = 0 ; i < str.length() ; ++i){
		hist[str[i] - 'a']++;
	}
	bool odd_seen = false;
	for(int i = 0 ; i < 26 ; ++i){
		if(hist[i] % 2){
			if(odd_seen) return false;
			odd_seen = true;
			hist[i] /= 2;
			odd_char += char('a'+i);
		}
		else{
			hist[i] /= 2;
		}
		for(int j=0 ; j<hist[i] ; j++){
			perm+=char('a'+i);	
		}
	}

	return true;
}

void Fact()
{
	fact_table[0] = 1;
	for(int i = 1 ; i < 16 ; ++i)
		fact_table[i] = fact_table[i-1] * i;
}

int64 ComputePermNum(const string& str, char removed)
{
	int64 total = fact_table[str.length()-1];
	vector<int> hist(26,0);
	for(int i = 0 ; i < str.length() ; ++i){
		hist[str[i] - 'a']++;
	}
	hist[removed-'a']--;
	for(int i = 0 ; i < 26 ; ++i)
		total /= fact_table[hist[i]];
	return total;
}

string ComputeAns(const string& str, int64 n)
{
	if(n==0) return str;
	if(str.length()==0) return "";

	int64 i, j, prevj=0; string ret="";
	for(i=0, j=0; i<str.length() && j<n ; i++){
		prevj = j;
		j+=ComputePermNum(str, str[i]);
		char tmp=str[i];
		while(i<str.length() && str[i]==tmp ) i++; i--;
	}
	if(i==str.length()+1) i--;
	string tmp = str; tmp.erase(i-1,1);
	ret += str[i-1];
	ret += ComputeAns(tmp, n-prevj);
	//ret += 
	return ret;
}

int main()
{
	Fact();
	//cout << ComputePermNum("aabbc", 'a') << endl;
	int64 testcase;
	cin >> testcase;
	for(int tc = 1 ; tc <= testcase ; ++tc){
		string str; int64 n;
		cin >> str >> n;
		//for(n=n ; n<10 ; n++){
		odd_char = "";
		perm = "";
		if(!Posssible(str) || ComputePermNum(perm+'a', 'a')<n){
			cout << "Case " << tc << ": XXX" << endl;
		}
		else{
			string ans = ComputeAns(perm, n), rev; rev = ans; reverse(rev.begin(), rev.end());
			cout << "Case " << tc << ": " << ans+odd_char+rev << endl;
		}
		//}
	}
	return 0;
}