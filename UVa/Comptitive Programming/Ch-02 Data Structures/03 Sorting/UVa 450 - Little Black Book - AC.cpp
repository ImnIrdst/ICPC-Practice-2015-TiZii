#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct emp
{
    string title, fname, lname, address;
    string dept, hphone, wphone, campusBox;
};

int cmp(emp a, emp b){
    return a.lname<b.lname;
}

int main(){
    string line; int n; cin >> n; 
    cin.ignore(); vector<emp> v;
    while(n--){
        string dept; getline(cin, dept); 
        while(getline(cin, line) && line!=""){
            for(int i=0 ; i<line.size() ; i++){
                if(line[i]==',') line[i]='\n';
            }line+='\n';
            stringstream sstr(line); emp e;
            getline(sstr, e.title); getline(sstr, e.fname); getline(sstr, e.lname);
            getline(sstr, e.address); getline(sstr, e.hphone); getline(sstr, e.wphone);
            getline(sstr, e.campusBox); e.dept=dept; v.push_back(e);
        }
    }
    sort(v.begin(), v.end(), cmp);
    for(int i=0 ; i<v.size() ; i++){
        cout << "----------------------------------------" << endl;
        cout << v[i].title << " " << v[i].fname << " " << v[i].lname << endl;
        cout << v[i].address << endl;
        cout << "Department: " << v[i].dept   << endl; 
        cout << "Home Phone: " << v[i].hphone << endl;
        cout << "Work Phone: " << v[i].wphone << endl;
        cout << "Campus Box: " << v[i].campusBox << endl;
    }
}