#include <iostream>
#include <cstdio>
#include <deque>

using namespace std;

int main(){
    int n;
    while(cin >> n && n){
        deque<int> dq; bool first = 1;
        for(int i=1 ; i<=n ; i++) dq.push_back(i);
        printf("Discarded cards:");
        while(dq.size()>1){
            if(!first) printf(","); first=0;
            printf(" %d", dq.front()); dq.pop_front();
            dq.push_back(dq.front());  dq.pop_front();
        }
        printf("\n");
        printf("Remaining card: %d\n", dq.front());
    }
}