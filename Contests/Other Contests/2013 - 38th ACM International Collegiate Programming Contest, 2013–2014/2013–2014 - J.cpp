#include <iostream>
#include <algorithm>

using namespace std;

struct point{
	int x,y;
};
int a[600][600]={0}, b[600][600]={0};

int main(){
	int n,k; cin >> n >> k;
	while(n && k){
		
		point p1, p2, fp; cin >> fp.x >> fp.y;
		p1=fp;
		int cnt=1;
		///////initialize ///////////
		for(int i=1 ; i<n ; i++){	
			cin >> p2.x >> p2.y;
			if(p1.x == p2.x){
				for(int i=min(p1.y, p2.y) ; i<=max(p1.y, p2.y) ; i++)
					if(a[p1.x][i]==0) a[p1.x][i]=cnt++;
			}else{
				for(int i=min(p1.x, p2.x) ; i<=max(p1.x, p2.x) ; i++)
					if(a[i][p1.y]==0) a[i][p1.y]=cnt++;
			}
			p1=p2;
		}
		if(fp.x == p2.x){
			for(int i=min(fp.y, p2.y) ; i<=max(fp.y, p2.y) ; i++)
				if(a[fp.x][i]==0) a[fp.x][i]=cnt++;
		}else{
			for(int i=min(fp.x, p2.x) ; i<=max(fp.x, p2.x) ; i++)
				if(a[i][fp.y]==0) a[i][fp.y]=cnt++;
		}
		/////////////////
		cin >> p1.x >> p1.y;
		for(int i=1 ; i<k ; i++){
			cin >> p2.x >> p2.y;
			if(p1.x == p2.x){
				for(int i=p1.x+1 ;1; i++){
					if(a[i][p1.y]==0 || a[i][p2.y]==0)
						b[i-1][min(p1.y,p2.y)]=1;
					else{
						b[i-1][min(p1.y,p2.y)]=1;
						break;
					}
				}
				for(int i=p1.x-1 ;1; i--){
					if(a[i][p1.y]==0 || a[i][p2.y]==0)
						b[i][min(p1.y,p2.y)]=1;
					else{
						b[i-1][min(p1.y,p2.y)]=1;
						break;
					}
				}
			}else{
				for(int i=p1.y+1 ;1; i++){
					if(a[p1.x][i]==0 || a[p2.x][i]==0)
						b[min(p1.x,p2.x)][i]=1;
					else{
						b[min(p1.x,p2.x)][i]=1;
						break;
					}
				}
				for(int i=p1.y-1 ;1; i--){
					if(a[p1.x][i]==0 || a[p2.x][i]==0)
						b[min(p1.x,p2.x)][i]=1;
					else{
						b[min(p1.x,p2.x)][i]=1;
						break;
					}
				}
			}
			p1=p2;
		}
		int ans=0;
		for(int i=0 ; i<600 ; i++)
			for(int j=0 ; j<600 ; j++)
				ans+=b[i][j];
		cout << ans << endl;
		cin >> n >> k;
	}	
}