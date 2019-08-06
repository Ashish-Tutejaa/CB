#include<iostream>
using namespace std;
string converted(string temp,int i,int size)
    {
    string fina;
    fina+=temp[i];
    if(i==(size-1))
    return fina;
    if(temp[i]==temp[i+1])
        fina+='*';
    fina+=converted(temp,i+1,size);
    
    }
int main()
{
string temp;
getline(cin,temp);
string fina;
cout<<converted(temp,0,temp.length())<<endl;
}