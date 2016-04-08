#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

string subs[1024];
int subnum,N;
struct rect{
    int x1,y1,x2,y2;
    int A;
    int Area(){
        return (y1-y2)*(x2-x1);
    }
}Rects[10];

int Overlap(string R){
    if(R.length()==1) return Rects[R[0]-'0'].Area();
    rect Temp; Temp.x1=-10000; Temp.x2=10000; Temp.y1=10000; Temp.y2=-10000; // Firs I Dont Write Right Number Of Zeros If Front Of 1s;
    for(int i=0 ; i<R.length() ; i++){
        Temp.x1=max(Temp.x1,Rects[R[i]-'0'].x1);
        Temp.y2=max(Temp.y2,Rects[R[i]-'0'].y2);
        Temp.x2=min(Temp.x2,Rects[R[i]-'0'].x2);
        Temp.y1=min(Temp.y1,Rects[R[i]-'0'].y1);
        if(Temp.x1>Temp.x2 || Temp.y1 < Temp.y2) return 0;
    }
    return Temp.Area();
}

int Area(){
    int A=0;
    for(int i=0 ; i<subnum ; i++){
        A+=Overlap(subs[i])*pow(-1.,subs[i].length())*-1;
        //cout << A << endl;
    }
    return A;
}

void subsets(string sub,int i){
    if(i==sub.length()-1){
        if(sub.empty()) return;
        subs[subnum++] = sub;
        return;
    }
    subsets(sub,++i);
    if(i>sub.length()-1 || i<0) return;
    sub.erase(i,1);
    if(sub.empty()) return;
    subsets(sub,--i);
}
bool compare(string a, string b){ return a.length()<b.length(); }
int main(){
    int tc; cin >> tc;
    while(tc--){
        cin >> N;
        for(int i=0 ; i<N ; i++){
            cin >> Rects[i].x1 >> Rects[i].y1 >> Rects[i].x2 >> Rects[i].y2;
        }
        string sub;
        subnum=0;
        for(int i=0 ; i<N ; i++) sub.push_back('0'+i);
        subsets(sub,-1);
        sort(subs,subs+subnum,compare);
        cout << Area() << endl;
    }
}
