//a to the power of n
#include<iostream>
using namespace std;
int power (int a,int b){
    if(b == 0) return 1;
    int x = 1;
    x = power(a,b>>1);
    x *= x;
    if(b%2) x *= a;
    return x;
}
int main()
{
int a,b;cin>>a>>b;
cout<<power(a,b)<<endl;
}

