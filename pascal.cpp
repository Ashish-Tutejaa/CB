#include<iostream>
using namespace std;
int main()
{
int n;
cin>>n;
int arr[n][n+1];
arr[0][0] = 1;
arr[1][0] = 1;
arr[1][1] = 1;
for(int i = 2;i<n;i++)
    {
    for(int j = 0;j<(n+1);j++)
        {
        if(j==0 or j==n)
            {
            arr[i][j]=1;
            continue;
            }
        arr[i][j] = arr[i-1][j-1]+arr[i-1][j];
        }
    }
for(int i =0;i<n;i++)
    {
    for(int j =0;j<n;j++)
        cout<<arr[i][j]<<" ";cout<<endl;
    }
}