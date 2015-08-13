#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef vector<int> vi;
typedef unsigned long long int64;

int n;

struct state
{
    int g, h; int64 key; vi v;
    int& operator[](int i){ return v[i]; }
    bool operator<(const state s) const { return g+h>s.g+s.h; }
    state operator=(state s){ v=s.v; h=s.h; g=s.g; key=s.key; return s; }
    void init(int gg){
        h=0; g=gg; key=v[0];
        for(int i=1 ; i<n ; i++){
            if(v[i]!=v[i-1]+1) h++;
            key = key * (n+1) + v[i];
        }
        if(v[n-1]!=n) h++;
    }
};

int AStar(state s, int lim){
    priority_queue<state> pq; pq.push(s);
    map<int64,int> mp;
    while(!pq.empty()){
        s = pq.top(); pq.pop();
        if(s.g>lim || 3*s.g + s.h > 3*lim) continue;
        if(mp.count(s.key)){
            if(s.g<=mp[s.key]) mp[s.key]=s.g;
            else continue; 
        } 
        mp[s.key]=s.g;
        if(s.h == 0) return s.g;
        for(int cuts=0 ; cuts<n ; cuts++){ // cuts = cut start
            for(int cute=cuts ; cute<n ; cute++){// cute = cut end
                for(int paste=0 ; paste<=n ; paste++){
                    if(paste < cuts){
                        state New;
                        for(int i=0     ; i<paste ; i++) New.v.push_back(s[i]);
                        for(int i=cuts  ; i<cute+1; i++) New.v.push_back(s[i]);
                        for(int i=paste ; i<cuts  ; i++) New.v.push_back(s[i]);
                        for(int i=cute+1; i<n     ; i++) New.v.push_back(s[i]);
                        New.init(s.g+1); if(New.g<=lim && !mp.count(New.key)) pq.push(New);
                    }
                    if(paste > cute){
                        state New;
                        for(int i=0     ; i<cuts  ; i++) New.v.push_back(s[i]);
                        for(int i=cute+1; i<paste ; i++) New.v.push_back(s[i]);
                        for(int i=cuts  ; i<cute+1; i++) New.v.push_back(s[i]);
                        for(int i=paste ; i<n     ; i++) New.v.push_back(s[i]);
                        New.init(s.g+1); if(New.g<=lim && !mp.count(New.key)) pq.push(New);
                    }
                }
            }
        }
    }
    return -1;
}

int IDA(state& source){
    int ans=-1;
    for(int lim=0 ; lim<n && ans==-1 ; lim++){
        ans = AStar(source, lim); 
    }
    return ans;
}

int main(){
    int cs=1;
    while(cin >> n && n){
        int tmp; state s;
        for(int i=0 ; i<n ; i++){
            cin >> tmp; s.v.push_back(tmp);
        }s.init(0);
        printf("Case %d: %d\n", cs++, IDA(s));
    }
}