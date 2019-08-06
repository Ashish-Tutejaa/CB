#include<iostream>
#include<stack>
using namespace std;
string converter(int n)
    {
    string temp;
    if(n==0)
        {
        cout<<"FINAl"<<temp<<endl;
        return temp;
        }

    char dummy = (char)('0'+n%10);
    temp+=dummy;
      cout<<"TEMP"<<temp<<endl;
    temp+=converter(n/10);
    }
int main()
{
int n;
cin>>n;
stack<char> stacky;

cout<<converter(n)<<endl;
}