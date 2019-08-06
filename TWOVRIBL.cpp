#include<iostream>
#include<math.h>
using namespace std;
int counter = 0;
int moves(int x,int y,int posInt,int key)
    {
    
    if(x==key)
        return 1;
    if(x>key)
        {
        return -1;
        }
    for(int i=x;i<=key;i++)
        {
        while(i*i<=y)
        i++;
    int temp = y+(i*i);
    int newPosInt = ceil(sqrt(temp));
    // cout<<"NEWPOSINT: "<<newPosInt<<endl;
    int answer = moves(i,temp,newPosInt,key);
    // if(answer==-1)
    //     counter--;
        if(answer==1)
            {
            // cout<<"CORRECT HERE:-"<<"X: "<<i<<" Y: "<<temp<<" posINT: "<<newPosInt<<" key: "<<key<<endl;  
            counter++;
            return 1;
            }
        }
    }
int main()
{
int testCases;
cin>>testCases;
while(testCases--)
    {
    counter =0 ;
    int n;
    cin>>n;
    int x = 0;
    int y = 0;
    int posInt = 1;
    moves(x,y,posInt,n);
    cout<<counter<<endl;
    }
}