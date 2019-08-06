#include<iostream>
#include<climits>
#include<math.h>
using namespace std;

int main()
{
int testCases;
cin>>testCases;
while(testCases--)
    {
    int arr[5]={1,2,3,4,5};
    int tempHigh = arr[4];
    for(int i = 4-1;i>=0;i--)
        {
        arr[i+1] = arr[i];
        }
    cout<<"1"<<endl;
    arr[0] = tempHigh;
    for(int j = 0;j<5;j++)
        cout<<arr[j]<<" ";cout<<endl;
    tempHigh = arr[0];
        int tempLow = arr[0+1];
        for(int i = 0+1;i<=4;i++)
            {
            arr[i-1]=arr[i];
            }

        for(int i = 1;i<4;i++)
            {
            arr[i-1]=arr[i];
            }

        arr[4-1]=tempHigh;
        arr[4]=tempLow;
         for(int j = 0;j<5;j++)
        cout<<arr[j]<<" ";cout<<endl;
    }
}