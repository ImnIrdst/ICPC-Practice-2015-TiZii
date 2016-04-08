#include <fstream>
#include <iostream>

using namespace std;


#define MAXNUMBER 100000

int calc(int a,int m)
{
	long long int s=0;
	int d=10;
	for(int i=1;i<=a;i++)
	{
		int ii=i/d;
		while(ii)
			ii=i/(d*=10);
		s*=d;
		s+=i;
		s%=m;
	}
	return s;
}

int arr[]={2,      8,      26     , 68      ,1052    ,1598    ,2510    ,8166    ,21370   ,73322};

int main()
{
	//for(int i=1;i<=MAXNUMBER;i++)
	//	if(!calc(i,i+1))
	//		cout<<i<<"\t";
	//cout<<endl;
	//return 0;
	//fstream fin("b.in",ios::in);
	//fstream fout("b.out",ios::out);
	int t;
	cin>>t;
	int nArr=sizeof(arr)/sizeof(arr[0]);
	while(t--)
	{
		int i;
		cin>>i;
		int s=0;
		for(int j=0;j<nArr;j++)
			if(arr[j]>i)break;
			else s++;
		cout<<s<<endl;
	}
//	fin.close();
	//fout.close();
}