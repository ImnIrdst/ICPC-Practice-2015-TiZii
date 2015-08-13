#include <iostream>

using namespace std;

int main(){
	int sz, p;
	while(cin >> sz >> p && (sz||p)){
		int pp=1, found=0, len=0;
		int line=sz/2+1, col=sz/2+1;
		while(!found && p!=pp && len<=sz){
			len++;
			if(pp+len < p) pp+=len, line+=len;
			else for(int i=0 ; i<len && !found; i++){
				pp++; line++; if(pp==p) found=true;
			}
			if(pp+len < p) pp+=len, col-=len;
			else for(int i=0 ; i<len && !found; i++){
				pp++; col--; if(pp==p) found=true;
			}
			
			len++;
			if(pp+len < p) pp+=len, line-=len;
			else for(int i=0 ; i<len && !found; i++){
				pp++; line--; if(pp==p) found=true;
			}
			if(pp+len < p) pp+=len, col+=len;
			else for(int i=0 ; i<len && !found; i++){
				pp++; col++; if(pp==p) found=true;
			}
		}
		cout << "Line = " << line << ", column = " << col << "." << endl;
	}
}
