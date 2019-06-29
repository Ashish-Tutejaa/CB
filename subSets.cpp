//finding all possible subsets
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
string str = "abc";
int n = (1<<str.length());
for(int i=0;i<n;i++)
    {
    for(int j=0;j<n;j++)
        {
        if((i&(1<<j))!=0)
            {
            cout<<str[j]; 
            }
        }cout<<endl;
    }
}