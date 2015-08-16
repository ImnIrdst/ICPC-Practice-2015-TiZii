#include <list>
#include <iostream>

using namespace std;

int main(){
	int n, m, k;
	while(cin >> n >> m >> k && (n||m||k)){
		cout << (m%2 ? "Keka" : "Gared" ) << endl;	
	}
}
// TLE
//#include <list>
//#include <iostream>
//
//using namespace std;
//
////void printlist(list<char>& lst){
////	list<char>::iterator it;
////	for(it=lst.begin() ; it!=lst.end() ; it++) 
////		cout << *it << " "; cout << endl;
////}
//
//int main(){
//	int n, m, k;
//	while(cin >> n >> m >> k && (n||m||k)){
//		list<char> lst; list<char>::iterator it;
//		for(int i=0 ; i<n ; i++) lst.push_back('G');
//		for(int i=0 ; i<m ; i++) lst.push_back('K');
//		
//		//printlist(lst);
//		it = lst.begin();
//		while(lst.size() > 1){
//			for(int i=1 ; i<k ; i++){
//				it++; if(it==lst.end()) it=lst.begin();
//			}
//			char c1 = *it; it=lst.erase(it);  
//			if(it==lst.end()) it=lst.begin();
//			
//			//printlist(lst);
//			for(int i=1 ; i<k ; i++){
//				it++; if(it==lst.end()) it=lst.begin();
//			}
//			char c2 = *it; *it = (c1==c2 ? 'G' : 'K');
//			it++; if(it==lst.end()) it=lst.begin();
//			//printlist(lst);
//		}
//		cout << (*lst.begin()=='K' ? "Keka" : "Gared" ) << endl;
//
//	}
//}