#include<iostream>
using namespace std;
void conv(string str,int size,int counter)
    {
    
    conv(str,size,counter+1);
    }
int main()
{
string str = "xpipyhpi";
conv(str,str.length(),0);
}