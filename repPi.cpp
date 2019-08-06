#include<iostream>
using namespace std;
string replace(string conv,int front,int size)
    {
    string temp;
    //base case
    if(front==size)
        return "";
    //rec case
    if(conv[front]=='p' and conv[front+1]=='i')
        {
        temp = "3.14";
        temp+=replace(conv,front+2,size);
        }
    else
        {
        temp=conv[front];
        temp+=replace(conv,front+1,size);
        }
    return temp;
    }
int main()
{
int testCases;
cin>>testCases;
while(testCases--)
    {
    string temp;
    cin>>temp;
    cout<<replace(temp,0,temp.size())<<endl;
    }
}