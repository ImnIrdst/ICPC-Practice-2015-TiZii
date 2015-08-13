#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

const int MAX = 300 + 10;

struct pt{ int x, y, id; pt(){}
	pt(int x, int y):x(x), y(y){id=-1;}
	//if(make_pair(x,y)<make_pair(b.x,b.y)) return id<b.id;
	bool operator<(const pt b){
		if(make_pair(x,y)==make_pair(b.x,b.y)) return id<b.id;
		else return make_pair(x,y)<make_pair(b.x,b.y);
	}
};

int cross(pt a, pt b, pt c){
	return (a.y-b.y)*(b.x-c.x) - (a.x-b.x)*(b.y-c.y);
}

int main(){
	vector<pt> vpt; pt p;
	while(cin >> p.x >> p.y && (p.x || p.y)){
		vpt.clear(); vpt.push_back(p); int id;
		while(cin >> p.x >> p.y && (p.x || p.y)){
			vpt.push_back(p);
		}
		sort(vpt.begin(), vpt.end());
		for(int i=0 ; i<vpt.size() ; i++){
			vpt[i].id = i;
		}

		vector<int> ans;  int found=0, first=1;
		int vis[MAX][MAX]={0}, n=vpt.size();
		for(int i=0 ; i<n ; i++){
			for(int j=i+1 ; j<n ; j++){
				if(!vis[i][j]){ vis[i][j]=1;
					ans.clear(); ans.push_back(i); ans.push_back(j);
					for(int k = j+1 ; k<n ; k++){
						if(cross(vpt[i],vpt[j],vpt[k])==0){
							ans.push_back(k);
						}
					}
					if(ans.size() >= 3 ){
						if(first){
							printf("The following lines were found:\n");
						}
						first = false;

						found = true;
						for(int ii=0 ; ii<ans.size() ; ii++){
							for(int jj=0 ; jj<ans.size() ; jj++){
								vis[ans[ii]][ans[jj]] = 1;
							}
							printf("(%4d,%4d)", vpt[ans[ii]].x, vpt[ans[ii]].y);
						}
						printf("\n");
					}
				}
			}
		}
		if(!found) printf("No lines were found\n");
	}
	return 0;
}