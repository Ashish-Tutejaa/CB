#include<iostream>
using namespace std;
void fxn(int n,string temp)
    {
    //base case
    if(n==0)
        {
        cout<<temp<<endl;
        return ;
        }
    //rec case
    string one,two;
    one = temp;
    one+="()";
    two+="(";
    two+=temp;
    two+=")";
    fxn(n-1,one);
    fxn(n-1,two);
    return;
    }
int main()
{
int testCases;
cin>>testCases;
while(testCases--)
    {
    int n;
    cin>>n;
    string temp;
    fxn(n,temp);
    }
return 0;
}