//SubArraySumK
#include<iostream>
using namespace std;
int main()
{
int k;cin>>k;
int arr[]={2,3,5,7,1,6,3,4,8,2};
int size=sizeof(arr)/sizeof(int);
int cumSum[size]={};
int temp =0;
for(int i=0;i<size;i++)
    {
    temp+=arr[i];
    cumSum[i]=temp;
    }
for(int i=0;i<size;i++)
    cout<<cumSum[i]<<" ";cout<<endl;
for(int i=0;i<size;i++)
    {
    for(int j=0;j<size;j++)
        {
        int sum = cumSum[j]-cumSum[i-1];
        if(sum==k)
            {
            for(int h = i;h<=j;h++)
                {
                cout<<arr[h]<<" ";
                }cout<<endl;
            }
        }
    }
}