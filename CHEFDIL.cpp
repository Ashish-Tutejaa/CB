#include<iostream>
using namespace std;
bool recur(int * arr,int start,int end,int alls)
    {
    //base case
    if(alls==0)
        {
        return true;
        }
    //rec case
    bool check = false;
    for(int i = start;i<end;i++)
        {
        int temp = alls;
        if(arr[i]==1)
            {
            arr[i] = -1;
            if((i-1)>=0)
                {
                if(arr[i-1]>=0)
                    arr[i-1]^=1;
                }
            if((i+1)<end)
                {
                if(arr[i+1]>=0)
                arr[i+1]^=1;
                }
            temp--;
            check = recur(arr,start,end,temp);
            arr[i] = 1;
            if((i-1)>=0)
                {
                arr[i-1]^=1;
                }
            if((i+1)<end)
                {
                arr[i+1]^=1;
                }
            if(check)
                return check;
            }
        }
    return false;
    }
int main()
{
int testCases;
cin>>testCases;
while(testCases--)
    {
    string str;
    cin>>str;
    int arr[str.size()];
    for(int i = 0;i<str.size();i++)
        arr[i] = str[i]-'0';
    int countOnes =0 ;
    for(int i = 0;i<str.size();i++)
        if(arr[i]==1)
            countOnes++;
    if(countOnes==0)
        {
        cout<<"LOSE"<<endl;
        continue;
        }
    if(recur(arr,0,str.size(),str.size()))
        cout<<"WIN"<<endl;
    else
        cout<<"LOSE"<<endl;
    
    }
}