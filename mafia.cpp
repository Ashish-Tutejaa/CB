#include<iostream>
using namespace std;
bool flag =0;
long long int counter=0;
long long int finder(long long int n,long long int moves, long long int prev,long long int box,long long int k,long long int eaten)
    {
    if(!flag)
        {
        // cout<<"BOXY"<<endl;
    //base case
    if(moves==n)
        {
        if(box==k)
            {
            if(!flag)
                {
                counter = eaten;
                flag=true;
                }
            }
        return 0;
        }
    //special case
    if(moves==0)
        {
        finder(n,moves+1,prev+1,box+1,k,eaten);
        return 0;
        }
    //rec case
         long long int temp = prev+1;
    finder(n,moves+1,temp,box+temp,k,eaten);
    if(box>0)
    finder(n,moves+1,prev,box-1,k,eaten+1);
        }
        
    return 0;
    }
int main()
{
long long int n,k;
cin>>n>>k;
finder(n,0,0,0,k,0);
cout<<counter<<endl;
}