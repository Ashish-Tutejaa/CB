#include<iostream>
#include<climits>
using namespace std;
long long int counter  =0 ;
long long int summer(long long int* arr,long long int n)
    {
    long long int i = 1;
    long long int sum = 0;
    for(long long int j = 0;j<n;j++)
        {
        sum+=i*arr[j];
        i++;
        }
    return sum;
    }
long long int recur(long long int* arr,long long int a,long long int size)
    {
    counter++;
    //base case
    if(a>=size)
        return summer(arr,size);
    //rec case
    long long int yesSwap,noSwap;
    yesSwap = noSwap = INT_MIN;
    if((a+1)<size)
        {
    swap(arr[a],arr[a+1]);
    yesSwap  = recur(arr,a+2,size);
    swap(arr[a],arr[a+1]); 
        }
    noSwap = recur(arr,a+1,size);
    return max(yesSwap,noSwap);
    }
int main()
{
long long int testCases;
cin>>testCases;
while(testCases--)
    {
    long long int n;
    cin>>n;
    long long int arr[n];
    for(long long int i = 0;i<n;i++)
        cin>>arr[i];
    cout<<recur(arr,0,n)<<endl;
    cout<<"COUNTER:"<<counter<<endl;
    }
}