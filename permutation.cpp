#include<iostream>
using namespace std;
void perm(string str, int k,int len)
    {
    cout<<str<<endl;
    }
int main()
{
int testCases;
cin>>testCases;
while(testCases--)
    {
    string str;
    cin>>str;
    perm(str,0,str.length());
    }
}