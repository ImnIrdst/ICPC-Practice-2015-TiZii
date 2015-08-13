#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int o[8], n;// order of landing
int begin[8], end[8];

int valid(int gap){
    int last=begin[o[0]];
    for(int i=0 ; i<n ; i++){
        int cur = last + gap;
        if(cur <= end[o[i]]) last = max(cur,begin[o[i]]);
        else return 0;
    }
    return (last<=end[o[n-1]]);
}

int main(){
    while(cin >> n && n){
        for(int i=0 ; i<n ; i++){
            cin >> begin[i] >> end[i]; 
            begin[i]*=60; end[i]*=60; o[i]=i;
        }
        int ans = -1;
        do{
            int lo=0 , hi=1440*60, mid;
            while(lo<hi){
                mid = (lo+hi)/2;
                if(valid(mid)) lo=mid; else hi=mid-1;
            }
            ans = max(ans,lo);
        }while(next_permutation(o,o+8));
    }
}