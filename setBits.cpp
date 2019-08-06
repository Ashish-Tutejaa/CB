#include<bits/stdc++.h>
using namespace std;
int main()
{
int testCases;
cin>>testCases;
while(testCases--)
    {
    int n;
    cin>>n;
    int counter = 0 ;
    int temp = 1;
    while(temp<=n)
        {
        // cout<<counter<<endl;
        bool check = n&(temp);
        temp = temp<<1;
        if(check)
        counter++;
        }
    cout<<counter<<endl;
    }
}