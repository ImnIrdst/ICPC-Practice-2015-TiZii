#include <iostream>
#include <functional>
#include <vector>
#include <queue>

using namespace std;

void printMax(priority_queue<int, vector<int>, less<int> > Max){
	while(!Max.empty()) cout << Max.top() << " ", Max.pop();
}

void printMin(priority_queue<int, vector<int>, greater<int> > Min){
	while(!Min.empty()) cout << Min.top() << " ", Min.pop();
}
int main(){
	int tc; cin >> tc;
	while(tc--){
		int n, m, x; cin >> n >> m;
		queue<int> add, get;
		for(int i=0 ; i<n ; i++){ cin >> x; add.push(x); }
		for(int i=0 ; i<m ; i++){ cin >> x; get.push(x); }

		priority_queue<int, vector<int>, greater<int> > Min;
		priority_queue<int, vector<int>, less<   int> > Max;
		
		int i=0;
		while(!add.empty()){
			if(!Min.empty() && add.front() > Max.top())
				Min.push(add.front());
			else
				Max.push(add.front());
			add.pop();
			while(!get.empty() && Max.size()+Min.size() == get.front()){
				while(Max.size() != i){
					if(Max.size() < i)
						Max.push(Min.top()), Min.pop();
					else
						Min.push(Max.top()), Max.pop();
				}
				//cout << "Max: "; printMax(Max); cout << endl;
				//cout << "Min: "; printMin(Min); cout << endl;
				cout << Min.top() << endl; get.pop(); i++;
			}
		}
		if(tc) cout << endl;
	}
}