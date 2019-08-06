//splitting an array into odd and even elements using quickSort method.
#include<bits/stdc++.h>
using namespace std;
int main()
{
int arr[]={1,2,3,4,5,6,7,8,9,10};
int size = sizeof(arr)/sizeof(arr[0]);
int i=-1;
for(int j=0;j<size;j++)
    {
    if(arr[j]&1==0)
        {
        i++;
        }
    if(arr[j]&1)
        {
        i++;
        swap(arr[j],arr[i]);
        }
    }
for(int i=0;i<size;i++)
    cout<<arr[i]<<" ";cout<<endl;
}