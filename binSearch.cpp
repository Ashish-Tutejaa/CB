//Implementing binary search via recursion
#include<iostream>
#include<math.h>
using namespace std;
int binSearch(int *arr,int front,int back,int key)
    {

    // if (back >= front) { 
    //     int middle = front + (back- front) / 2; 
  
    //     // If the element is present at the middle 
    //     // itself 
    //     if (arr[middle] == key) 
    //         return middle; 
  
    //     // If element is smaller than mid, then 
    //     // it can only be present in left subarray 
    //     if (arr[middle] > key) 
    //         return binSearch(arr, front, middle - 1, key); 
  
    //     // Else the element can only be present 
    //     // in right subarray 
    //     return binSearch(arr, middle + 1, back,key); 
    // } 
  
    // // We reach here when element is not 
    // // present in array 
    // return -1; 


    if(front>back)
        return -1;
    int middle = front + (back-front)/2;
    if(key==arr[middle])
        return middle;
    if(key>arr[middle])
        {
        return binSearch(arr,middle+1,back,key);
        }
    if(key<arr[middle])
        {
        return binSearch(arr,front,middle-1,key);
        }
    }
int main()
{
int arr[]={1,2,3,4,5,6,7};
int key;
cin>>key;
int size = sizeof(arr)/sizeof(arr[0]);
cout<<binSearch(arr,0,size-1,key)<<endl;
}