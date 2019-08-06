#include<iostream>
using namespace std;
bool checker(int * arr,int i,int n)
    {
    //base case
    if(i==(n-1))
        return true;
    //rec case
    if(arr[i]<arr[i-1])
        return false;
    checker(arr,i+1,n);
    }
int main()
{
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
    cin>>arr[i];
if(checker(arr,1,n))
cout<<"true"<<endl;
else
cout<<"false"<<endl;
}