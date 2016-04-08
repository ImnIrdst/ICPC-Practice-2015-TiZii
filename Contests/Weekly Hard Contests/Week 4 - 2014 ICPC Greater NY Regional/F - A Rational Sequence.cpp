#include <iostream>

using namespace std;

struct frac{
	int numi, deno; bool isLeftChild;
	frac(int numi = 0, int deno = 1, bool isLeftChild = 0)
		:numi(numi), deno(deno), isLeftChild(isLeftChild){}
};

frac getParent(frac a){
	if (a.numi > a.deno) return frac(a.numi - a.deno, a.deno, false);
	if (a.numi < a.deno) return frac(a.numi, a.deno - a.numi, true);
	return frac();
}



int main(){
	int tc;
	cin >> tc;
	while (tc--){
		int p, q, cs; char c;
		cin >> cs >> p >> c >> q ;
		frac ans;
		if (q == 1)
			ans = frac(1, p+q);
		else{
			int m = p / q;
			frac lc(p - (m*q), q);  // leftChild
			frac ca = getParent(lc); // commonAncestor
			frac rc(ca.numi + ca.deno, ca.deno); // rightChild
			ans = frac(rc.numi, rc.deno + (rc.numi*m));
		}
		cout << cs << " " << ans.numi << "/" << ans.deno << endl;
	}
}