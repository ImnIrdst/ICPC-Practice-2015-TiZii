#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct p{
	p(){}
	p(int a, int b , int c){i=a; x=b; y=c;}
	int i,x,y;
};

int dist(p a, p b){
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

int main(){
	int m,n; cin >> m >> n;
	while(m && n){
		vector<p> b,w;
		int markb[50]={0}, markw[50]={0}, marks[50]={0};
		p nodes[50];
		
		for(int i=0 ; i<n ; i++) cin >> nodes[i].x >> nodes[i].y;
		for(int i=0 ; i<m ; i++){
			int x,y; char c; cin >> x >> y >> c;
			if(c=='B'){
				if(markb[x]==0){ 
					b.push_back(p(x,nodes[x].x,nodes[x].y)); markb[x]=1;}
				if(markb[y]==0){ 
					b.push_back(p(y,nodes[y].x,nodes[y].y)); markb[y]=1;}
			}
			if(c=='W'){
				if(markw[x]==0){ 
					w.push_back(p(x,nodes[x].x,nodes[x].y)); markw[x]=1;}
				if(markw[y]==0){ 
					w.push_back(p(y,nodes[y].x,nodes[y].y)); markw[y]=1;}
			}
		}
		int x,y; cin >> x >> y;
		//correct
		int mid=10000/2, flag=0, ans;
		for(int l=1, r=10000 ; r>l ; mid=(r-l)/2){
			for(int i=0 ; i<w.size() ; i++){
				for(int j=0 ; j<b.size() ; j++){
					if(dist(w[i],b[j]) < mid){
						marks[j]=1;
						flag=1;
					}
				}
				if(flag==0) break;
			}
			int flag2=0;
			for(int j=0 ; j<b.size() ; j++){
				if(marks[b[j].i]==0){
					flag2=1;
					break;
				}
			}
			if(flag2==1 || flag==0) r=mid;
			else{ l=mid; ans=mid;}
			ans=mid;
		}
		cout << ans << endl;
		cin >> m >> n;
	}
}
