#include<iostream>
using namespace std;
string converter(int n,string temp)
    {
    cout<<n<<" "<<n%10<<""<<temp<<endl;
    if(n==0)
        return temp;
    char dummy = n%10;
    temp+=dummy;
    converter(n/10,temp);
    }
int main()
{
int n;
cin>>n;
string temp="";
cout<<converter(n,temp)<<endl;
}