#include<iostream>
using namespace std;
void spiral(int arr[][100],int size,int i,int j)
    {
    //base case
    if(i==j and i==size-1)

        {
        cout<<arr[i][j]<<endl;
        return;
        }
    if(i>=size or j>=size)
        return;
    //rec case
    for(int k = j;k<size;k++)
        {
        cout<<arr[0][k]<<" ";
        }cout<<endl;
    for(int k = j+1;k<size;k++)
        {
        cout<<arr[k][size-1]<<" ";
        }cout<<endl;
    for(int k = size-1;k>j;k--)
        {
        cout<<arr[size-1][k]<<" ";
        }cout<<endl;
    for(int k = size-1;k>j;k--)
        {
        cout<<arr[k][0]<<" ";
        }
    cout<<endl;
    return spiral(arr,size-1,i+1,j+1);
    }
int main()
{
int n;cin>>n;
int arr[100][100];
for(int i = 0;i<n;i++)
    {
    for(int j = 0;j<n;j++)
        {
        cin>>arr[i][j];
        }
    }
spiral(arr,n,0,0);
}