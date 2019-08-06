#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool compare(char a,char b)
    {
    if(a!='x' && b=='x')
        return true;
    else return false;
    }
int main()
{
string temp;
cin>>temp;
// solver(temp,0,temp.size());
sort(temp.begin(),temp.end(),compare);
cout<<temp<<endl;
}