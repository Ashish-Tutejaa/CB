//tiling problem 4xn
#include<iostream>
using namespace std;
int counter=0;
int tiler(int n)
    {
    if(n==1)return 1;
    if(n==4)return 2;
    int temp =  tiler(n-1);
    if(n>=4)temp+= tiler(n-4);
    return temp;
    }
int main()
{
int n;
cin>>n;
cout<<tiler(n)<<endl;
}