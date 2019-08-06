#include<iostream>
#include<unordered_map>
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
    string one = temp+"()";
    string two = "(" + temp + ")";
    string three = "()"+ temp;
    fxn(n-1,one);
    fxn(n-1,two);
    fxn(n-1,three);
    return ;
    }
int main()
{
int testCases;
cin>>testCases;
while(testCases--)
    {
    int n;
    cin>>n;
    fxn(n,"");
    }
}