#include <iostream>
#include <string>

using namespace std;

int times[] = {1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,1,2,3,4,1,2,3,1,2,3,4};
// chars    =  a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z}

int main(){
	int tc;
	int cs=1;
	cin >> tc;
	cin.ignore();
	while(tc--){
		string str; getline(cin, str);
		
		int ans = 0;
		for(int i = 0 ; i<str.length() ; i++){
			if(str[i]==' ') ans++;
			else ans += times[str[i]-'a'];
		}
		cout << "Case #" << cs++ << ": " << ans << endl;
	}
}