#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef vector<int> vi;
typedef unsigned long long int64;

int dx[4][4]={
    {-3,-1,+4,-4},
    {+1,+3,+4,-4},
    {+1,-1,+4,-4},
    {+1,-1,+4,-4},
}, n;

bool inRange(int x){ return (x<n && x>0); }

int Manhatan(int i, int j) {
   int a = abs(i/4 - j/4);   // need moves to the same roll
   int b = abs(i%4 - j%4);
   if (b == 3) b = 1;  // in the same roll, distance 3 == 1,
   return a + b;
}

struct state
{
    int g, h; string key; vi v;
    int& operator[](int i){ return v[i]; }
    bool operator<(const state s) const { return g+h>s.g+s.h; }
    state operator=(state s){ v=s.v; h=s.h; g=s.g; key=s.key; return s; }
    void init(int gg){
        h=0; g=gg; key="";
        for(int i=0 ; i<n ; i++){
            if(v[i]!=i) h++;
            key += (char)('0'+v[i]);
        }
        //h*=2;
        //if(h>1) h--;
    }
};

int kingPos(vector<int>& v){
    for(int i=1 ; i<n ; i++){
        if(v[i]==1) return i;
    }
}

int ans;

int DFS(state s, int lim){
    queue<state> q; q.push(s);
    map<string,int> mp; int ret=1e9;
    while(!q.empty()){
        s = q.front(); q.pop();
        if(s.g+s.h>lim ){ ret=min(ret,s.g+s.h); continue;}
        if(mp.count(s.key)){
            if(s.g<=mp[s.key]) mp[s.key]=s.g;
            else continue; 
        } 
        //cout << s.key << " " << s.g << " " << s.h << " " << s.g+s.h << endl;
        mp[s.key]=s.g;
        if(s.h == 0){ ans = s.g; break; }
        int k = kingPos(s.v);
        for(int i=0 ; i<4 ; i++){
            if(inRange(k+dx[k%4][i])){
                state tmp; tmp.v=s.v; 
                swap(tmp.v[k],tmp.v[k+dx[k%4][i]]);
                tmp.init(s.g+1); q.push(tmp);
            }
        }
    }
    return ret;
}

int IDA(state& source){
    for(int lim=0 ; lim<400 && ans==-1 ; lim++){
        lim = DFS(source, lim);  //cout << lim << endl;
    }
    return ans;
}

int main(){
    int cs=1;
    while(cin >> n && n){ n++; ans=-1;
        int tmp; state s; s.v.push_back(0);
        for(int i=1 ; i<n ; i++){
            cin >> tmp; s.v.push_back(tmp);
        }s.init(0);
        printf("Set %d:\n%d\n", cs++, IDA(s));
    }
}