//Checking Sorted Using Recursion
#include<iostream>
using namespace std;
int checker(int *arr,int size)
    {
     if(size==1)
        return 1;
    if(arr[size-2]>arr[size-1])
        return 0;
    checker(arr,size-1);
    }
int main()
{
int arr[]={1,2,2,3,4,5,6,7};
int size = sizeof(arr)/sizeof(int);
int temp = checker(arr,size);
if(temp)
    cout<<"sorted"<<endl;
else
    cout<<"nah mate"<<endl;
}
