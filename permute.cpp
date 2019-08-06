#include<iostream>
using namespace std;
void perm(string str, int k,int len)
    {
    if(k==len)
        cout<<str<<endl;
    for(int i=k;i<=len;i++)
        {
        swap(str[i],str[k]);
        perm(str,k+1,len);
        // swap(str[i],str[k]);
        }
    }
int main()
{
int testCases;
cin>>testCases;
while(testCases--)
    {
    string str;
    cin>>str;
    perm(str,0,str.length()-1);
    }
}