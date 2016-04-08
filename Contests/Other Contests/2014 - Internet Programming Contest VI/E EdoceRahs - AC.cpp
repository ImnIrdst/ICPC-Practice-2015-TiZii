#include <iostream>
#include <math.h>
#include <algorithm>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include<string.h>
#include<cstdlib>
#include<cmath>
//#define cin fin
#define cout fout
#define INF (int)1e9

#define		Length(n)		((int)log10(n) + 1)

using namespace std;

char str[500000];

char f2(int flag,int len)
{
	int start = flag;
	int it = 1;
	int size = len;//strlen(str);//.length();
	//flag=1;
	while(start + (1<<it) < size){
		if(!flag){
			start += (1<<it);
		}
		flag=1-flag;
		++it;
	}
	return str[start];
}

char f3(string str, int flag,int n){
	string str2="";
	if(n==1){
		return str[0];
	}
	for(int i=flag ; i<n ; i+=2){
		str2+=str[i];
	}
	return f3(str2,1-flag,str2.length());
}

int LEN(int n)
{
	int sum=0;
	if(n < 10)
		return n;
	sum+=9;
	if(n < 100)
		return (sum + (n - 9)*2);
	sum+=90*2;
	if(n < 1000)
		return sum + (n-99)*3;
	sum+=900*3;
	if(n<10000)
		return sum + (n-999)*4;
	sum+=9000*4;
	if(n<100000)
		return sum + (n-9999)*5;
}

int main(){
	//ifstream fin("in.txt");
	ofstream fout("out.txt");
	char num[10];
	int n; int tc; cin >> tc;
	int first = 0;
	for(int i=1 ; i<=100000 ; i++){
			sprintf(str+first,"%d",i);
			first += Length(i);
			if(i%10000==0)
				i=i;
	}
	for(int tcc=0 ; tcc<tc ; tcc++){
		int first = 0;
		cin >> n; //string str1=""; string str2="";
		if(n == 1 || n == 0){
			cout << "Edoce:" << n << ", ";
		cout << "Rahs:" << n << endl;
		}else{
		//fr(str1,0,e,r);
		int l = LEN(n);
		//cout << n << endl;
		cout << "Edoce:" << f2(0,l) << ", ";
		cout << "Rahs:" << f2(1,l) << endl;
		cout.flush();
		}
	}
}
