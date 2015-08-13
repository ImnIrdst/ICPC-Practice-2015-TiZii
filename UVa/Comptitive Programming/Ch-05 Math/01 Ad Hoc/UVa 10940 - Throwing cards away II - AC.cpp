#include <iostream>
#include <deque>

using namespace std;

const int MAX = 500000+10;

int ans[MAX] = {0}; 

int main(){
	ans[1]=1; ans[2]=2;
	for (int i = 2; i < MAX; i *= 2){
        ans[i] = i; ans[i + 1] = 2;
    }
    for (int i = 2; i < MAX ; i++)
    {
        if (!ans[i])
            ans[i] = 2 + ans[i - 1];
    }

	int n; 
	while(cin >> n && n) cout << ans[n] << endl;
}