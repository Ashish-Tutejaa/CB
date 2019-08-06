#include<iostream>
using namespace std;
int main()
{
int prev;
for(int i = 0;i<9;i++)
    {
    if(i==0 or i==8)
        {
        for(int j = 0;j<3;j++)
            {
            cout<<" ";
            }
        for(int k = 0;k<3;k++)
            cout<<"*";
        for(int j = 0;j<3;j++)
            {
            cout<<" ";
            }
        cout<<endl;
        continue;
        }
    int sub = 3-i;
    int add = 3+(2*(i-1));
    if(i>=6)
        {
        sub = i-6+1;
        add = prev-(2*(i-5));
        }
    if(sub<=0)
        {
        sub = 0;
        add = 7;
        }
    for(int j = 0;j<sub;j++)
        cout<<" ";
    cout<<"*";
    for(int j = 0;j<add;j++)
        cout<<" ";
    cout<<"*";
    for(int j = 0;j<sub;j++)
        cout<<" ";
    cout<<endl;
    if(i<6)
        prev = add;
    }
}