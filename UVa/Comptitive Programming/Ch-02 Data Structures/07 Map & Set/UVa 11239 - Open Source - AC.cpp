#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

typedef set<string> setstr ;
typedef map<string, setstr > mapss;
typedef map<string, int>     mapsi;
typedef pair<int , string>   psi;

bool cmp(const psi &a,const psi &b){
    if(a.first!=b.first) return a.first  > b.first;
    if(a.first==b.first) return a.second < b.second;
}

int main(){
    string str; bool terminate=0;
    while(!terminate){
        string lastprj; mapss mpss; mapsi mpsi;
        while(getline(cin, str)){
            if(str[0]=='1') break;
            if(str[0]=='0'){ terminate=1; break; }
            if(str[0]>='A' && str[0]<='Z') mpss[str]=setstr(), lastprj=str;
            if(str[0]>='a' && str[0]<='z') if(!mpss[lastprj].count(str))mpss[lastprj].insert(str), mpsi[str]++;
        }
        if(terminate) break;

        mapss::iterator i1; setstr::iterator i2; vector<psi> ans;
        for(i1 = mpss.begin() ; i1!=mpss.end() ; i1++){
            int cnt = 0;
            for(i2 = mpss[i1->first].begin() ; i2!=mpss[i1->first].end() ; i2++){
                if(mpsi[*i2]==1) cnt++;
            }
            ans.push_back(psi(cnt, i1->first));
        }
        sort(ans.begin(), ans.end(), cmp);
        for(int i=0 ; i<ans.size() ; i++){
            cout << ans[i].second << " " << ans[i].first << endl;
        }
    }
}
