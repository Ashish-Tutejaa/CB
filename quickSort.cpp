#include<bits/stdc++.h>
using namespace std;
int partition(int * arr,int low,int high)
    {
    // if(low<high)
    //     {
        cout<<"PART"<<endl;
    int i=low-1,j;
    //taking high as the pivot
    for(j=low;j<high;j++)
        {
        if(arr[j]<=arr[high])
            {
            i++;
            swap(arr[i],arr[j]);
            }
        }
    swap(arr[i+1],arr[high]);
    return i+1;
        // }    
    }
void quickSort(int * arr,int low,int high)
    {
    cout<<"PARTS: "<<low<<" "<<high<<endl;
    if(low>=high)
        return;
    cout<<"QUICKIE"<<endl;
    int part = partition(arr,low,high);
    quickSort(arr,low,part-1);
    quickSort(arr,part+1,high);
    }
int main()
{
int arr[]={3,1,2,6,5,4};
int size = sizeof(arr)/sizeof(arr[0]);
quickSort(arr,0,size-1);
for(int i=0;i<size;i++)
    cout<<arr[i]<<" ";cout<<endl;
}