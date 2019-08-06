#include<iostream>
using namespace std;

void dec(int n)
    {
    if(n==0)
        {cout<<endl;return;}
    cout<<n<<" ";
    //just chaning the order of the cout statement can change from increasing to decreasing order.
    //the difference is that in the decreasing function we print whilst building the call stack
    //and in the increasing function we print whilst releasing the call stack.
    return dec(n-1);
    }
void inc(int n,int temp)
    {
    //base case
    if(temp > n)
        {cout<<endl;
        return ;
        }
    cout<<temp<<" ";
    return inc(n,temp+1);
    }
    void helper(int n)
    {
    inc(n,1);
    dec(n);
    return ;
    }
int main()
{
int n;
cin>>n;
helper(n);
}