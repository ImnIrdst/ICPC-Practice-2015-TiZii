#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

struct edge{
    int u,v,w;
}E[100000];

int p[40000];

int cmp(edge a, edge b){
    return a.w < b.w;
}

int find(int a){
    if(a==p[a]) return a;
    else return p[a]=find(p[a]);
}

int merge(int u , int v){
    int U=find(u); int V=find(v);
    if(U==V) return 0;
    p[u]=p[v]=p[U]=p[V]=U;
    return 1;
}

int main(){
    int tc; cin >> tc;
    while(tc--){
        int n,m; cin >> n >> m;
        for(int i=0 ; i<m ; i++){
            cin >> E[i].u >> E[i].v >> E[i].w;
        }
        for(int i=0 ; i<n ; i++) p[i]=i;
        sort(E,E+m,cmp);
        int cost=0; int cnt=1;
        for(int i=0 , j ; i<m ; ){
            set< pair<int,int> > S;
            int tot=0;
            for(j=i ; E[j].w==E[i].w && j<m; j++){
                //cout << E[j].w << " "<< E[i].w << " ";
                if(find(E[j].u)!=find(E[j].v)){
                    S.insert(make_pair(max(find(E[j].u),find(E[j].v)),min(find(E[j].u),find(E[j].v))));
                    tot++;
                }
            }
            int num=0;

            for( i ; i<j ; i++){
                num+=merge(find(E[i].u),find(E[i].v));
            }
            cost+=E[i-1].w*num;
            if(tot==3){
                if(num==1 || num==2 && S.size()==3) cnt=(cnt*3)%1000000007;
                if(num==2 && S.size()==2) cnt=(cnt*2)%1000000007;
            }
            if(tot==2 && num==1) cnt=(cnt*2)%1000000007;
        }
        cout << cost << " " << cnt << endl;
    }
}
