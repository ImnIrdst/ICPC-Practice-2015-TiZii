#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> score; set<int> st; set<int>::iterator it;

int main(){
	int n; st.insert(50);
	for(int i=0 ; i<=20 ; i++)
			st.insert(i), st.insert(i*2), st.insert(i*3);
	for(it=st.begin() ; it!=st.end() ; it++) score.push_back(*it);
	while(cin >> n && n>0){
		int comb = 0, perm = 0;
		for(int D1=0 ; D1<score.size() ; D1++){
			for(int D2=D1 ; D2<score.size() ; D2++){ if(score[D1]+score[D2]<=n)
				for(int D3=D2 ; D3<score.size() ; D3++) if(score[D1]+score[D2]+score[D3]==n){
					st.clear(); st.insert(score[D1]); 
					st.insert(score[D2]); st.insert(score[D3]);
					if(st.size()==1) perm+=1, comb++;
					if(st.size()==2) perm+=3, comb++;
					if(st.size()==3) perm+=6, comb++;
				}
			}
		}
		if(comb!=0)
			cout << "NUMBER OF COMBINATIONS THAT SCORES " << n << " IS " << comb << "." << endl,
			cout << "NUMBER OF PERMUTATIONS THAT SCORES " << n << " IS " << perm << "." << endl,
			cout << "**********************************************************************" << endl;
		else
			cout << "THE SCORE OF " << n << " CANNOT BE MADE WITH THREE DARTS." << endl,
			cout << "**********************************************************************" << endl;
	}
	cout << "END OF OUTPUT" << endl;
}