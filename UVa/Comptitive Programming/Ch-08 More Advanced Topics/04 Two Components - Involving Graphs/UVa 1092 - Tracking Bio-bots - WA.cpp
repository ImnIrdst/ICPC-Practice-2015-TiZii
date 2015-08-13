#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

typedef long long int64;

struct Wall{ int x1, x2, y;
	Wall(int x1=0, int x2=0, int y=0)
		:x1(x1), x2(x2), y(y) {}
};

const int MAXW = 1e3+110;

int y[MAXW], x[MAXW*2]; Wall walls[MAXW];
int64 contx[MAXW*4], conty[MAXW*4], grid[MAXW*4][MAXW*4], passo=1;

int main(){
	int m, n, w, cs=1;
	while(cin >> m >> n >> w && (m||n||w)){
		if(w==0){ cout << "Case " << cs++ << ": 0" << endl; continue; }
		int ny=0, nx=0, cx=0, cy=0; 
		int x1, y1, x2, y2;//, ans=0;
		for(int i=0 ; i<w ; i++) {
			cin >> x1 >> y1 >> x2 >> y2;
			walls[i]=Wall(x1,x2,y2);
			y[ny++] = y2; x[nx++]=x1; x[nx++]=x2;
		}
		x[nx++] = -1; x[nx++] = n;
		y[ny++] = -1; y[ny++] = m;
		sort(x, x+nx); sort(y, y+ny);
		nx=unique(x,x+nx)-x; ny=unique(y,y+ny)-y;

		map<int64, int64> mapx, mapy;
		for(int i=1 ; i<nx ; i++){
			if(i > 0 && (x[i-1] < x[i]-1))
				contx[cx] = x[i]-x[i-1]-1, cx++;
			if(x[i] == n) continue;
			contx[cx] = (i%2==0 ? x[i]-x[i-1] : 1);
			mapx[x[i]] = cx++;
		}
		for(int i=1 ; i<ny ; i++){
			if(i > 0 && (y[i-1] < y[i]-1)) 
				conty[cy] = y[i]-y[i-1]-1, cy++;
			if(y[i] == m) continue;
			conty[cy] = (i%2==0 ? y[i]-y[i-1] : 1);
			mapy[y[i]] = cy++;
		}
		for(int i=0 ; i<w ; i++){
			int mpy = mapy[walls[i].y];
			for(int j=mapx[walls[i].x1] ; j<=mapx[walls[i].x2] ; j++){
				grid[mpy][j]=passo;
			}
		}
		for(int i=0 ; i<cx ; i++)  grid[cy][i]=passo;
		for(int i=0 ; i<cy-1; i++) grid[i][cx]=passo;

		int64 ans=0;
		for(int j=cx-1 ; j>=0 ; j--){
			for(int i=cy-1 ; i>=0 ; i--){
				if(grid[i][j] != passo && grid[i+1][j] == passo && grid[i][j+1] == passo){
					grid[i][j] = passo; ans += contx[j]*conty[i];
				}
			}
		}
		cout << "Case " << cs++ << ": " << ans << endl; passo++;
	}
}

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Rect{
	int x1, y1, x2, y2;
	Rect(int xx1=0, int yy1=0, int xx2=0, int yy2=0){
		x1 = min(xx1, xx2); x2 = max(xx1, xx2);
		y1 = min(yy1, yy2); y2 = max(yy1, yy2);
	}
	int area(){
		return (x2-x1)*(y2-y1);
	}
	Rect intersect(const Rect& r2){
		const Rect& r1 = *this;
		if(r1.x1 >= r2.x2 || r1.x2 <= r2.x1 || r1.y1 >= r2.y2 || r1.y2 <= r2.y1) return Rect(-1);
		return Rect(max(r1.x1, r2.x1), max(r1.y1, r2.y1), min(r1.x2, r2.x2), min(r1.y2, r2.y2));
	}
	bool operator==(const Rect& r2){
		const Rect& r1 = *this;
		if(r1.x1 == r2.x1 && r1.y1 == r2.y1 && r1.x2 == r2.x2 && r1.y2 == r2.y2) return true; else return false;
	}
};

typedef vector<Rect> VR; VR rects;

int Union(VR rects){
	if(rects.size() == 0) return 0;
	if(rects.size() == 1) return rects[0].area();
	
	int area = 0;
	Rect taken = rects[0];  
	area=taken.area();
	rects.erase(rects.begin(),rects.begin()+1);
	if(area != 0){
		VR newRects;
		for(int i=0 ; i<rects.size() ; i++){
			Rect tmp = rects[i].intersect(taken);
			if(tmp.x1!=-1) newRects.push_back(tmp);
		}
		area += Union(rects); area -= Union(newRects);
	}
	return area;
}

int main(){
	int m, n, w, cs=1;
	while(cin >> m >> n >> w && (m||n||w)){
		int wallsArea=0; rects.clear();
		int x1, y1, x2, y2;
		for(int i=0 ; i<w ; i++){
			cin >> x1 >> y1 >> x2 >> y2;
			rects.push_back(Rect(x1,y1,x2+1,y2+1)); 
			wallsArea += Rect(x1,y1,x2+1,y2+1).area();
		}
		Rect rgt(n,n+1,0,m); rects.push_back(rgt); // right
		Rect top(0,n,m,m+1); rects.push_back(top); // top
		wallsArea += n+m;

		int ii=0;
		while(ii<rects.size()){
			Rect cur = rects[ii];
			for(int i=0 ; i<ii ; i++){
				Rect old = rects[i];
				if((cur==rgt && old==top) || (cur==top && old==rgt)) continue;
				if(cur.x1 < old.x1 && old.x1 <= cur.x2){
					if(old.y1 < cur.y1 && cur.y1 <= old.y2){
						rects.push_back(Rect(cur.x1, cur.y1, old.x1 ,old.y1));
					}
				}
				if(old.x1 < cur.x1 && cur.x1 <= old.x2){
					if(cur.y1 < old.y1 && old.y1 <= cur.y2){
						rects.push_back(Rect(cur.x1, cur.y1, old.x1 ,old.y1));
					}
				}
			}
			ii++;
		}

		int newWallArea = Union(rects);
		cout << "Case " << cs++ << ": " << newWallArea-wallsArea << endl;
	}
}