//tiling problem 4xn
#include<iostream>
using namespace std;
int counter=0;
void tiler(int n)
    {
    if(n<=0)
        {
        counter++;
        return;
        }
    if(n>=4)
        tiler(n-4);
    tiler(n-1);
    }
int main()
{
int n;
cin>>n;
tiler(n);
cout<<counter<<endl;
}