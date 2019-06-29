//XOR of all subarrays
#include<iostream>
using namespace std;
int main()
{
int arr[]={3,8,13};
int n = sizeof(arr)/sizeof(int);
int finalSum = 0;
int sum = 0;
for(int i=0;i<n;i++)
    {
    for(int j=i;j<=n;j++)
        {
        for(int k=i;k<j;k++)
            {
            sum^=arr[k];
            }
        finalSum+=sum;
        sum=0;
        }
    }
cout<<finalSum<<endl;
}