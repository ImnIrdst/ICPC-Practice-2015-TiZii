#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
//#define cin fin
#define INF (int)1e9

using namespace std;

int main(){
	//ifstream fin("in.txt");
	
	int n; int tc; cin >> tc;
	for(int tcc=0 ; tcc<tc ; tcc++){
		string str, ans=""; int n; char s[2000];
		cin >> n; getchar();
		scanf("%[^\n]",s); str=s; getchar();
		int flag1=1, flag2=1;  int tmp1=0; int i=1,j=1,tmp=1;
		while(n>0){
			for( i=tmp+tmp1, j=tmp+tmp1 ; tmp1+j-1<str.length() && n>0 ; ){
				if(str[tmp1+j-1]=='-')
				{
					tmp1=j+tmp1;
					i=1; j=1;
				}
				if(tmp1+j-1>=str.length()) 
					break;
				ans+=str[tmp1+j-1];
				n--;
				int tmp=j;
				j=i+j;
				i=tmp;
				
			}
			tmp=i; //tmp1=0;
			for(i=str.length()-tmp-tmp1, j=str.length()-tmp-tmp1 ; str.length()-j-tmp1>=0 && n>0 ; ){
				if(str[str.length()-j-tmp1]=='-'){
					tmp1=j+tmp1;
					i=1; j=1;
				}
				if(str.length()-j-tmp1<0) 
					break;
				ans+=str[str.length()-j-tmp1];
				n--;
				int tmp=j;
				j=i+j;
				i=tmp;
			
			}
			tmp=i;
		}
		cout << ans << endl;
	}
}