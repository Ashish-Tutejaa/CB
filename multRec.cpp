//We must multiple two signed integers using recursion without using the *.
#include<iostream>
#include<math.h>
using namespace std;
int mult(int a,int b)
    {
    int sign;
    //neg = false, pos = true;
    if((a<=0 and b<=0) or (a>=0 and b>=0))
        {
        sign =1;
        }
    else {
        sign = -1;}
    //base case
    if(b == 0)
        return 0;
    //rec case
    a= abs(a);
    b= abs(b);
    int temp = a+mult(a,b-1);
    if(sign<0)
        {
        return -temp;
        }
    else
    {
        return temp;
    }
    
    }
int main()
{
int a,b;
cin>>a>>b;
cout<<mult(a,b)<<endl;
}