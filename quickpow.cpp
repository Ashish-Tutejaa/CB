#include<iostream>
#include<math.h>
using namespace std;
int main()
{
int testCases;
cin>>testCases;
while(testCases--)
    {
   long long int a,n,p;
cin>>a>>n>>p;
//break down power into binary code.
long long int answer=1;
long long int dummy = 1;
long long int i=0;
    while(1)
        {
        if(i>=n)
            break;
        long long int temp = ((1<<i)&n);
        cout<<"TEMP:"<<temp<<" ";
        if(temp!=0)
            {
    
            int dummy =  pow(a,temp);
            cout<<"NOT MODDED"<<dummy<<endl;
            dummy = dummy % p;
            cout<<"MODDED: "<<dummy<<endl;
            answer*=dummy;
            }
        i++;
        }
    cout<<"ANSWER"<<answer<<endl;
    }
}