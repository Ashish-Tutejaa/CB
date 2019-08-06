#include<iostream>
using namespace std;
int main()
{
int testCases;
cin>>testCases;
while(testCases--)
    {
    string str;
    cin>>str;
    for(int i =0;i<str.length();i++)
        {
        cout<<(int)str[i]<<" ";
        }cout<<endl;
    }
}