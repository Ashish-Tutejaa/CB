#include<iostream>
#include<math.h>
using namespace std;
int bsearch(int arr[],int key,int start,int end)
    {
    if(start>end)
        return -1;
    int mid = ceil(start + (end-start)/2);
    if(arr[mid]==key)
        return mid;
    if(arr[mid]<key)
        {
        return bsearch(arr,key,mid+1,end);
        }
    if(arr[mid]>key)
        {
        return bsearch(arr,key,start,mid-1);
        }
    }
int main()
{
int testCases;
cin>>testCases;
while(testCases--)
    {
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0;i<n;i++)
        cin>>arr[i];
    int search;
    cin>>search;
    cout<<bsearch(arr,search,0,n-1)<<endl;
    }
}