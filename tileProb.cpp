#include<iostream>
using namespace std;
int answer(int n,int m)
	{
	if(n==1)
		return 1;
	if(n==m)
		return m;
	return answer(n-1,m)+answer(n-m,m);
	}
int main()
{
int testCases;
cin>>testCases;
while(testCases--)
	{
	int n,m;
	cin>>n>>m;
	cout<<answer(n,m)<<endl;
	}
}