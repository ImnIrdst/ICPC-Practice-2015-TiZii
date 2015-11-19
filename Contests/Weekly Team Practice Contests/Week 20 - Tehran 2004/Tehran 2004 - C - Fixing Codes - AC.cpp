#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <sstream>
#include <set>

using namespace std;

bool per(string u,string v)
{
if(u.size()>v.size())
    return false;
    for(int i=0;i<u.size();i++)
        if(u[i]!=v[i])
                return false;
    return true;

}

long long tav(long long p,long long q){
    if(q==0)
        return 1;
    long long ans=tav(p,q/2);
    ans*=ans;
    if(q%2)
        ans*=p;
    return ans;
}

string tabdil(long long n,int o){
    string s="";
    for(int i=1;i<=o;i++){
        s+=n%2+'0';
        n/=2;
    }
    return s;

}

int main() {
    int tc;
    cin>>tc;
    cin.ignore();
    while(tc--){
            long long ans=0;
        string line, c;
        vector<string> codes;
        getline(cin, line);
        stringstream sstr(line);
        while(sstr >> c)
            codes.push_back(c);
        set <string> x[100];
        string d=codes[codes.size()-1];
        for(int i=0;i<codes.size()-1;i++)
            if(per(d,codes[i])){
            string s="";
            x[0].insert(s);
            int poin=d.size();
            while(poin<codes[i].size()){
                s+=codes[i][poin];
                x[poin-d.size()+1].insert(s);
                poin+=1;

            }
        }

 /*       if(codes.size()==1){
            cout<<1<<endl;
            break;
        }*/
        for(int i=0;i<=50;i++)
            if(x[i].size()<tav(2,i)){
                ans=i;
                int mini=1000;
                for(int j=0;j<tav(2,i);j++)
                    if(!(x[i].count(tabdil(j,i)))){
                        string w=d+tabdil(j,i);
                        int q=0;
                        for(int i=0;i<codes.size()-1;i++)
                            if(per(codes[i],w))
                                q+=1;
                        mini=min(mini,q);
                    }
                ans+=mini;
                break;
            }

        cout<<ans<<endl;
    }


    return 0;
}
