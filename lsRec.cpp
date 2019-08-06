//linear search using recursion
#include<iostream>
using namespace std;
int finder(int *arr,int key,int i,int size)
    {
    if(i==(size-1))
        {
        return -1;
        }
    if(arr[i]==key)
        return i;
    return finder(arr,key,i+1,size);
    }
int main()
{
int arr[]={1,3,2,6,8,0};
int size = sizeof(arr)/sizeof(arr[0]);
int key;cin>>key;
cout<<finder(arr,key,0,size)<<endl;
}