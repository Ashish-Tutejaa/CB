#include<iostream>
using namespace std;
void spiral(int arr[][100],int size,int i,int j)
    {
    //base case
    if(i>=size or j>=size)
        return;
    //rec case
    for(int k = i;k<size;k++)
        {
        for(int h = j;h<size;h++)
            {
            cout<<arr[k][h]<<" ";
            }cout<<endl;
        }
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