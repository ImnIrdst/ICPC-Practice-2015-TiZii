#include <cstdio>
#include <iostream>
#define isJleap(year) ((year)%4==0)
#define isGleap(year) ((year%400==0) || ((year%4==0) && (year%100!=0)))

using namespace std;

int Cnt_Leaps(int y, int isJ){
	if(isJ){
		return y/4 + !isJleap(y);
	}
	else{
		int cnt=0;
		for(int i=1753 ; i<y ; i++){
			if(isGleap(i)) cnt++;
		}
		return cnt;
	}
}

int Days_of_Month(int m, int year, int isJ){
	switch (m) {
	   case 4: case 6: case 9: case 11:
		  return 30; break;
	   case 2:
		  if(isJ==1) {
			  if(isJleap(year)) return 29;
		  }else if(isGleap(year)) return 29;
		  return 28; break;
	 }
	return 31;
}

int DATE(int m, int d, int y, int isJ){
	int leaps = Cnt_Leaps(y,isJ), days=d;
	for(int i=1 ; i<m ; i++){
		days+=Days_of_Month(i,y,isJ);
	}
	int ans = leaps+days+y - (!isJ)*1752 + isJ*4;
	return ans%7;
}

int main(){

}